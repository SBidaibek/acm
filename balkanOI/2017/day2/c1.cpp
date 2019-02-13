#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 3e5 + 3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int a[N], p[N];
pii d[N];

void dfs(int x, int pr = -1) {
    d[x] = {a[x], -x};
    for (auto to : g[x]) {
        if (to == pr) continue;
        dfs(to, x);
        d[x] = max(d[x], pii(d[to].F - 1, d[to].S));
    }
}

pii v[N], sx[N], gift[N];
int sz;

void up(int x, int pr) {
    int sz = 0;
    v[++sz] = {a[x], -x};
    if (pr > 0) {
        pii &c = gift[x];
        c.F--;
        v[++sz] = c;
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        v[++sz] = {d[to].F - 1, d[to].S};
    }
    sx[sz + 1] = {-INF, -INF};
    for1(i, sz, 1) sx[i] = max(sx[i + 1], v[i]);
    pii px = v[1];
    int cnt = 2;
    if (pr > 0) px = max(px, v[2]), ++cnt;
    for (auto to : g[x]) {
        if (to == pr) continue;
        gift[to] = max(px, sx[cnt + 1]);
        px = max(px, v[cnt++]);
    }
    p[x] = -(sx[2].S);
    for (auto to : g[x]) {
        if (to == pr) continue;
        up(to, x);
    }
}

int u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    dfs(1);
    up(1, -1);

    forn(i, 1, n) u[i] = -1;
    int x = 1, c = 0;
    for (; u[x] == -1; x = p[x]) {
        if (c == k) {
            cout << x << "\n";
            return 0;
        }
        u[x] = c++;
    }
    k -= c;
    for (k %= (c - u[x]); k; --k) x = p[x];
    cout << x << "\n";

    return 0;
}
