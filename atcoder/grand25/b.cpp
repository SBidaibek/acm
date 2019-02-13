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
const int B = 998244353;

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll f[N], rf[N];

ll c(ll n, ll k) {
    return f[n] * rf[n - k] % B * rf[k] % B;
}

ll gcd(ll &ka, ll a, ll &kb, ll b) {
    if (!b) {
        ka = 1, kb = 0;
        return a;
    }
    ll g = gcd(kb, b, ka, a % b);
    kb -= ka * (a / b);
    assert(ka * a + kb * b == g);
    return g;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1, rf[0] = 1;
    forn(i, 1, 3e5) {
        f[i] = f[i - 1] * i % B;
        rf[i] = pwr(f[i], B - 2);
    }

    ll n, a, b, k, ka, kb;
    cin >> n >> a >> b >> k;
    ll g = gcd(ka, a, kb, b);
    if (k % g != 0) {
        cout << "0\n";
        return 0;
    }
    ka *= k / g, kb *= k / g;
    ll l = a * b / g;
    ll qa = l / a, qb = l / b;
    if (ka < kb)
        swap(a, b), swap(ka, kb), swap(qa, qb);
    if (kb < 0) {
        ll d = (-kb + qb - 1) / qb;
        ka -= qa * d, kb += qb * d;
//        if (ka < 0) {
//            cout << "0\n";
//            return 0;
//        }
    }
    if (ka < kb)
        swap(a, b), swap(ka, kb), swap(qa, qb);
    if (ka > n) {
        ll d = ((ka - n) + qa - 1) / qa;
        ka -= qa * d, kb += qb * d;
//        if (ka < 0 || kb > n) {
//            cout << "0\n";
//            return 0;
//        }
    }
    if (ka < kb)
        swap(a, b), swap(ka, kb), swap(qa, qb);
    while (ka + qa <= n && kb - qb >= 0) ka += qa, kb -= qb;
    ll ans = 0;
    for (; 0 <= min(ka, kb) && max(ka, kb) <= n; ka -= qa, kb += qb)
        ans = (ans + c(n, ka) * c(n, kb)) % B;
    cout << ans << "\n";

    return 0;
}
