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
const int B = 1e9 + 7;

int n, d;
int a[N], f[N], l[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        if (f[a[i]] == 0) f[a[i]] = i;
    }
    vi v;
    forn(i, 1, n)
        if (l[a[n - i + 1]] == 0) l[a[n - i + 1]] = i, v.pb(i);
    ll ans = 0;
    sort(v.begin(), v.end());
    //for (auto x : v) cerr <<x << "\n";cerr << "\n";
    forn(i, 1, 1e5) {
        if (!f[i] || f[i] + v[0] > n) continue;
        ans += upper_bound(v.begin(), v.end(), n - f[i]) - v.begin();
    }
    cout << ans << "\n";

    return 0;
}
