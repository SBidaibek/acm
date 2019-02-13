#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll f(ll n, ll m, ll i) {
    if (i == 0) i = m;
    return n / m + (n % m >= i);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll ans = 0;
    forn(i, 0, m - 1) {
        forn(j, 0, m - 1) {
            if ((i * i + j * j) % m != 0) continue;
            ans += f(n, m, i) * f(n, m, j);
        }
    }
    cout << ans << "\n";

    return 0;
}

