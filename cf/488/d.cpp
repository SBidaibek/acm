#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e2 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

ll n;
pii a[N];
ll d[N][N];

ll getmin(ll x) {
    forn(i, 1, n) d[0][i] = INF;
    int prv = 0;
    forn(i, 1, n) {
        if (a[i - 1].F != a[i].F) prv = i - 1;
        forn(j, 0, n) {
            d[i][j] = j + (i - prv) <= n ? d[prv][j + (i - prv)] : INF;
            if (j > 0)
                d[i][j] = min(d[i][j], d[i - 1][j - 1] + (a[i].F - x * a[i].S));
        }
    }
    ll ans = INF;
    forn(i, 0, n)
        ans = min(ans, d[n][i]);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].F;
    forn(i, 1, n)
        cin >> a[i].S;
    sort(a + 1, a + 1 + n, [](pii x, pii y) {
        x.F *= -1, y.F *= -1;
        return x < y;
    });
    forn(i, 1, n) {

    }
    forn(i, 1, n)
        a[i].F *= 1000;

    ll l = 1, r = 1e12;
    while (l < r) {
        ll x = (l + r + 1) / 2;
        if (getmin(x) >= 0) l = x;
        else r = x - 1;
    }
    cout << l + (getmin(l) > 0) << "\n";

    return 0;
}
