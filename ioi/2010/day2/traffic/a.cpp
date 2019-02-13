#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace kek {
    typedef long long ll;
    typedef pair <int, int> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;

    int n, a[N];
    vi g[N];
    int d[N], sum[N];

    void dfs(int x, int p) {
        sum[x] = a[x];
        for (auto to : g[x]) {
            if (to == p) continue;
            dfs(to, x);
            sum[x] += sum[to];
            d[x] = max(d[x], sum[to]);
        }
    }

    int solve(int _n, int og[], int f[], int t[]) {
        n = _n;
        forn(i, 0, n - 2) {
            g[++f[i]].pb(++t[i]);
            g[t[i]].pb(f[i]);
        }
        forn(i, 1, n) a[i] = og[i - 1];
        dfs(1, 0);
        forn(i, 1, n)
            d[i] = max(d[i], sum[1] - sum[i]);
        int ans = 1;
        forn(i, 2, n)
            if (d[i] < d[ans]) ans = i;
        return ans - 1;
    }
}

int LocateCentre(int N, int pp[], int S[], int D[]) {
   return kek :: solve(N, pp, S, D);
}



