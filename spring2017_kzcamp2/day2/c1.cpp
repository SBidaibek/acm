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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int sz[N];
int d[N][N], u[N}[N];

void dfs(int x, int p = -1) {
    if (p > 0) g[x].erase(g[x].find(p));
    sz[x] = 1;
    g[x].pb(x);
    u[g[x][0]][1] = 0;
    forn(_i, 0, g[x].size() - 2) {
        int to = g[x][_i], nxt = g[x][_i + 1];
        dfs(to, x);
        forn(i, 1, sz[x]) {
            forn(j, 1, sz[to]) {
                u[nxt][i + j] = max(u[nxt][i + j], u[to][i] + d[to][j] + j);
                u[nxt][i] = max(u[nxt][i], u[to][i] + d[to][j] + i * j);
                u[nxt][j] = max(u[nxt][j], u[to][i] + d[to][j] + i * j);
                u[nxt][1] = max(u[nxt][1], )
            }
        }
        sz[x] += sz[to];
    }
    forn(i, 1, sz[x]) {
        d[x][i] = u[x][i];
        u[x][i] = 0;
    }
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
    cout << n - 1 << " ";
    dfs(1);
    ll ans = 0;
    forn(i, 1, n)
        ans = max(ans, d[1][i]);
    cout << ans << "\n";

    return 0;
}
