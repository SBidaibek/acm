#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <int> vi;

const int N = (1 << 24);
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

int n;
vi g[100];

int sz(int x, int p) {
    int ans = 1;
    for (auto to : g[x]) {
        if (to == p) continue;
        ans += sz(to, x);
    }
    return ans;
}

ld d[N];
ld ans[100];
ld f[100];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    forn(i, 1, 99)
        f[i] = f[i - 1] / ld(i);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    vector <pii> v;
    forn(i, 1, n) v.pb({g[i].size(), i});
    sort(v.begin(), v.end());
    ld rest = 1;
    for (auto _p : v) {
        int x = _p.second;
        if (_p == v.back()) {
            ans[x] = rest;
            break;
        }
        vi a;
        for (auto to : g[x])
            a.pb(sz(to, x));
        int deg = g[x].size();
        cerr << x << ": " << deg  << "\n";
        d[0] = 1;
        forn(mask, 1, (1 << deg) - 1) {
            d[mask] = 0;
            int _n = 1;
            forn(i, 0, deg - 1)
                if (bit(mask, i)) _n += a[i];
            forn(i, 0, deg - 1)
                if (bit(mask, i)) {
                    //ld cur = (a[i] / ld(_n - 1)) * d[a[i] - 1];
                    d[mask] += d[mask ^ (1 << i)] * 0.5 * f[_n - 2];
                }
        }
        ans[x] = d[(1 << deg) - 1];
        rest -= ans[x];
    }

    cout << fixed << setprecision(20);
    forn(i, 1, n)
        cout << ans[i] << "\n";

    return 0;
}

