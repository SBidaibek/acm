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

const int N = 1e4 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, k;
vi g[N * 2];
int pr[N * 2], u[N * 2], bad[N * 2];
int ans[N * 2];

bool dfs(int x) {
    if (u[x]) return 0;
    u[x] = 1;
    for (auto to : g[x])
        if (pr[to] == -1) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    for (auto to : g[x])
        if (dfs(pr[to])) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    return 0;
}

void clear(int x) {
    if (u[x]) return;
    u[x] = 1;
    ans[x] = 0;
    for (auto to : g[x])
        if (pr[to] != -1 && pr[to] != x)
            clear(pr[to]);
    return;
}

int p[N * 2];

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

vi G[N], RG[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, k) {
        int f, t;
        cin >> f >> t;
        g[f].pb(n + t);
        g[n + t].pb(f);
    }
    forn(i, 1, n + m) pr[i] = -1, ans[i] = 1, p[i] = i;
    forn(i, 1, n) {
        if (pr[i] == -1) {
            memset(u, 0, sizeof u);
            bool x = 0;
            forn(j, 1, n)
                if (pr[j] == -1) x |= dfs(j);
            if (!x) break;
        }
    }

    forn(i, 1, n + m)
        if (pr[i] == -1) ans[i] = 0;
    forn(i, 1, n + m) {
        if (pr[i] == -1) continue;
        for (auto to : g[i])
            if (pr[to] != -1 && pr[to] != i)
                p[f(pr[to])] = f(i);
    }
    forn(i, 1, n + m) {
        if (pr[i] == -1) continue;
        bool ok = 0;
        for (auto to : g[i])
            if (pr[to] == -1)
                {ok = 1; break;}
        if (!ok) continue;
        bad[f(pr[i])] = 1;
    //    memset(u, 0, sizeof u);
    //    clear(pr[i]);
    }
    forn(i, 1, n + m)
        if (bad[f(i)]) ans[i] = 0;

    int a = 0, b = 0;
    forn(i, 1, n)
        if (ans[i]) ++a;
    forn(i, n + 1, n + m)
        if (ans[i]) ++b;
    cout << a << "\n";
    forn(i, 1, n)
        if (ans[i]) cout << i << " ";
    cout << "\n" << b << "\n";
    forn(i, n + 1, n + m)
        if (ans[i]) cout << i - n << " ";

    return 0;
}
