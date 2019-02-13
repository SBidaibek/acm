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

const int N = 2e6 + 1;
const int K = 8;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];
ll d[(1 << K)][(1 << K)], dp[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    if (n <= 2000) {
        ll ans = 0;
        forn(i, 1, n)
            forn(j, 1, i - 1) {
                dp[i] = max(dp[i], dp[j] + (a[i] & a[j]));
                ans = max(ans, dp[i]);
            }
        cout << ans << "\n";
        return 0;
    }

    forn(i, 0, (1 << K) - 1)
        forn(j, 0, (1 << K) - 1)
            d[i][j] = -1e18;

    ll ans = 0;
    forn(i, 1, n) {
        int m2 = (a[i] >> K);
        int m1 = (a[i] ^ (m2 << K));
        forn(mask, 0, (1 << K) - 1)
            dp[i] = max(dp[i], d[m1][mask] + ((mask & m2) << K));
        ans = max(ans, dp[i]);
        forn(mask, 0, (1 << K) - 1)
            d[mask][m2] = max(d[mask][m2], dp[i] + (mask & m1));
    }
    cout << ans << "\n";

    return 0;
}
