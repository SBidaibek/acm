#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 700 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int tmp[N][N];
ll k;

void mul(int a[][N], int b[][N], int c[][N]) {
    forn(i, 0, k + k + 1)
        forn(j, 0, k + k + 1) {
            tmp[i][j] = 0;
            forn(z, 0, k + k + 1)
                tmp[i][j] = (tmp[i][j] + 1ll * a[i][z] * b[z][j]) % B;
        }
    forn(i, 0, k + k + 1)
        forn(j, 0, k + k + 1)
            c[i][j] = tmp[i][j];
}

int q[N][N], m[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> k >> a >> b;
    forn(j, 0, k) {
        forn(t, 0, 1) {
            m[j + t * (k + 1)][min(k, 1ll * j + 1) + (t || j + 1 == k) * (k + 1)] = a;
            m[j + t * (k + 1)][0 + t * (k + 1)] = b;
        }
    }

    forn(i, 0, k + k + 1)
        q[i][i] = 1;
    for (; n; n >>= 1, mul(m, m, m))
        if (n & 1) mul(q, m, q);

    ll ans = 0;
    forn(i, k + 1, k + k + 1)
        ans = (ans + q[0][i]) % B;
    cout << ans << "\n";

    return 0;
}
