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

const int N = 5e4 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
vector <pii> g[N];

const int L = 18;
int lvl[N];
int p[N][L], s[N][L];
int sz, tin[N], tout[N];

void dfs(int x) {
    forn(i, 1, L - 1) {
        p[x][i] = p[p[x][i - 1]][i - 1];
        s[x][i] = s[x][i - 1] + s[p[x][i - 1]][i - 1];
    }
    tin[x] = ++sz;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p[x][0]) continue;
        p[to][0] = x, s[to][0] = e.S;
        lvl[to] = lvl[x] + 1;
        dfs(to);
    }
    tout[x] = ++sz;
}

bool isa(int a, int b) {
    return tin[a] <= tin[b] && tin[b] <= tout[a];
}

int lca(int a, int b) {
    if (isa(a, b)) return a;
    for1(i, L - 1, 0)
        if (!isa(p[a][i], b)) a = p[a][i];
    return p[a][0];
}

int d(int x, int l) {
    int ans = 0;
    for1(i, L - 1, 0)
        if (lvl[p[x][i]] >= l) {
            ans += s[x][i];
            x = p[x][i];
        }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t, w;
        cin >> f >> t >> w;
        ++f, ++t;
        g[f].pb({t, w});
        g[t].pb({f, w});
    }
    p[1][0] = 1;
    dfs(1);

    ll q, ans = 0;
    cin >> q;
    forn(it, 1, q) {
        vi v(6);
        forn(i, 1, 5) {
            cin >> v[i];
            ++v[i];
        }
        sort(v.begin() + 1, v.end(), [](int x, int y) {
            return tin[x] < tin[y];
        });
        int l = lca(v[1], v[2]);
        ans += d(v[1], lvl[l]) + d(v[2], lvl[l]);
        forn(i, 3, 5) {
            int x = lca(v[i - 1], v[i]);
            ans += d(v[i], lvl[x]);
            if (lvl[x] < lvl[l]) {
                ans += d(l, lvl[x]);
                l = x;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
