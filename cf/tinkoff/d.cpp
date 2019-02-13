#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 80 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, K, m;
vector <pii> g[N];
int d[N][N][N][2];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;
    cin >> m;
    forn(i, 1, m) {
        int f, t, w;
        cin >> f >> t >> w;
        g[f].pb({t, w});
    }
    if (K == 1) {
        cout << "0\n";
        return 0;
    }
    if (K > n) {
        cout << "-1\n";
        return 0;
    }

    memset(d, -1, sizeof d);
    forn(i, 1, n)
        d[1][i][i][0] = d[1][i][i][1] = 0;
    forn(len, 2, n) {
        forn(k, 2, min(K, len)) {
            forn(l, 1, n - len + 1) {
                int r = l + len - 1;
                forn(v, 0, 1) {
                    d[k][l][r][v] = INF;
                    if (d[k][l + 1][r][v] != -1 && !v) d[k][l][r][v] = min(d[k][l][r][v], d[k][l + 1][r][v]);
                    if (d[k][l][r - 1][v] != -1 && v) d[k][l][r][v] = min(d[k][l][r][v], d[k][l][r - 1][v]);
                    int x = v ? l : r;
                    for (auto e : g[x]) {
                        int to = e.f, w = e.s;
                        if (to < l || r < to || x == to) continue;
                        //cerr << k << " " << l << " " << r << " " << v << " " << x << "\n";
                        int T = d[k - 1][v ? to : l][v ? r : to][v];
                        //cerr << k << " " << l << " " << r << " " << v << " " << x << ": " << T << " " << to << "\n";
                        if (T != -1)
                            d[k][l][r][v] = min(d[k][l][r][v], T + w);
                        T = d[k - 1][v ? l + 1 : to][v ? to : r - 1][v ^ 1];
                        //cerr << k << " " << l << " " << r << " " << v << " " << x << ": " << T << " " << to << "\n";
                        if (T != -1)
                            d[k][l][r][v] = min(d[k][l][r][v], T + w);
                    }
                        //cerr << k << " " << l << " " << r << " " << v << " " << x << ": " << d[k][l][r][v] << "\n-\n";
                }
            }
        }
    }

    int ans = INF;
    forn(i, 1, n) {
        if (d[K][1][i][0] != -1)
            ans = min(ans, d[K][1][i][0]);
        if (d[K][i][n][1] != -1)
            ans = min(ans, d[K][i][n][1]);
    }
    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
