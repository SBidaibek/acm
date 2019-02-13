#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 6e4 + 100;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, q, m;
vector <pii> g[N * 2];
unordered_map <int, int> xcnt[N * 2];
set <int> kcur[N];
int ans[N];

typedef struct node* node_ptr;

struct node {
    int x, y;
    int cnt, sz;
    node_ptr l, r;
    node() {
        y = rand();
        l = r = 0;
        cnt = sz = 1;
    }
} nds[N * 6 * 20];
int n_sz;

node_ptr new_node(int x) {
    nds[n_sz].x = x;
    return &nds[n_sz++];
}

int gsz(node_ptr t) {
    return t ? t -> sz : 0;
}

void recalc(node_ptr t) {
    if (!t) return;
    t -> sz = gsz(t -> l) + t -> cnt + gsz(t -> r);
}

void Merge(node_ptr &w, node_ptr left, node_ptr right) {
    if (!left || !right) {
        w = left ? left : right;
        return;
    }
    if (left -> y > right -> y)
        Merge(left -> r, left -> r, right), w = left;
    else
        Merge(right -> l, left, right -> l), w = right;
    recalc(w);
}

void Split(node_ptr w, node_ptr &left, node_ptr &right, int sep) {
    if (!w) {
        left = right = 0;
        return;
    }
    if (w -> x <= sep)
        Split(w -> r, w -> r, right, sep), left = w;
    else
        Split(w -> l, left, w -> l, sep), right = w;
    recalc(w);
}

void out(node_ptr t) {
    if (!t) return;
    out(t -> l);
    cerr << t -> x << " ";
    out(t -> r);
}

node_ptr t[N * 2];

void Insert(int x, int val) {
    for (; x <= m; x |= (x + 1)) {
        node_ptr L = 0, R = 0, M = 0;
        Split(t[x], L, R, val - 1);
        Split(R, M, R, val);
        if (M == 0) M = new_node(val);
        else ++(M -> cnt), ++(M -> sz);
        Merge(R, M, R);
        Merge(t[x], L, R);
    }
}

void Erase(int x, int val) {
    for (; x <= m; x |= (x + 1)) {
        node_ptr L = 0, R = 0, M = 0;
        Split(t[x], L, R, val - 1);
        Split(R, M, R, val);
        assert(M != 0);
        if ((M -> cnt) == 1) M = 0;
        else --(M -> cnt), --(M -> sz);
        Merge(R, M, R);
        Merge(t[x], L, R);
    }
}

int Get2(int x, int v) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) {
        node_ptr L = 0, R = 0;
        Split(t[x], L, R, v - 1);
        ans += gsz(R);
        Merge(t[x], L, R);
    }
    return ans;
}

int Get(int l, int r) {
    return Get2(r - 1, r) - Get2(l - 1, r);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> q;
    vi x2i, t2i;
    vector <vi> tmp;
    forn(i, 1, n) {
        int x, tp, a, b;
        cin >> x >> tp >> a >> b;
        tmp.pb({x, tp, a, ++b});
        x2i.pb(x);
        t2i.pb(a);
        t2i.pb(b);
    }
    vector <pii> Q;
    forn(i, 1, q) {
        int x, t;
        cin >> x >> t;
        Q.pb({t, x});
    }
    sort(x2i.begin(), x2i.end());
    x2i.resize(unique(x2i.begin(), x2i.end()) - x2i.begin());
    sort(t2i.begin(), t2i.end());
    t2i.resize(unique(t2i.begin(), t2i.end()) - t2i.begin());

    for (auto w : tmp) {
        int x, tp, a, b;
        x = lower_bound(x2i.begin(), x2i.end(), w[0]) - x2i.begin() + 1;
        tp = w[1];
        a = lower_bound(t2i.begin(), t2i.end(), w[2]) - t2i.begin() + 1;
        b = lower_bound(t2i.begin(), t2i.end(), w[3]) - t2i.begin() + 1;
        g[a].pb({x, tp});
        g[b].pb({x, -tp});
    }
    tmp.clear();
    map <pii, vi> q2i;
    forn(i, 0, q - 1) {
        pii &w = Q[i];
        q2i[w].pb(i + 1);
        ans[i + 1] = -1;
    }
    sort(Q.begin(), Q.end());
    m = x2i.size();
    int mx = x2i.back();
    int mxk = mx;
    forn(i, 1, k)
        kcur[i].insert(0), kcur[i].insert(m + 1);
    forn(i, 0, q - 1)
        mxk = max(mxk, (int)Q[i].S);

    int ptr = 0;
    vi used(k + 1);
    int dif = 0;
    forn(it, 1, t2i.size()) {
        for (; ptr < (int)Q.size() && Q[ptr].F < t2i[it - 1]; ++ptr) {
            if (dif < k) continue;
            int x = Q[ptr].S;
            int l = 0, r = 2 * mxk;
            while (l < r) {
                int mid = (l + r) / 2;
                int pl = lower_bound(x2i.begin(), x2i.end(), x - mid) - x2i.begin() + 1;
                int pr = upper_bound(x2i.begin(), x2i.end(), x + mid) - x2i.begin() + 1;
                if (Get(pl, pr) < dif) l = mid + 1;
                else r = mid;
            }
            for (auto id : q2i[Q[ptr]])
                ans[id] = l;
        }
        for (auto p : g[it]) {
            if (p.S > 0) {
                if (!used[p.S]) ++dif;
                used[p.S]++;
                if (!xcnt[p.F].count(p.S)) {
                    auto iter = kcur[p.S].upper_bound(p.F);
                    int nx = *iter; --iter; int pr = *iter;
                    if (pr != 0) Erase(pr, nx);
                    if (pr != 0) Insert(pr, p.F);
                    Insert(p.F, nx);
                    xcnt[p.F][p.S] = 1;
                    kcur[p.S].insert(p.F);
                }
                else
                    xcnt[p.F][p.S]++;
            }
            else {
                p.S = -p.S;
                if (used[p.S] == 1) --dif;
                used[p.S]--;
                if (xcnt[p.F][p.S] == 1) {
                    kcur[p.S].erase(p.F);
                    auto iter = kcur[p.S].upper_bound(p.F);
                    int nx = *iter; --iter; int pr = *iter;
                    if (pr != 0) Insert(pr, nx);
                    if (pr != 0) Erase(pr, p.F);
                    Erase(p.F, nx);
                    xcnt[p.F].erase(p.S);
                }
                else
                    xcnt[p.F][p.S]--;
            }
        }
        //cerr << it << " : " << dif << "\n";
    }
    forn(i, 1, q)
        cout << ans[i] << "\n";

    return 0;
}
