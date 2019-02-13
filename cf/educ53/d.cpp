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
const int B = 1e9 + 7;

ll n, f[N];

ll get(int x) {
    ll ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) ans += f[x];
    return ans;
}

void upd(int x, ll val) {
    for (; x <= n; x |= x + 1) f[x] += val;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t, sum = 0;
    cin >> n >> t;
    int mn = INF;
    vi a(n + 1);
    forn(i, 1, n) {
        cin >> a[i];
        sum += a[i];
        upd(i, +a[i]);
        mn = min(mn, a[i]);
    }
    ll ans = 0;
    ll s = sum, c = n;
    while (t >= mn) {
        ans += (t / s) * c;
        t %= s;
        while (get(n) > t) {
            int l = 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (get(m) <= t) l = m + 1;
                else r = m;
            }
            s -= a[l], --c;
            upd(l, -a[l]);
        }
    }
    cout << ans << "\n";

    return 0;
}

