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

int n;
int d[2][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        ll ans = 1;
        forn(i, 1, n / 2)
            ans = ans * 10 % B;
        cout << ans << "\n";
    }
    else {
        forn(i, 0, N - 1) d[0][i] = 1;
        forn(i, 1, n / 4 + 1) {
            forn(j, 0, 9 * i)
                d[i & 1][j] = (d[(i & 1) ^ 1][j] - (j <= 9 ? 0 : d[(i & 1) ^ 1][j - 10]) + B) % B;
            forn(j, 1, 9 * (i + 1))
                d[i & 1][j] = (d[i & 1][j - 1] + (j <= 9 * i ? d[i & 1][j] : 0)) % B;
        }
        forn(i, 0, 1)
            for1(j, N - 1, 1)
                d[i][j] = (d[i][j] >= d[i][j - 1] ? 0 : B) + d[i][j] - d[i][j - 1];
        if (n / 2 % 2 == 0) {
            ll ans = 0;
            forn(i, 0, n / 4 * 9)
                forn(k, 0, min(i, 4))
                    ans = (ans + 1ll * d[(n / 4) & 1][i] * d[(n / 4) & 1][i - k]) % B;
            cout << ans << "\n";
        }
        else {
            ll ans = 0;
            forn(i, 0, (n / 4 + 1) * 9)
                forn(k, 0, min(i, 4))
                    ans = (ans + 1ll * d[(n / 4 + 1) & 1][i] * d[(n / 4) & 1][i - k]) % B;
            cout << ans << "\n";
        }
    }

    return 0;
}
