#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e2 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
ll d[N], p[N], c[N], dg[N];
vi g[N], v[N];

void dfs(int x) {
    for (auto to : g[x])
        if (to != p[x])
            {d[to] = d[x] + 1; p[to] = x; dfs(to);}
}

void dcount(int x, int p, int lvl) {
    dg[x] = 0;
    v[lvl].pb(x);
    for (auto to : g[x])
        if (to != p)
            {dcount(to, x, lvl + 1); ++dg[x];}
}

ll sav[N][N];

ll solveforv(int x, int y) {
    if (x > y) swap(x, y);
    if (sav[x][y]) return sav[x][y];
    forn(i, 0, n - 1) v[i].clear();
    dcount(x, y, 0);
    if (x != y) dcount(y, x, 0);
    ll ans = 0;
    for1(i, n - 1, 0) {
        if (!v[i].size()) continue;
        if (!v[i + 1].size()) {
            ans = v[i].size();
            c[i] = 1;
            continue;
        }
        ll mx = 0;
        for (auto q : v[i])
            mx = max(mx, dg[q]);
        for (auto q : v[i])
            ans += (mx - dg[q]) * c[i + 1];
        c[i] = mx * c[i + 1];
    }
    return sav[x][y] = ans;
}

ll solve(int x, int y) {
    bool ok = (x == 1 && y == 7);
    int len = d[y];
    forn(i, 1, len / 2) y = p[y];
    ll ans = 0;
    if (len % 2 == 0) {
        ans = solveforv(y, y);
        for (auto to : g[y])
            ans = min(ans, solveforv(y, to));
    }
    else
        ans = solveforv(y, p[y]);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    pii ans = {INF, INF};
    int diam = 0;
    forn(i, 1, n) {
        d[i] = 0, p[i] = 0;
        dfs(i);
        forn(j, i + 1, n) {
            if (d[j] < diam) continue;
            if (d[j] == diam) {
                ans.S = min(ans.S, solve(i, j));
            }
            if (d[j] > diam) {
                diam = d[j];
                ans = {diam / 2 + 1, solve(i, j)};
            }
        }
    }

    cout << ans.F << " " << ans.S << "\n";

    return 0;
}
