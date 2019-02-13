#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vector <pii> g[N];
ll a[N], up[N], down[N];

void dfsdown(ll s, int x, int p = -1) {
    down[x] = s - a[x];
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        dfsdown(s, to, x);
        down[x] = min(down[x], down[to] + e.S - a[x]);
    }
}

void rel(pll &p, ll x) {
    if (p.F >= x) {
        p.S = p.F;
        p.F = x;
    }
    else
        p.S = min(p.S, x);
}

void dfsup(ll s, int x, int p = -1) {
    pll mn(1e18, 1e18);
    up[x] = min(up[x], s - a[x]);
    rel(mn, up[x]);
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        rel(mn, down[to] + e.S - a[x]);
    }
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        ll oth = (mn.F == down[to] + e.S - a[x] ? mn.S : mn.F);
        up[to] = min(oth + e.S - a[to], s - a[to]);
        dfsup(s, to, x);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n - 1) {
        int f, t, w;
        cin >> f >> t >> w;
        g[f].pb({t, w});
        g[t].pb({f, w});
    }

    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        forn(i, 1, n)
            down[i] = up[i] = 1e18;
        dfsdown(m, 1);
        dfsup(m, 1);
        bool ok = 0;
        forn(i, 1, n)
            if (min(up[i], down[i]) <= 0) ok = 1;
        if (ok) l = m;
        else r = m - 1;
    }
    cout << l << "\n";

    return 0;
}
