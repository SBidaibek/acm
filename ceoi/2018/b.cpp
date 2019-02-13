#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, a[N], q[N];
int t[N];

#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

int g(int ql, int qr, int x, int tl, int tr) {
    if (qr <= tl || tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t[x];
    int m = (tl + tr) / 2;
    return max(
        g(ql, qr, left(x), tl, m),
        g(ql, qr, right(x), m, tr)
    );
}

void u(int qx, int delta, int x, int tl, int tr) {
    t[x] = max(t[x], delta);
    if (tl == tr - 1) return;
    int m = (tl + tr) / 2;
    if (qx < m)
        u(qx, delta, left(x), tl, m);
    else
        u(qx, delta, right(x), m, tr);
}

int sav[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vi v;
    forn(i, 1, n) {
        cin >> a[i];
        v.pb(a[i]);
        v.pb(a[i] + k);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 1, n) {
        q[i] = lower_bound(v.begin(), v.end(), a[i] + k) - v.begin() + 1;
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }

    forn(i, 1, n) {
        sav[i] = g(1, q[i], 1, 1, v.size() + 1);
        int d = g(1, a[i], 1, 1, v.size() + 1) + 1;
        u(a[i], d, 1, 1, v.size() + 1);
    }
    memset(t, 0, sizeof t);
    int ans = 0;
    for1(i, n, 1) {
        int d = g(a[i] + 1, v.size() + 1, 1, 1, v.size() + 1) + 1;
        u(a[i], d, 1, 1, v.size() + 1);
        ans = max(ans, d + sav[i]);
    }
    cout << ans << "\n";

    return 0;
}
