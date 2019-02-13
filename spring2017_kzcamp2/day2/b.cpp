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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

map <int, int> d[N];
int n;
int a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    d[1][a[1]] = 0;
    forn(j, -1, 1)
        if (j != a[1]) d[1][j] = INF;
    forn(i, 2, n) {
        forn(j, -1, 1)
            d[i][j] = INF;
        forn(j, -1, 1) {
            if (d[i - 1][j] == INF) continue;
            forn(k, j, 1) {
                if (a[i] == k)
                    d[i][k] = min(d[i][k], d[i - 1][j]);
                else {
                    if (j == 0) continue;
                    int x = (k - a[i]) / j;
                    if (x > 0) d[i][k] = min(d[i][k], d[i - 1][j] + x);
                }
            }
        }
    }
    int ans = INF;
    forn(i, -1, 1)
        ans = min(ans, d[n][i]);
    if (ans == INF)
        cout << "NU OK\n";
    else
        cout << ans << "\n";

    return 0;
}
