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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
int a[N][3];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        vi v(3);
        forn(j, 0, 2)
            cin >> v[j];
        sort(v.begin(), v.end());
        a[i][0] = v[0];
        a[i][1] = v[1];
        a[i][2] = v[2];
    }

    ll ans = 0;
    forn(i, 1, n) {
        vi v(3);
        forn(j, i, n) {
            forn(k, 0, 2)
                v[k] = max(v[k],(ll)a[j][k]);
            ans = (ans + 1ll * v[0] * v[1] % B * v[2]) % B;
        }
    }
    ll x = 1ll * n * (n + 1) / 2;
    forn(i, 0, 30) {
        if ((B - 2) & (1 << i))
            ans = ans * x % B;
        x = x * x % B;
    }
    cout << ans << "\n";

    return 0;
}
