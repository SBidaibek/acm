#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;



int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = 1e18;
    forn(i, 1, n - 1) {
        ll x = 0;
        for (ll a = i, b = n - i; a || b; a /= 10, b /= 10)
            x += a % 10 + b % 10;
        ans = min(ans, x);
    }
    cout << ans << "\n";

    return 0;
}
