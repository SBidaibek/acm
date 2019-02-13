#include <bits/stdc++.h>
#include "train.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace slow {
typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 3e5 + 10;
const ll INF = 1e18 + 9;

vi a, r;
vi g[N];
int u[N];
vi v;
int lst = -1;

bool dfs(int x) {
    u[x] = v.size();
    int sav = lst;
    if (r[x]) lst = v.size();
    v.pb(x);
    for (auto to : g[x]) {
        if (u[to] == -1) {
            bool res = dfs(to);
            if (a[x] == res) {
                v.pop_back();
                u[x] = -1;
                lst = sav;
                return a[x];
            }
        }
        else {
            bool res = (u[to] <= lst);
            if (a[x] == res) {
                v.pop_back();
                u[x] = -1;
                lst = sav;
                return a[x];
            }
        }
    }
    v.pop_back();
    u[x] = -1;
    lst = sav;
    return (!a[x]);
}

vi who_wins(vi _a, vi _r, vi fr, vi to) {
    int n = _a.size(), m = fr.size();
    a = _a, r = _r;
    forn(i, 0, m - 1)
        g[fr[i]].pb(to[i]);
    vi ans(n + 1);
    forn(s, 0, n - 1) {
        forn(i, 0, n - 1) u[i] = -1;
        ans[s] = dfs(s);
    }
    ans.pop_back();
    forn(i, 0, n - 1) g[i].clear();
    return ans;
}
}
