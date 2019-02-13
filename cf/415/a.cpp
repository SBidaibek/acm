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

ll n, a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vi v(10);
    delete(&v);
    return 0;

    cin >> n;
    ll ans = 0, s1 = 0, s2 = 0, pwr = 1;
    forn(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    forn(i, 1, n) {
        ans = (ans + a[i] * s1 - s2 + B) % B;
        s1 = (s1 * 2 + 1) % B;
        s2 = (s2 * 2 + a[i]) % B;
    }
    cout << ans << "\n";

    return 0;
}
