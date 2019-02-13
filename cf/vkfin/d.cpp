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
typedef vector <int> vi;

const int N = 3e5 + 3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int p[N];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int n, m;
vector <pii> g[N];
const int L = 20;
int up[N][L], d[N][L];
int dp[N], lvl[N];
map <pii, int> q[N];

void dfs(int x, int p = 0) {
    forn(i, 1, L - 1) {
        up[x][i] = up[up[x][i - 1]][i - 1];
        d[x][i] = max(d[x][i - 1], d[up[x][i - 1]][i - 1]);
    }
    for (auto to : g[x]) {
        if (to.F == p) continue;
        up[to.F][0] = x;
        d[to.F][0] = to.S;
        lvl[to.F] = lvl[x] + 1;
        dfs(to.F, x);
    }
    for (auto to : g[x]) {
        if (to.F == p) continue;
        if (q[x].size() < q[to.F].size()) q[x].swap(q[to.F]);
        for (auto y : q[to.F]) {
            if (q[x].count(y.F)) q[x].erase(y.F);
            else q[x][y.F]++;
        }
    }
    dp[x] = q[x].size() ? q[x].begin() -> F.F : -1;
}

int e[N][3];
int st[N];
int ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector <pii> v;
    forn(i, 1, m) {
        forn(j, 0, 2)
            cin >> e[i][j];
        v.pb({e[i][2], i});
    }
    sort(v.begin(), v.end());
    forn(i, 1, n) p[i] = i;
    for (auto qwe : v) {
        int i = qwe.S;
        int x = e[i][0], y = e[i][1];
        if (f(x) == f(y)) {
            st[i] = 0;
            q[x][{e[i][2], i}]++;
            q[y][{e[i][2], i}]++;
        }
        else {
            st[i] = 1;
            p[f(x)] = f(y);
            g[x].pb({y, e[i][2]});
            g[y].pb({x, e[i][2]});
        }
    }
    dfs(1);

    forn(i, 1, m) {
        int x = e[i][0], y = e[i][1];
        if (lvl[x] < lvl[y]) swap(x, y);
        if (st[i]) {
            if (dp[x] == -1) {
                ans[i] = -1;
            }
            else {
                ans[i] = dp[x] - 1;
            }
        }
        else {
            for1(j, L - 1, 0)
                if (lvl[up[x][j]] >= lvl[y]) {
                    ans[i] = max(ans[i], d[x][j]);
                    x = up[x][j];
                }
            if (x != y) {
                for1(j, L - 1, 0)
                    if (up[x][j] != up[y][j]) {
                        ans[i] = max(ans[i], d[x][j]);
                        x = up[x][j];
                        ans[i] = max(ans[i], d[y][j]);
                        y = up[y][j];
                    }
                ans[i] = max(ans[i], d[y][0]);
                ans[i] = max(ans[i], d[x][0]);
            }
            ans[i]--;
        }
    }
    forn(i, 1, m)
        cout << ans[i] << " ";

    return 0;
}
