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

const int N = 2e4 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll f[N], rf[N], rev[N];

ll C(int n, int k) {
    return f[n] * rf[k] % B * rf[n - k] % B;
}

ll n, k;
vi p, a;
//ll P, Q;
ll ans;
ll d[N][100];
ll sav[100][100];

void rec(int it, ll num, ll prob) {
    if (it == p.size()) {
        //num = n / num;
        //cerr << num << ": 1/" << pwr(prob, B - 2) << "\n";
        ans = (ans + (num % B * prob % B)) % B;
        //cerr << num << " " << w << "\n";
        //P = (P + num % B * w) % B;
        //Q = (Q + w) % B;
        return;
    }
    d[0][a[it]] = 1;
    forn(c, 0, k) d[c][a[it] + 1] = 0;
    forn(i, 0, a[it] - 1) d[0][i] = 0;
    forn(c, 1, k) {
        for1(i, a[it], 0) {
            d[c][i] = (d[c][i + 1] + d[c - 1][i] * rev[i + 1]) % B;
        }
    }
    vi sav(a[it] + 1);
    forn(i, 0, a[it]) sav[i] = d[k][i];
    forn(i, 0, a[it]) {
    //    cerr << it << " -> " << ": " << num << " " << " 1/" << pwr(prob* d[k][i] % B, B - 2) << " | " << prob* d[k][i] % B << "\n";
        rec(it + 1, num, prob * sav[i] % B);
        num *= p[it];
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = rf[0] = 1;
    rev[0] = 1;
    forn(i, 1, N - 1)
        f[i] = f[i - 1] * i % B,
        rf[i] = pwr(f[i], B - 2),
        rev[i] = pwr(i, B - 2);

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

    //cerr << P << " " << Q << "\n";
    cout << ans << "\n";

    return 0;
}
