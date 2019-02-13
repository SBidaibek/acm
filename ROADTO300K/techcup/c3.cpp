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

int n, m, p[N], d1[N], d2[N];

int f[N];

int g(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) ans = max(ans, f[x]);
    return ans;
}

int u(int x, int v) {
    for (; x <= n; x |= x + 1) f[x] = max(f[x], v);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) {
        int f, t;
        cin >> f >> t;
        ++p[f], --p[t + 1];
    }
    forn(i, 1, m)
        p[i] += p[i - 1];
    forn(i, 0, n) f[i] = 0;
    forn(i, 1, m) {
        d1[i] = g(p[i]) + 1;
        u(p[i], d1[i]);
    }
    forn(i, 0, n) f[i] = 0;
    int ans = 0;
    for1(i, m, 1) {
        d2[i] = g(p[i]) + 1;
        u(p[i], d2[i]);
        ans = max(ans, d1[i] + d2[i] - 1);
    }
    cout << ans << "\n";

    return 0;
}
