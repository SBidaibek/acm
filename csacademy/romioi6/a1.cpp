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

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int L = 21;

int n, m;
vi g[N];
int lvl[N];
int pr[N][L], dist[N][L], mxd[N];
ll up[N];
vi sum[N], qsb[N];

int fc(int x, int p, int &center, int k) {
    int sz = 1;
    for (auto to : g[x])
        if (lvl[to] == -1 && to != p)
            sz += fc(to, x, center, k);
    if (center == 0 && sz * 2 >= k)
        center = x;
    return sz;
}

void dfs(int x, int p, int c, int dep, int len) {
    pr[x][dep] = c;
    dist[x][dep] = len;
    mxd[c] = max(mxd[c], len);
    for (auto to : g[x])
        if (lvl[to] == -1 && to != p)
            dfs(to, x, c, dep, len + 1);
}

int cd(int x, int sz, int dep) {
    int cen = 0;
    fc(x, -1, cen, sz);
    if (cen) x = cen;
    lvl[x] = dep;
    dfs(x, -1, x, dep, 0);
    sum[x].resize(mxd[x] + 1);
    for (auto to : g[x])
        if (lvl[to] == -1) {
            to = cd(to, sz / 2, dep + 1);
            qsb[to].resize(mxd[x] + 1);
        }
    return x;
}

ll ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 2, n) {
        int p;
        cin >> p;
        g[p].pb(i);
        g[i].pb(p);
    }
    forn(i, 1, n) lvl[i] = -1;
    cd(1, n, 0);
    forn(it, 1, m) {
        int v, rad;
        cin >> v >> rad;
        for1(i, lvl[v], 0) {
            int c = pr[v][i], cprev = pr[v][i + 1];
            if (dist[v][i] > rad) continue;
            int x = rad - dist[v][i];
            if (x > mxd[c]) {
                up[c] += x - mxd[c];
                if (c != v)
                    up[cprev] -= x - mxd[c];
                x = mxd[c];
            }
            ++sum[c][x];
            if (c != v)
                ++qsb[cprev][x];
        }
    }
    forn(i, 1, n) {
        int cnt = sum[i].back();
        sum[i].back() = 0;
        for1(j, sum[i].size() - 2, 0) {
            int sav = sum[i][j];
            sum[i][j] = sum[i][j + 1] + cnt;
            cnt += sav;
        }
        if (!qsb[i].size()) continue;
        cnt = qsb[i].back();
        qsb[i].back() = 0;
        for1(j, qsb[i].size() - 2, 0) {
            int sav = qsb[i][j];
            qsb[i][j] = qsb[i][j + 1] + cnt;
            cnt += sav;
        }
    }

    forn(i, 1, n) {
        for1(j, lvl[i], 0) {
            int c = pr[i][j];
            ans[i] += up[c] + sum[c][dist[i][j]];
            if (j < lvl[i]) {
                int cprev = pr[i][j + 1];
                ans[i] -= qsb[cprev][dist[i][j]];
            }
        }
        cout << ans[i] << "\n";
    }

    return 0;
}
