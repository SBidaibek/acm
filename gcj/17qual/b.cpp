#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 500 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(_, 1, tests) {
        cout << "Case #" << _ << ": ";
        ll n;
        cin >> n;
        int len = 0;
        for (ll x = n; x; x /= 10) ++len;
        ll ans = 0, lst = 0;
        forn(i, 1, len) {
            for1(d, 9, lst) {
                ll x = ans;
                forn(j, 1, len - i + 1)
                    x = x * 10 + d;
                if (x <= n) {
                    ans = ans * 10 + d;
                    lst = d;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
