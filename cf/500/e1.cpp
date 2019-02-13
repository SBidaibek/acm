#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e3 + 10;
const int INF = 1e9 + 9;
//const int B = 1e9 + 7;
int B;

void rlx(ll &a, ll b) {
    a = (a + b) % B;
}

int n, k, m;
ll d[N][N], p[N][N], c[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> B;
    cerr << n << " " << k << "\n";

    forn(i, 0, n + n)
        forn(j, 0, i)
            c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % B : 1;

    d[1][0] = 1;
    forn(i, 1, n + 1) {
        forn(j, 0, k) {
            p[i][j] = ((j ? p[i][j - 1] : 0) + d[i][j]) % B;
            if (!d[i][j] || i > n) continue;
            cerr << i << " " << j << ": " << d[i][j] << "\n";
            forn(nj, j + 1, k)
                rlx(d[i + 1][nj], d[i][j]);
            forn(ni, 1, i - 1) {
                forn(nj, 0, k - 1) {
                    if (!d[ni][nj]) continue;
                    forn(add, 1, k - nj) {
                        ll cur = d[i][j] * d[ni][nj] % B;
                        cur = cur * c[i + ni - 1][ni];
                        rlx(d[ni + i][max(j, nj + add)], cur);
                    }
                }
            }
        }
    }

    ll ans = p[n + 1][k];
    cout << ans << "\n";

    return 0;
}
