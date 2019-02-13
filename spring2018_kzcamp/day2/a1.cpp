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

const int N = 3e5 + 1;
const int K = 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];

int c[N];
int m[N][K + 5];

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];

    ll ans = 0;
    forn(i, 2, n) {
        int x = a[i - 1], y = a[i];
        if (x < y) swap(x, y);
        c[i] = x - y;
        forn(j, 0, K - 1)
            if (bit(x, j) != bit(y, j))
                m[i][j] = bit(x, j) ? -1 : +1;
    }
    int mn = INF, t = -1;
    forn(v, 0, (1 << K) - 1) {
        ll cur = 0;
        forn(i, 2, n) {
            ll x = c[i];
            for1(j, K - 1, 0)
                x += (1 << (j + 1)) * m[i][j] * bit(v, j);
            cur += abs(x) - abs(c[i]);
        }
        if (cur < mn)
            mn = cur, t = v;
    }
    ans = t;

    cout << ans << " ";
    forn(i, 1, n) a[i] ^= ans;
    ans = 0;
    forn(i, 2, n)
        ans += abs(a[i] - a[i - 1]);
    cout << ans << "\n";

    return 0;
}
