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

void dfsdown(int x, int p ) {
    down[x] = a[x];
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        dfsdown(to, x);
        if (down[to] >= e.S)
            down[x] = max(down[x], down[to] - e.S + a[x]);
    }
}

void rel(pll &p, ll x) {
    if (p.F <= x) {
        p.S = p.F;
        p.F = x;
    }
    else
        p.S = max(p.S, x);
}

void dfsup(int x, int p) {
    pll mx(-INF, -INF);
    up[x] = max(up[x], a[x]);
    rel(mx, up[x]);
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        if (down[to] >= e.S)
            rel(mx, down[to] - e.S + a[x]);
    }
    for (auto &e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        ll oth = 0;
        if (down[to] >= e.S)
            oth = (mx.F == down[to] - e.S + a[x] ? mx.S : mx.F);
        else
            oth = mx.F;
        if (oth >= e.S)
            up[to] = max(oth - e.S + a[to], a[to]);
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
    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
        //a[i] = rand() % i;
    forn(i, 1, n - 1) {
        int f, t, w;
        cin >> f >> t >> w;
        //f = rand() % i + 1;
        //t = i + 1;
        //w = rand();
        g[f].pb({t, w});
        g[t].pb({f, w});
    }

    dfsdown(1, -1);
    dfsup(1, -1);
    ll ans = 0;
    forn(i, 1, n)
        ans = max(ans, max(up[i], down[i]));
    cout << ans << "\n";

    return 0;
}
