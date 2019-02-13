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
typedef vector <ll> vi;

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, q;
vector <pii> g[N * 2];
map <int, int> xcnt[N * 2];
int ans[N];

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
        x2i.pb(x);
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
        w.S = lower_bound(x2i.begin(), x2i.end(), w.S) - x2i.begin() + 1;
        q2i[w].pb(i + 1);
        ans[i + 1] = -1;
    }
    sort(Q.begin(), Q.end());

    int m = x2i.size();
    int ptr = 0;
    vi used(k + 1), ut(k + 1, -1);
    int dif = 0;
    forn(it, 1, t2i.size()) {
        for (; ptr < (int)Q.size() && Q[ptr].F < t2i[it - 1]; ++ptr) {
            if (dif < k) continue;
            int x = Q[ptr].S, lst = 0;
            int lptr = x - 1;
            forn(d, 0, m - x) {
                for (; lptr > 0 && x2i[x - 1] - x2i[lptr - 1] <= x2i[x + d - 1] - x2i[x - 1]; --lptr)
                    for (auto v : xcnt[lptr])
                        if (ut[v.F] != ptr) lst = x2i[x - 1] - x2i[lptr - 1], ut[v.F] = ptr;
                for (auto v : xcnt[x + d])
                    if (ut[v.F] != ptr) lst = x2i[x + d - 1] - x2i[x - 1], ut[v.F] = ptr;
            }
            for (; lptr > 0; --lptr)
                    for (auto v : xcnt[lptr])
                        if (ut[v.F] != ptr) lst = x2i[x - 1] - x2i[lptr - 1], ut[v.F] = ptr;
            for (auto id : q2i[Q[ptr]])
                ans[id] = lst;
        }
        for (auto p : g[it]) {
            if (p.S > 0) {
                if (!used[p.S]) ++dif;
                used[p.S]++;
                xcnt[p.F][p.S]++;
            }
            else {
                p.S = -p.S;
                if (used[p.S] == 1) --dif;
                used[p.S]--;
                if (xcnt[p.F][p.S] == 1)
                    xcnt[p.F].erase(p.S);
                else
                    xcnt[p.F][p.S]--;
            }
        }
    }
    forn(i, 1, q)
        cout << ans[i] << "\n";

    return 0;
}
