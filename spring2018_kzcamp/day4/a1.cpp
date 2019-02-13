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

const int N = 3e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll c[N][N];

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll p(ll z) {
    return z % 2 == 0 ? -1 : +1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 0, N - 1) {
        c[i][0] = 1;
        forn(j, 1, i)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % B;
    }

    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll ans = 0;
    forn(x, k, n) {///x = danges
        ll cur = 0;
        forn(y, 1,  min(x - k + 1, n - x + 1)) {///y = total dang segments
            ll s = 1;
            if (x < n) {
                s = c[n - x - 1][y];
                if (y >= 1) s += 2 * c[n - x - 1][y - 1];
                if (y >= 2) s += c[n - x - 1][y - 2];
                s %= B;
            }
            forn(z, 1, min(1ll * y, x / k))///z = dang segments with len >= k
                cur = (cur + B + p(z) * c[y][z] * c[x - z * (k - 1) - 1][y - 1] % B * s % B) % B;
        }
        ans = (ans + cur * pwr(a, x) % B * pwr(b, n - x)) % B;
    }

    cout << ans << "\n";

    return 0;
}
