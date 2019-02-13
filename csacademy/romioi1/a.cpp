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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, e;
vector <pii> g[N];
int u[N], id[N], ok[N];

void dfs(int x, int p) {
    ok[x] = 1;
    if (g[x].size() == 2) {
        for (auto to : g[x])
            if (to.F != p) {
                id[to.S] = ++e;
                if (!ok[to.F])
                    dfs(to.F, x);
            }
        return;
    }
    int s = e;
    for (auto to : g[x]) {
        if (ok[to.F]) continue;
        id[to.S] = ++e;
        dfs(to.F, x);
        break;
    }
    if (s == e) {
        for (auto to : g[x])
            if (to.F != p) {
                id[to.S] = ++e;
                if (!ok[to.F]) dfs(to.F, x);
                break;
            }
    }
    for (auto to : g[x]) {
        if (ok[to.F]) continue;
        if (!id[to.S]) id[to.S] = ++e;
        dfs(to.F, x);
    }
}

pii p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if (n == 2) {
        cout << "1 2 1\n";
        return 0;
    }
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        p[i] = {f, t};
        g[f].pb({t, i});
        g[t].pb({f, i});
    }
    forn(i, 1, n)
        if (g[i].size() == 1)
            ok[i] = 1;
    forn(i, 1, n)
        if (!ok[i]) {
            dfs(i, 0);
            break;
        }
    forn(i, 1, n) assert(ok[i]);
    forn(i, 1, m) {
        if (id[i] == 0) id[i] = ++e;
        cout << p[i].F << " " << p[i].S << " " << id[i] << "\n";
    }


    return 0;
}
