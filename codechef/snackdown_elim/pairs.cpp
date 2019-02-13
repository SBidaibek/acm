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

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll a[N], b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    forn(_, 1, t) {
        int n, m, k;
        cin >> n >> m >> k;
        forn(i, 1, n)
            cin >> a[i];
        forn(j, 1, m)
            cin >> b[j];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        int ans = 0;
        forn(p1, 1, n) {
            forn(p2, 1, m) {
                int s = b[p2] - k - a[p1], p = 1, cur = 0;
                forn(i, 1, n) {
                    while (p <= m && a[i] + s - k > b[p]) ++p;
                    if (p > m) break;
                    if (a[i] + s + k >= b[p])
                        ++cur, ++p;
                }
                ans = max(ans, cur);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
