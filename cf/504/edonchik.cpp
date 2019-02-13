//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)5e5 + 228;
const int LOG = 21;

using namespace std;

int n, k, m, col[N], up[LOG][N], tin[N], tout[N], timer, rt[N], sz[N];
vector < int > g[N];

void dfs(int v, int pr)
{
    tin[v] = ++timer;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (pr == to)
            continue;
        col[to] = col[v];
        up[0][to] = v;
        dfs(to, v);
    }
    tout[v] = timer;
}

int get(int v)
{
    if (rt[v] == v)
        return v;
    return rt[v] = get(rt[v]);
}

bool merge(int v, int u)
{
    v = get(v), u = get(u);
    if (v == u)
        return false;
    if (sz[v] > sz[u])
    {
        sz[v] += sz[u];
        rt[u] = v;
    }
    else
    {
        sz[u] += sz[v];
        rt[v] = u;
    }
    return true;
}

bool upper(int v, int u)
{
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u)
{
    if (upper(v, u))
        return v;
    if (upper(u, v))
        return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (up[i][v] != -1 && !upper(up[i][v], u))
            v = up[i][v];
    return up[0][v];
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d%d%d", &n, &k, &m);
    forn(i, k)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u), g[u].pb(v);
    }
    //~calc_up
    memset(up, -1, sizeof(up));
    forn(i, n)
    {
        if (col[i])
            continue;
        col[i] = i;
        dfs(i, -1);
    }
    for (int i = 1; i < LOG; i++)
    {
        forn(j, n)
        {
            if (up[i - 1][j] != -1)
                up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    //~solve
    forn(i, n)
    {
        rt[i] = i, sz[i] = 1;
    }
    ll ans = 0;
    int cnt = 0;
    forn(i, m)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        if (get(v) == get(u))
            continue;
        if (col[v] != col[u])
        {
            //ans += w;
            merge(v, u);
            cnt++;
            continue;
        }
        int pr = lca(v, u);
        while(v != pr)
        {
            if (!merge(up[0][v], v))
                break;
            ans += w;
            cnt++;
            v = up[0][v];
        }
        while(u != pr)
        {
            if (!merge(up[0][u], u))
                break;
            ans += w;
            cnt++;
            u = up[0][u];
        }
    }
    if (cnt < n - 1)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;

	return 0;
}
