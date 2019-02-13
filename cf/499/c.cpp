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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int g = 0;
    forn(i, 1, n) {
        cin >> a[i];
        a[i] %= k;
        g = __gcd(g, a[i]);
    }
    vector <bool> u(k);
    for (int x = 0; u[x] == 0; x = (x + g) % k) u[x] = 1;
    vi ans;
    forn(i, 0, k - 1)
        if (u[i]) ans.pb(i);
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
