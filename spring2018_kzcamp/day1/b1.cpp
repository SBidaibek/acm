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

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll solve(int n, int m) {
    ll ans = 0;
    forn(g, 1, n) {
        int a = n / g, b = m / g;
        ll cur = 0;
        forn(i, 1, a)
            forn(j, 1, b)
                if (__gcd(i, j) == 1)
                    cur = (cur + pwr(i, g) * pwr(j, g)) % B;
        ans = (ans + cur * pwr(g, g)) % B;
    }
    return ans;
}

int n, m;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 1, 10) {
        forn(j, 1, 10) {
            cout << solve(i, j) << ", ";
        }
        cout << "\n";
    }
    //cin >> n >> m;
    //if (n > m) swap(n, m);
    //cout << solve(n, m) << "\n";

    return 0;
}
