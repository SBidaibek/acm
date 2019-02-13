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

const int N = 2e4 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

int u[N], timer;

void dfs(int x) {
    u[x] = timer;
    for (auto to : g[x])
        dfs(to);
}

vector <pii> v;

int slow() {
    int ans = 0;
    forn(mask, 0, (1 << (n - 1)) - 1) {
        forn(i, 1, n) g[i].clear();
        forn(i, 0, n - 2)
            if (bit(mask, i))
                g[v[i].F].pb(v[i].S);
            else
                g[v[i].S].pb(v[i].F);
        int cur = -n;
        forn(i, 1, n) {
            ++timer;
            dfs(i);
            forn(j, 1, n)
                cur += (u[j] == timer);
        }
        ans = max(ans, cur);
    }
    return ans;
}

int sz[N], d[N];

int dfssize(int x, int p = -1) {
    sz[x] = 0;
    for (auto to : g[x])
        if (to != p) {
            d[to] = d[x] + 1;
            sz[x] += dfssize(to, x);
        }
    return ++sz[x];
}

int kek_slow() {
    for (auto e : v)
        g[e.F].pb(e.S), g[e.S].pb(e.F);
    int ans = 0;
    forn(i, 1, n) {
        d[i] = 0;
        dfssize(i);
        int mrg = 0, cur = 0;
        forn(j, 1, n)
            cur += d[j];
        bitset <N> k;
        k[0] = 1;
        for (auto to : g[i])
            k |= (k << sz[to]);
        forn(j, 0, n - 1)
            if (k[j])
                mrg = max(mrg, j * (n - 1 - j));/*
        forn(mask, 0, (1 << g[i].size()) - 1) {
            int a = 0, b = 0;
            forn(j, 0, g[i].size() - 1)
                if (bit(mask, j))
                    a += sz[g[i][j]];
                else
                    b += sz[g[i][j]];
            mrg = max(mrg, a * b);
            cerr << a << " " << b << ": " << a * b << "\n";
        }
        cerr << cur << "\n";*/
        ans = max(ans, mrg + cur);
    }
    return ans;
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
        v.pb({f, t});
    }/*
    forn(mask, 0, (1 << (n - 1)) - 1) {
        forn(i, 1, n) g[i].clear();
        forn(i, 0, n - 2)
            if (bit(mask, i))
                g[v[i].F].pb(v[i].S);
            else
                g[v[i].S].pb(v[i].F);
        int cur = -n;
        forn(i, 1, n) {
            ++timer;
            dfs(i);
            forn(j, 1, n)
                cur += (u[j] == timer);
        }
        if (cur == ans) {
            bitset <9> b(mask);
            cerr << b << "\n";
            forn(i, 1, n)
                for (auto to : g[i])
                    cerr << i << " " << to << "\n";
        }
    }*/
    int ans = kek_slow();
    cout << n - 1 << " " << ans << "\n";
    //cerr << kek_slow() << "\n";

    return 0;
}
