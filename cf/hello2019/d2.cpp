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

ll n, k;
vi p, a;
//ll P, Q;
ll rev[N];
ll ans;
ll d[N][100];
ll sav[100][100];

void rec(int it, ll num, ll prob) {
    if (it == p.size()) {
        //cerr << num << ": 1/" << pwr(prob, B - 2) << "\n";
        ans = (ans + (num % B * prob % B)) % B;
        return;
    }
    forn(i, 0, a[it]) {
        //cerr << it << ": " << i << " " << a[it] << " " << i << " " << sav[a[it]][i] << "\n";
        rec(it + 1, num, prob * sav[a[it]][i] % B);
        num *= p[it];
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    rev[0] = 1;
    forn(i, 1, N - 1)
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
        if (x % i != 0) continue;
        p.pb(i), a.pb(0);
        for (; x % i == 0; x /= i) ++a.back();
    }
    if (x > 1) p.pb(x), a.pb(1);
    vi used(100);
    for (auto i : a) used[i] = 1;

    forn(m, 1, 99) {
        if (!used[m]) continue;
        d[0][m] = 1;
        forn(c, 0, k) d[c][m + 1] = 0;
        forn(i, 0, m - 1) d[0][i] = 0;
        forn(c, 1, k) {
            for1(i, m, 0) {
                d[c][i] = (d[c][i + 1] + d[c - 1][i] * rev[i + 1]) % B;
            }
        }
        forn(i, 0, m)
            sav[m][i] = d[k][i];
        //cerr << sav[m][0] << " " << sav[m][1] << "\n";
    }

    rec(0, 1, 1);

    //cerr << P << " " << Q << "\n";
    cout << ans << "\n";

    return 0;
}
