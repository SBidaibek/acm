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
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    int n;
    vi g[N];

    void init(int _n) {
        n = _n;
    }

    void add_edge(int a, int b) {
        ++a, ++b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int u[N], del[N],  d[N];
    bool shit;

    void dfs(int x, int p = -1) {
        if (u[x]) {
            shit = 1;
            return;
        }
        u[x] = 1;
        int deg = (p != -1);
        for (auto to : g[x]) {
            if (del[to] || to == p) continue;
            if (++deg > 2) {
                shit = 1;
                return;
            }
            dfs(to, x);
            if (shit) return;
        }
    }

    int get() {
        int ans = 0;
        forn(i, 1, n) {
            del[i] = 1;
            shit = 0;
            forn(j, 1, n) u[j] = 0;
            forn(j, 1, n)
                if (!u[j] && !shit && j != i) dfs(j);
            ans += (!shit);
            del[i] = 0;
        }
        return ans;
    }
}


void Init(int _n) {
    kek :: init(_n);
}

void Link(int a, int b) {
    kek :: add_edge(a, b);
}

int CountCritical() {
    return kek :: get();
}

