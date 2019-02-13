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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, k;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("balls.in", "r", stdin);
    freopen("balls.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    ll ans = 0;
    forn(m, 1, (1 << n) - 1) {
        vi a;
        forn(i, 0, n - 1)
            if (m & (1 << i))
                a.pb(i + 1);
        if (a.size() != k) continue;
        ll cur = 1;
        forn(i, 1, k)
            cur = (cur * (2 * a[i - 1] - i)) % B;
        ans = (ans + cur) % B;
    }
    d[0] = 1, c[0] = 1;
    forn(i, 1, n) {
        for1(j, i, 1)
            d[j] = (d[j] + d[j - 1] * (2 * i - j)) % B;
        for1(j, i, 1)
            c[j] = (c[j] + c[j - 1]) % B;
        forn(j, 1, i) {
            assert(d[j] % c[j] == 0);
            cout << "(" << d[j] << " " << c[j] << " " << d[j] / c[j] << ") ";
        }
        cout << "\n";
    }
    cout << d[k] << "\n";
    cout << ans << "\n";

    return 0;
}
