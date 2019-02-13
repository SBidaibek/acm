#include "simurgh.h"
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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

//namespace kek {

int get(vi q) {
    return count_common_roads(q);
}

vector <pii> g[N];
int u[N], in[N];

void dfs(int x) {
    u[x] = 1;
    for (auto e : g[x]) {
        if (u[e.F]) continue;
        in[e.S] = 1;
        dfs(e.F);
    }
}

void calc(int x, int pr = -1) {

    for (auto e : g[x]) {
        if (!in[e.S] || col[e.F] == c) continue;
        dfsc(e.F, c);
    }
}

int gold[N];

vi find_roads(int n, vi ef, vi et) {
    int m = ef.size();
    forn(i, 0, m - 1) {
        g[ef[i]].pb({et[i], i});
        g[et[i]].pb({ef[i], i});
    }
    dfs(0);
    calc(0);
    forn(i, 0, m - 1)
        if (gold[i]) ans.pb(i);
    return ans;
}

//}
