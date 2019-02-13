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

int n, k;
int a[5][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, k)
        forn(j, 1, n)
            cin >> a[i][j];
    n = (n % 2 == 1 ? 1 : 2);
    if (n == 1) {
        n = k;
        unordered_map <int, int> t;
        ll ans = 0;
        for1(i, n, 1) {
            for (int x = a[1][i] - 1; x >= 0; x = (x & (x + 1)) - 1)
                ans += t[x];
            for (int x = a[1][i]; x <= 1e9; x |= x + 1)
                ++t[x];
        }
        cout << ans << "\n";
    }

    return 0;
}
