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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 998244353;

ll d[20][2][2][(1 << 10)];
ll c[20][2][2][(1 << 10)];
bool u[20][2][2][(1 << 10)];

ll f(ll n, ll k) {
    if (!n) return 0;
    vi v;
    for (ll x = n; x; x /= 10) v.pb(x % 10);
    reverse(v.begin(), v.end());
    memset(u, 0, sizeof u);
    memset(d, 0, sizeof d);
    memset(c, 0, sizeof c);
    u[0][1][0][0] = 1;
    c[0][1][0][0] = 1;
    //cerr << v[0] << " " << v[1] << "\n";
    forn(i, 0, v.size() - 1) {
        forn(eq, 0, 1) {
            forn(pos, 0, 1) {
                forn(mask, 0, (1 << 10) - 1) {
                    if (!u[i][eq][pos][mask]) continue;
                    forn(dig, 0, eq ? v[i] : 9) {
                        bool neq = eq & (dig == v[i]);
                        int npo = pos || (dig);
                        int nmask = mask | (1 << dig);
                        if (!npo) nmask = 0;
                        //cerr << i << ": " << eq << " " << mask << " -> " << neq << " " << nmask << "\n";
                        u[i + 1][neq][npo][nmask] = 1;
                        c[i + 1][neq][npo][nmask] = (c[i + 1][neq][npo][nmask] + c[i][eq][pos][mask]) % B;
                        d[i + 1][neq][npo][nmask] = (d[i + 1][neq][npo][nmask]
                                    + d[i][eq][pos][mask] * 10 + c[i][eq][pos][mask] * dig) % B;
                    }
                }
            }
        }
    }
    ll ans = 0;
    forn(mask, 0, (1 << 10) - 1)
        if (__builtin_popcount(mask) <= k) {//cerr << v.size() << " " << mask << "\n";
            ans = (ans + d[v.size()][0][1][mask] + d[v.size()][1][1][mask]) % B;}
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cerr << f(10, 1) << "\n";
    //return 0;

    ll l, r, k;
    cin >> l >> r >> k;
    cout << (f(r, k) - f(l - 1, k) + B) % B << "\n";

    return 0;
}

