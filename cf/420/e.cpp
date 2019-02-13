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

ll n, k;
ll a[N], b[N], c[N];

const int C = 16;

vi mul(vi a, vi b) {
    vi res(C * C);
    forn(i, 0, C - 1)
        forn(j, 0, C - 1)
            forn(k, 0, C - 1)
                res[i * C + j] = (res[i * C + j] + a[i * C + k] * b[k * C + j]) % B;
    return res;
}

vi pwr(vi a, ll b) {
    vi res(C * C);
    forn(i, 0, C - 1)
        res[i * C + i] = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i] >> b[i] >> c[i];
    b[n] = k;
    if (a[n] == k) --n;
    vi v(C + 1);
    v[0] = 1;
    forn(it, 1, n) {
        vi t(C * C);
        forn(i, 0, c[it]) {
            t[i * C + i] = 1;
            if (i > 0) t[(i - 1) * C + i] = 1;
            if (i < c[it]) t[(i + 1) * C + i] = 1;
        }
        t = pwr(t, b[it] - a[it]);
        vi w(C);
        forn(i, 0, C - 1)
            forn(j, 0, C - 1)
                w[i] = (w[i] + v[j] * t[j * C + i]) % B;
        v = w;
        if (it < n && c[it + 1] < c[it])
            forn(i, c[it + 1] + 1, C - 1)
                v[i] = 0;
    }
    cout << v[0] << "\n";

    return 0;
}
