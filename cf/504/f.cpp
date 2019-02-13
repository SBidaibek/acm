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

const int N = 6e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int p[N];
int fp(int x) {
    return p[x] == x ? x : p[x] = fp(p[x]);
}
int n, k, m;
vi g[N];
int pr[N][20], lvl[N];

void build(int x) {
    forn(i, 1, 19)
        pr[x][i] = pr[pr[x][i - 1]][i - 1];
    for (auto to : g[x]) {
        if (to == pr[x][0]) continue;
        pr[to][0] = x;
        lvl[to] = lvl[x] + 1;
        build(to);
    }
}

int lca(int a, int b) {
    if (lvl[a] < lvl[b]) swap(a, b);
    for1(i, 19, 0)
        if (lvl[pr[a][i]] >= lvl[b]) a = pr[a][i];
    if (a == b) return a;
    for1(i, 19, 0)
        if (pr[a][i] != pr[b][i]) a = pr[a][i], b = pr[b][i];
    return pr[a][0];
}

ll ans = 0;
vector <pii> q[N];
vi del[N];
multiset <int> st[N];

void merg(int a, int b) {
    if (st[a].size() < st[b].size()) swap(st[a], st[b]);
    for (auto x : st[b]) st[a].insert(x);
    st[b].clear();
}

void count(int x) {
    for (auto to : g[x]) {
        if (pr[x][0] == to) continue;
        count(to);
        if (!st[to].size()) {
            cout << "-1\n";
            exit(0);
        }
        ans += *st[to].begin();
        merg(x, to);
    }
    for (auto pa : q[x]) {
        del[pa.F].pb(pa.S);
        st[x].insert(pa.S);
    }
    for (auto y : del[x])
        st[x].erase(st[x].find(y));
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    forn(i, 1, n) p[i] = i;
    forn(i, 1, k) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
        p[fp(f)] = fp(t);
    }
    forn(i, 1, n) {
        if (!g[i].size() || fp(i) != i) continue;
        pr[i][0] = i;
        build(i);
    }
    forn(i, 1, m) {
        int f, t, w;
        cin >> f >> t >> w;
        if (fp(f) != fp(t)) continue;
        int l = lca(f, t);
        q[f].pb({l, w});
        q[t].pb({l, w});
    }
    forn(i, 1, n) {
        if (!g[i].size() || fp(i) != i) continue;
        count(i);
    }
    cout << ans << "\n";

    return 0;
}
