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

const int N = 5e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
int d[N][N];

int solve(int n) {
    if (n % 2 == 0) {
        if (n / 2 % 2 == 0) {
            ll ans = 1;
            forn(i,  1, n / 2)
                ans = ans * 10 % B;
            return ans;
        }
        else {
            ll ans = 1;
            forn(i,  1, n / 2)
                ans = ans * 10 % B;
            return ans;
        }
    }
    else {
        if (n / 2 % 2 == 0) {
            ll ans = 0;
            forn(i, 0, n / 4 * 9)
                forn(k, 0, min(i, 4))
                    ans = (ans + 1ll * d[n / 4][i] * d[n / 4][i - k]) % B;
            return ans;
        }
        else {
            ll ans = 0;
            forn(i, 0, (n / 4 + 1) * 9)
                forn(k, 0, min(i, 4))
                    ans = (ans + 1ll * d[n / 4 + 1][i] * d[n / 4][i - k]) % B;
            return ans;
        }
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    d[0][0] = 1;
    forn(i, 1, 500) {
        forn(j, 0, 9 * i)
            forn(k, max(0, j - 9), j)
                d[i][j] = (d[i][j] + d[i - 1][k]) % B;
    }

    forn(i, 1, 100)
        cout << solve(i) << ", ";

    return 0;
}

