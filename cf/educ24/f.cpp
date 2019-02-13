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

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    forn(i, 1, q) {
        int n;
        cin >> n;
        ll l = 2, r = n;
        if (n <= 5) {
            cout << n - 1 << "\n";
            continue;
        }
        --n;
        while (l < r) {
            ll m = (l + r + 1) / 2;
            if (m + m * (m + 1) / 2 <= n) l = m;
            else r = m - 1;
        }
        ll ans = l * (l + 1);
        n -= l + l * (l + 1) / 2;
        if (n > 1)
            ans += 2 + (n - 2) * 2;
        else
            ans += n;
        cout << ans << "\n";
    }

    return 0;
}
