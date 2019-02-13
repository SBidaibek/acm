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
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1);
    vi b;
    ll ans = 0;
    forn(i, 1, n) {
        cin >> a[i];
        if (i > 1)
            b.pb(a[i] - a[i - 1] - 1);
    }
    ans = a[n] - a[1] + 1;
    sort(b.begin(), b.end(), greater <int> ());
    forn(i, 0, k - 2)
        ans -= b[i];
    cout << ans << "\n";
/*
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid, n, a)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
*/
    return 0;
}
