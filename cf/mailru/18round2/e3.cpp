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

const int N = 3e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s, m, k;
int a[N], p[N];
int l[N], r[N];
vi q[N];
int d[N];
//int b[N];
int t[N];

inline void u(int x, int val) {
    for (x += n - 1; x >= 1; x >>= 1) t[x] = max(t[x], val);
}

int get(int l, int r) {
    int ans = -INF;
    if (l == 0) ans = 0, ++l;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, t[l++]);
        if (!(r & 1)) ans = max(ans, t[r--]);
    }
    return ans;
}

int getmaxbelow(int W) {
    forn(i, 1, n)
        p[i] = p[i - 1] + (a[i] <= W);
    memset(d, 0, sizeof d);
   // memset(b, 0, sizeof b);
    forn(i, 1, 2 * n) t[i] = -INF;
    forn(i, 1, n)
        u(i, -p[i]);
    forn(j, 1, m) {
        for1(i, n, 1) {
            int cur = -INF;
            for (auto prv : q[i])
                cur = max(cur, get(prv - 1, i - 1));
            d[i] = max(d[i], cur + p[i]);
        }
        forn(i, 1, n) {
            d[i] = max(d[i], d[i - 1]);
            u(i, d[i] - p[i]);
        }
    }
    return d[n];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m >> k;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, s) {
        cin >> l[i] >> r[i];
        q[r[i]].pb(l[i]);
    }

    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (getmaxbelow(m) >= k)
            r = m;
        else l = m + 1;
    }
    if (l > 1e9) l = -1;
    cout << l << "\n";

    return 0;
}

