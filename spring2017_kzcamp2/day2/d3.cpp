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

const int N = 1e4 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, k;
vi g[N * 2];
int pr[N * 2], u[N * 2], bad[N * 2];
int ans[N * 2];

bool dfs(int x) {
    if (u[x]) return 0;
    u[x] = 1;
    for (auto to : g[x])
        if (pr[to] == -1) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    for (auto to : g[x])
        if (dfs(pr[to])) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    return 0;
}

void clear(int x) {
    if (u[x]) return;
    u[x] = 1;
    ans[x] = 0;
    for (auto to : g[x])
        if (pr[to] != -1 && pr[to] != x)
            clear(pr[to]);
    return;
}

vi G[N * 2], RG[N * 2];
vi o;
int c[N * 2];

void ts(int x) {
    if (u[x]) return;
    u[x] = 1;
    for (auto to : G[x]) ts(to);
    o.pb(x);
}

void rd(int x) {
    for (auto to : RG[x]) {
        if (c[to]) continue;
        c[to] = c[x];
        rd(to);
    }
}

void down(int x) {
    if (u[x] || !bad[x]) return;
    u[x] = 1;
    for (auto to : G[x]) {
        if (c[to] == c[x]) continue;
        bad[c[to]] = 1;
        down(to);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, k) {
        int f, t;
        cin >> f >> t;
        g[f].pb(n + t);
        g[n + t].pb(f);
    }
    forn(i, 1, n + m) pr[i] = -1, ans[i] = 1;
    forn(i, 1, n) {
        if (pr[i] == -1) {
            memset(u, 0, sizeof u);
            bool x = 0;
            forn(j, 1, n)
                if (pr[j] == -1) x |= dfs(j);
            if (!x) break;
        }
    }

    forn(i, 1, n + m)
        if (pr[i] == -1) ans[i] = 0;
    forn(i, 1, n)
        if (pr[i] != -1)
        for (auto to : g[i])
            if (pr[to] != i && pr[to] != -1)
                G[i].pb(pr[to]), RG[pr[to]].pb(i);
    o.clear();
    memset(u, 0, sizeof u);
    forn(i, 1, n)
        if (!u[i]) ts(i);
    reverse(o.begin(), o.end());
    //for (auto x : o) cerr << x << " ";cerr << "\n";
    for (auto x : o)
        if (!c[x]) {
            c[x] = x;
            rd(x);
        }
    forn(i, n + 1, n + m)
        if (pr[i] != -1)
            for (auto to : g[i])
                if (pr[to] == -1)
                    bad[c[pr[i]]] = 1;
    memset(u, 0, sizeof u);
    for (auto x : o)
        if (!u[x]) down(x);
    forn(i, 1, n)
        if (bad[c[i]]) ans[i] = 0;

    forn(i, n + 1, n + m)
        if (pr[i] != -1)
        for (auto to : g[i])
            if (pr[to] != i && pr[to] != -1)
                G[i].pb(pr[to]), RG[pr[to]].pb(i);
    o.clear();
    memset(u, 0, sizeof u);
    forn(i, n + 1, n + m)
        if (!u[i]) ts(i);
    reverse(o.begin(), o.end());
    for (auto x : o)
        if (!c[x]) {
            c[x] = x;
            rd(x);
        }
    forn(i, 1, n)
        if (pr[i] != -1)
            for (auto to : g[i])
                if (pr[to] == -1)
                    bad[c[pr[i]]] = 1;
    memset(u, 0, sizeof u);
    for (auto x : o)
        if (!u[x]) down(x);
    forn(i, n + 1, n + m)
        if (bad[c[i]]) ans[i] = 0;
    //forn(i, 1, n + m)
    //    cerr << i << " " << c[i] << " " << bad[c[i]] << "\n";

    int a = 0, b = 0;
    forn(i, 1, n)
        if (ans[i]) ++a;
    forn(i, n + 1, n + m)
        if (ans[i]) ++b;
    cout << a << "\n";
    forn(i, 1, n)
        if (ans[i]) cout << i << " ";
    cout << "\n" << b << "\n";
    forn(i, n + 1, n + m)
        if (ans[i]) cout << i - n << " ";

    return 0;
}
