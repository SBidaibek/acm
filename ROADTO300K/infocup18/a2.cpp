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

int n, m;
ll a[N][N], d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];

    ll ans = -1;

    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            d[i][j] = -2 * INF;
    forn(i, 1, n) {
        forn(j, 1, m) {
            d[i][j] = max(max(d[i - 1][j], d[i][j - 1]), -a[i][j] + i + j);
            ans = max(ans, a[i][j] - i - j + d[i][j] - 1);
        }
    }

    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            d[i][j] = -2 * INF;
    forn(i, 1, n) {
        for1(j, m, 1) {
            d[i][j] = max(max(d[i - 1][j], d[i][j + 1]), -a[i][j] + i - j);
            ans = max(ans, a[i][j] - i + j + d[i][j] - 1);
        }
    }

    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            d[i][j] = -2 * INF;
    for1(i, n, 1) {
        forn(j, 1, m) {
            d[i][j] = max(max(d[i + 1][j], d[i][j - 1]), -a[i][j] - i + j);
            ans = max(ans, a[i][j] + i - j + d[i][j] - 1);
        }
    }

    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            d[i][j] = -2 * INF;
    for1(i, n, 1) {
        for1(j, m, 1) {
            d[i][j] = max(max(d[i + 1][j], d[i][j + 1]), -a[i][j] - i - j);
            ans = max(ans, a[i][j] + i + j + d[i][j] - 1);
        }
    }

    cout << ans << "\n";

    return 0;
}
