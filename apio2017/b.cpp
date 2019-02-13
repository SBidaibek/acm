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
typedef vector <ll> vi;

const int N = 2e2 + 2;
const int K = 2e3 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, k;
ll b[N][K], s[N][K];
ll dist[N][N], trade[N][N], f[N][N], e[N][N];

int u[N];

void dfs(int x) {
    if (u[x]) return;
    u[x] = 1;
    forn(i, 1, n)
        if (!u[i] && e[x][i])
            dfs(i);
}

ll F(int rat) {
    forn(i, 1, n)
        forn(j, 1, n)
            //if (i != j)
                dist[i][j] = (e[i][j] ? -e[i][j] * rat : -INF);
            //else
            //    dist[i][j] = 0;
    forn(k, 1, n)
        forn(i, 1, n)
            forn(j, 1, n)
                if (dist[i][k] != -INF && dist[k][j] != -INF)
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
    forn(i, 1, n)
        forn(j, 1, n)
            if (dist[i][j] != -INF)
                f[i][j] = trade[i][j] + dist[i][j];
            else
                f[i][j] = -INF;
    forn(k, 1, n)
        forn(i, 1, n)
            forn(j, 1, n)
                if (f[i][k] != -INF && f[k][j] != -INF)
                    //if (k != i && k != j)
                        f[i][j] = max(f[i][j], f[i][k] + f[k][j]);
    forn(i, 1, n)
        forn(j, 1, n)
            cerr << i << " " << j << ": " << f[i][j] << "\n";
    //ll ans = -1;
    forn(i, 1, n) {
        if (f[i][i] > 0) return 1;
        if (f[i][i] == 0) return 0;
        //ans = max(ans, f[i][i]);
    }
    return -1;
            //if (u[i]) {cerr << i << " ";
            // cerr << i << " " << f[1][i] << " " << f[i][1] << " " << trade[1][i] << " " << dist[1][i] << "\n";
            //forn(j, 1, n)
            //    if (i != j)
            //        ans = max(ans, f[i][j] + dist[j][i]);}
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, n)
        forn(j, 1, k)
            cin >> b[i][j] >> s[i][j];
    forn(i, 1, m) {
        int f, t, w;
        cin >> f >> t >> w;
        e[f][t] = w;
    }
    dfs(1);
    forn(i, 1, n)
        forn(j, 1, n)
            forn(x, 1, k)
                if (b[i][x] != -1 && s[j][x] != -1 && b[i][x] < s[j][x])
                    trade[i][j] = max(trade[i][j], s[j][x] - b[i][x]);
    cerr << F(40) << "\n";
    return 0;
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (F(mid) >= 0) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";

    return 0;
}
