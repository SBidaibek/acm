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
const ll INF = 1e18;
const int B = 1e9 + 7;

vector <pii> g[N];
ll a[N], up[N], down[N];
ll s;

void dfsdown(int x, int p ) {
    //down[x] = s - a[x];
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        dfsdown(to, x);
        //down[x] = min(down[x], down[to] + e.S - a[x]);
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

void dfsup(int x, int p) {
    pll mn(INF, INF);
    up[x] = min(up[x], s - a[x]);
    rel(mn, up[x]);
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        rel(mn, down[to] + e.S - a[x]);
    }
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        ll oth = (mn.F == down[to] + e.S - a[x] ? mn.S : mn.F);
        up[to] = min(oth + e.S - a[to], s - a[to]);
        dfsup(to, x);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n = 3e5;
    //cin >> n;
    forn(i, 1, n)
        //cin >> a[i];
        a[i] = rand() % i;
    forn(i, 1, n - 1) {
        int f, t, w;
        //cin >> f >> t >> w;
        f = rand() % i + 1;
        t = i + 1;
        w = rand();
        g[f].pb({t, w});
        g[t].pb({f, w});
    }

    ll l = 0, r = 1e18;
    while (l < r) {
        cerr << l << " " << r << "\n";
        ll m = (l + r + 1) / 2;
        forn(i, 1, n)
            down[i] = up[i] = INF;
        cerr << l << " " << r << "\n";
        s = m;
        //dfsdown(1, -1);
        cerr << l << " " << r << "\n";
        //dfsup(1, -1);
        cerr << l << " " << r << "\n";
        bool ok = 0;
        forn(i, 1, n)
            if (min(up[i], down[i]) <= 0) ok = 1;
        if (ok) l = m;
        else r = m - 1;
    }
    cout << l << "\n";

    return 0;
}
