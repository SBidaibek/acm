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
    typedef vector <ll> vi;

    const int N = 2e6 + 1;
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    vector <pii> g[N];
    int lvl[N], m;
    int ans;

    int fc(int x, int p, int k, int &c) {
        int sz = 1;
        for (auto to : g[x])
            if (to.F != p && lvl[to.F] == -1)
                sz += fc(to.F, x, k, c);
        if (sz * 2 >= k && c == 0) c = x;
        return sz;
    }

    int used[N], timer;
    int mp[N];

    void relax(int x, int p, int dep, int len) {
        if (len > m) return;
        //cerr << "R " << x << " " << dep << " " << len << " " << mp[m - len] << " " << used[m - len] << "\n";
        if (used[m - len] == timer)
            ans = min(ans, dep + mp[m - len]);
        for (auto to : g[x])
            if (to.F != p && lvl[to.F] == -1)
                relax(to.F, x, dep + 1, len + to.S);
    }

    void calc(int x, int p, int dep, int len) {
        if (len > m) return;
        if (used[len] != timer)
            used[len] = timer, mp[len] = dep;
        else
            mp[len] = min(mp[len], dep);
        //cerr << "C " << x << " " << dep << " " << len << " " << mp[len] << "\n";
        for (auto to : g[x])
            if (to.F != p && lvl[to.F] == -1)
                calc(to.F, x, dep + 1, len + to.S);
    }

    void cd(int x, int sz, int dep) {
        int c = 0;
        fc(x, -1, sz, c);
        if (c) x = c;
        lvl[x] = dep;
        ++timer;
        used[0] = timer;
        mp[0] = 0;
        for (auto to : g[x])
            if (lvl[to.F] == -1) {
                relax(to.F, x, 1, to.S);
                calc(to.F, x, 1, to.S);
            }
        //cerr << x << " " << sz << " " <<dep << " " << ans << "\n";
        //exit(0);
        for (auto to : g[x])
            if (lvl[to.F] == -1)
                cd(to.F, sz / 2, dep + 1);
    }

    int best_path(int n, int k, int e[][2], int w[]) {
        m = k;
        forn(i, 0, n - 2) {
            forn(j, 0, 1) ++e[i][j];
            g[e[i][0]].pb({e[i][1], w[i]});
            g[e[i][1]].pb({e[i][0], w[i]});
        }
        forn(i, 1, n) lvl[i] = -1;
        ans = n;
        cd(1, n, 1);
        return ans == n ? -1 : ans;
    }
}

int best_path(int N, int K, int H[][2], int L[]) {
  return kek :: best_path(N, K, H, L);
}
