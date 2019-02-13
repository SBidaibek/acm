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

int n, m;
int a[N][N], o[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            o[i][j] = a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    int ans = -1e9;
    forn(i, 1, n) {
        forn(j, 1, m) {
            int prv = o[i][j];
            int l = min(min(i - 1, n - i), min(j - 1, m - j));
            forn(k, 1, l) {
                int x = a[i + k][j + k] - a[i + k][j - k - 1] - a[i - k - 1][j + k] + a[i - k - 1][j - k - 1];
                x -= prv + o[i - k + 1][j - k];
                ans = max(ans, x);
                prv = x;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
