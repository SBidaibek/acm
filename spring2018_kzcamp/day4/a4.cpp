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
typedef vector <int> vi;

const int N = 350 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

typedef vector <vi> mat;

int k;
mat tmp;

mat mul(const mat &a, const mat &b) {
    forn(i, 0, k)
        forn(j, 0, k)
            tmp[i][j] = 0;
    forn(z, 0, k)
        forn(j, 0, k)
            forn(i, 0, k)
                tmp[i][j] = (tmp[i][j] + 1ll * a[i][z] * b[z][j]) % B;
    return tmp;
}

mat q, m;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> k >> a >> b;
    m.resize(k + 1), q.resize(k + 1), tmp.resize(k + 1);
    forn(i, 0, k)
        m[i].resize(k + 1), q[i].resize(k + 1), tmp[i].resize(k + 1);
    forn(j, 0, k) {
        if (j < k)
            m[j][j + 1] = a, m[j][0] = b;
        else
            m[k][k] = a + b;
    }

    forn(i, 0, k)
        q[i][i] = 1;
    for (; n; n >>= 1, m = mul(m, m))
        if (n & 1) q = mul(m, q);

    cout << q[0][k] << "\n";

    return 0;
}
