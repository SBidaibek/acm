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

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
vi g[N];
int d[N], u[N], lvl[N], e[N], v[N];
int ans, len;

void dfs(int x, int pr = -1) {
    ++v[u[x]];
    e[u[x]] += g[x].size();
    for (auto to : g[x]) {
        if (u[to]) continue;
        u[to] = u[x];
        lvl[to] = lvl[x] + 1;
        d[to] = d[x];
        dfs(to, x);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        if (f != t)
            g[t].pb(f);
    }

    int len = 0;
    forn(i, 1, n) {
        if (u[i]) continue;
        u[i] = i;
        d[i] = -1;
        dfs(i);
        e[i] /= 2;
        if (e[i] > v[i]) ans = 2;
        len = max(len, e[i]);
    }
    if (ans == 2) {
        cout << ">1\n";
        return 0;
    }
    forn(i, 1, n)
        if (u[i] == i && e[i] == v[i]) ans = 1;
    if (ans == 1) {
        cout << "1/1\n";
        return 0;
    }
    cout << len << "/" << (len + 1) << "\n";

    return 0;
}
