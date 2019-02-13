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

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, q, a[N], g[N], p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    forn(i, 1, n - 1)
        cin >> a[i];
    forn(i, 1, n)
        cin >> g[i] >> p[i];
    forn(it, 1, q) {
        int f, t;
        cin >> f >> t;
        ll ans = 0, tank = 0, mn = p[f];
        forn(i, f, t - 1) {
            tank += g[i];
            mn = min(mn, p[i]);
            if (tank >= a[i])
                tank -= a[i];
            else {
                ans += mn * (a[i] - tank);
                tank = 0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
