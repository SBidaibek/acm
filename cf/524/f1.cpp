#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 1e6 + 10;
const int INF = 1e9 + 9;

int zip(int x, vi &v) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

typedef struct node* node_ptr;

struct node {
    int mn;
    node_ptr l, r;
    node() {
        mn = INF;
        l = r = 0;
    }
} nds[N * 30];

int sz;

int g(node_ptr t) {
    return t ? t -> mn : INF;
}

void recalc(node_ptr t) {
    if (t) t -> mn = min(g(t -> l), g(t -> r));
}

node_ptr new_node(int x) {
    nds[sz].mn = x;
    return &nds[sz++];
}

node_ptr new_node(node_ptr l, node_ptr r) {
    nds[sz].l = l, nds[sz].r = r;
    recalc(&nds[sz]);
    return &nds[sz++];
}

vector <pii> a[N], up[N];
vector <vi> Q[N];

node_ptr upd(int qx, int v, node_ptr x, int tl, int tr) {
    if (qx < tl || tr <= qx) return x;
    if (tl == tr - 1)
        return new_node(v);
    int m = (tl + tr) / 2;
    return new_node(
        upd(qx, v, x -> l, tl, m),
        upd(qx, v, x -> r, m, tr)
    );
}

int get(int ql, int qr, node_ptr x, int tl, int tr) {
    if (qr <= tl || tr <= ql) return INF;
    if (ql <= tl && tr <= qr) return g(x);
    int m = (tl + tr) / 2;
    return min(
        get(ql, qr, x -> l, tl, m),
        get(ql, qr, x -> r, m, tr)
    );
}

node_ptr build(int tl, int tr) {
    if (tl == tr - 1)
        return new_node(-1);
    int m = (tl + tr) / 2;
    return new_node(
        build(tl, m),
        build(m, tr)
    );
}

node_ptr roots[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    forn(i, 1, k) {
        int l, r, p;
        cin >> l >> r >> p;
        a[p].pb({l, r});
    }
    vi v;
    forn(i, 1, n) {
        sort(a[i].begin(), a[i].end());
        vector <pii> cl;
        for (auto p : a[i]) {
            while (cl.size() && p.S <= cl.back().S)
                cl.pop_back();
            cl.pb(p);
        }
        a[i] = cl;
        for (auto p : a[i])
            v.pb(p.F), v.pb(p.S);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 1, n)
        for (auto &p : a[i]) {
            p.F = zip(p.F, v), p.S = zip(p.S, v);
            up[p.S].pb({i, p.F});
        }
    roots[0] = build(1, n + 1);
    forn(it, 1, v.size()) {
        roots[it] = roots[it - 1];
        for (auto u : up[it])
            roots[it] = upd(u.F, u.S, roots[it], 1, n + 1);
    }

    //for (auto x : v) cerr << x << " ";cerr << "\n";
    forn(i, 1, m) {
        int l, r, vl, vr;
        cin >> l >> r >> vl >> vr;
        if (vr < v[0]) {
            cout << "no" << endl;
            continue;
        }
        //cerr <<  vl << " " << vr << "\n";
        vr = upper_bound(v.begin(), v.end(), vr) - v.begin() - 1 + 1;
        //cerr << vr << "\n";
        int mn = get(l, r + 1, roots[vr], 1, n + 1);
        if (mn <= 0 || v[mn - 1] < vl)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    return 0;
}
