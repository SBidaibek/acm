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

const int N = 2e3 + 10;//3e5 + 10;
const ll INF = 1e18;
const int B = 998244353;

ll p[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 0, N - 1) {
        p[i][0] = 1;
        forn(j, 1, i)
            p[i][j] = (p[i - 1][j - 1] + p[i - 1][j]) % B;
    }

    int n, m, k;
    cin >> n >> m >> k;
    ll ans = m;
    forn(i, 1, k)
        ans = ans * (m - 1) % B;
    ans = ans * p[n - 1][k] % B;
    cout << ans << "\n";

    return 0;
}
