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

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
ll a[N];

ll cost(ll x) {
    ll ans = 0;
    forn(i, 1, n)
        ans += x - a[i];
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (cost(a[n]) <= k) {
        ll l = a[n], r = 2e9;
        while (l < r) {
            ll m = (l + r + 1) / 2;
            if (cost(m) <= k) l = m;
            else r = m - 1;
        }
        cout << l << "\n";
        return 0;
    }

    ll ans = 1;
    ll d = 1;
    while (d < a[n]) {
        ll cur = 0, nxt = INF, sum = 0;
        forn(i, 1, n)
            cur += (d - a[i] % d) % d;
        ll len = 0;
        forn(i, 0, n) {
            ++len;
            if (i < n && ((a[i] - 1) / d) == (a[i + 1] - 1) / d) continue;
            ll c = 1 + ((a[i] - 1) / d);
            if (i < n) nxt = min(nxt, (a[i + 1] % d) / c);
            sum += len * c;
            len = 0;
        }
        //    cerr << d << " " << sum << " "<< nxt << "\n";
        if (cur <= k) {
        //cerr <<  "^ ok\n";
            ans = max(ans, d + min(k / sum, nxt));
            //ans = max(ans, d);
        }
        d += nxt + 1;
    }
    cout << ans << "\n";

    return 0;
}
