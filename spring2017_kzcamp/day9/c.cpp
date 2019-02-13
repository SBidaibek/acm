#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 500 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, k;
int a[N][N], d[N][N][4];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }

    forn(b, 1, 3) {
        forn(i, k, n) {
            forn(j, k, m) {
                d[i][j][b] = max(d[i][j - 1][b], d[i - 1][j][b]);
                d[i][j][b] = max(d[i][j][b],
                    a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j + k]
                    + max(d[i - k][j][b - 1], d[i][j - k][b - 1])
                );
            }
        }
    }
    cout << d[n][m][3] << "\n";

    return 0;
}
