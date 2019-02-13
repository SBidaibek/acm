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

const int N = 2.5e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int sz[N], d[N];
int c;

int dfs(int x, int p = -1) {
    int sz = 1;
    for (auto to : g[x])
        if (to != p) sz += dfs(to, x);
    if (c == 0 && sz * 2 >= n) c = x;
    return sz;
}

int dfssize(int x, int p = -1) {
    sz[x] = 0;
    for (auto to : g[x])
        if (to != p) {
            d[to] = d[x] + 1;
            sz[x] += dfssize(to, x);
        }
    return ++sz[x];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    cout << n - 1 << " ";
    dfs(1);
    ll ans = 0;
    dfssize(c);
    forn(j, 1, n)
        ans += d[j];
    vi w;
    if (g[c].size() > n / 2) {
        for (auto to : g[c])
            w.pb(sz[to]);
        sort(w.begin(), w.end(), greater <int> ());
        int a = 0, b = 0;
        for (auto x : w)
            if (a < b) a += x; else b += x;
        ans += 1ll * a * b;
    }
    else {
        ll mrg = 0;
        bitset <N> k;
        forn(i, c, c) {
            k.reset();
            k[0] = 1;
            for (auto to : g[i])
                k |= (k << sz[to]);
            forn(j, 0, n - 1)
                if (k[j])
                    mrg = max(mrg, 1ll * j * (n - 1 - j));
        }
        ans += mrg;
    }
    cout << ans << "\n";

    return 0;
}
