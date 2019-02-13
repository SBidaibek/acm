#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <ll> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll f[N], rf[N];

ll C(int n, int k) {
    return f[n] * rf[k] % B * rf[n - k] % B;
}

ll n, k;
vi p, a;
ll P, Q;

void rec(int i, ll num, ll w) {
    if (i == p.size()) {
        num = n / num;
        cerr << num << " " << w << "\n";
        P = (P + num % B * w) % B;
        Q = (Q + w) % B;
        return;
    }
    forn(j, 0, a[i]) {
        rec(i + 1, num, w * C(j + k - 1, k - 1) % B);
        num *= p[i];
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = rf[0] = 1;
    forn(i, 1, N - 1)
        f[i] = f[i - 1] * i % B,
        rf[i] = pwr(f[i], B - 2);

    cin >> n >> k;

    vector <ll> div;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        div.pb(i);
        if (i * i != n) div.pb(n / i);
    }
    sort(div.begin(), div.end());
    ll x = n;
    for (auto i : div) {
        if (i == 1) continue;
        p.pb(i), a.pb(0);
        for (; x % i == 0; x /= i) ++a.back();
    }
    if (x > 1) p.pb(x), a.pb(1);

    rec(0, 1, 1);

    cerr << P << " " << Q << "\n";
    cout << (P * pwr(Q, B - 2) % B) << "\n";

    return 0;
}
