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
const int K = 30;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];
ll dp[N];
int prv[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];

    ll ans = 0;
    forn(b, 0, K - 1) {
        int lst = 0;
        forn(i, 1, n) {
            if (lst && dp[lst] + (a[i] & a[lst]) > dp[prv[i]] + (a[i] & a[prv[i]]))
                prv[i] = lst;
            dp[i] = max(dp[i], dp[prv[i]] + (a[i] & a[prv[i]]));
            ans = max(ans, dp[i]);
            if ((a[i] & (1 << b))) lst = i;
        }
    }
    cout << ans << "\n";

    return 0;
}

