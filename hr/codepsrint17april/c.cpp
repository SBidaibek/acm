
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

const int N = 2e6 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

ll bp(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) ans = ans * a % B;
    return ans;
}

int n, k;
ll a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    ll ans = 0;
    for1(b, 59, 0) {
        ll x = (ans | (1ll << b)), c = 0;
        forn(i, 1, n)
            if ((x & a[i]) == x) ++c;
        if (c >= k)
            ans |= (1ll << b);
    }
    cout << ans << "\n";
    int x = 0, y = k;
    forn(i, 1, n)
        if ((ans & a[i]) == ans) ++x;
    ans = 1;
    forn(i, 1, y) ans = (ans * i) % B;
    ans = bp(ans, B - 2);
    forn(i, x - y + 1, x)
        ans = (ans * i) % B;
    cout << ans << "\n";

    return 0;
}
