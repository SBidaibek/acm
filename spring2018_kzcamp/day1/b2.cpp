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

const int N = 1e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll pwr(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

ll d[N];
ll t[N];
vi v[N];
int n, m;
int bp[N];

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 0, 1000 - 1)
        bp[i] = __builtin_popcount(i);

    cin >> n >> m;
    if (n > m) swap(n, m);
    forn(i, 2, m) {
        int x = i;
        forn(j, 2, x) {
            if (j * j > x) break;
            if (x % j == 0) v[i].pb(j);
            while (x % j == 0) x /= j;
        }
        if (x > 1) v[i].pb(x);
    }
    ll ans = 0;
    forn(g, 1, n) {
        int a = n / g, b = m / g;
        ll sum = 0;
        forn(i, 1, b) {
            t[i] = pwr(i, g);
            sum = (sum + t[i]) % B;
        }
        ll cur = 0;
        forn(i, 1, a) {
            d[i] = 0;
            if (v[i].size() == 1) {
                for (int j = i; j <= b; j += i) {
                    d[i] += t[j];
                    if (d[i] > B) d[i] -= B;
                }
            }
            else {
                int sz = v[i].size();
                forn(mask, 0, (1 << (sz - 1))) {
                    ll x = 1;
                    forn(j, 0, sz - 1)
                        if (bit(mask, j)) x *= v[i][j];
                    if (bp[mask] & 1)
                        d[i] += d[x];
                    else
                        d[i] -= d[x];
                    if (d[i] >= B) d[i] -= B;
                    if (d[i] < 0) d[i] += B;
                }
            }
            cur = (cur + pwr(i, g) * (sum < d[i] ? sum - d[i] + B : sum - d[i])) % B;
        }
//            forn(j, 1, b)
//                if (__gcd(i, j) == 1)
//                    cur = (cur + pwr(i, g) * pwr(j, g)) % B;
        ans = (ans + cur * pwr(g, g)) % B;
    }
    cout << ans << "\n";

    return 0;
}
