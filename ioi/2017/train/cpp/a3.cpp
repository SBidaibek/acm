#include <bits/stdc++.h>
#include "train.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 3e5 + 10;
const ll INF = 1e18 + 9;

//namespace fast {
vi a, r;
vi g[N], rg[N];
int u[N], comp[N], sz[N], loop[N], gd1[N], gd2[N];
vi o;

void topsort(int x, bool ban) {
    if (ban && r[x]) return;
    u[x] = 1;
    for (auto to : g[x])
        if (!u[to]) topsort(to, ban);
    o.pb(x);
}

void col(int x, int c, bool ban) {
    if (ban && r[x]) return;
    comp[x] = c;
    ++sz[c];
    for (auto to : rg[x])
        if (!comp[to]) col(to, c, ban);
}

vi who_wins(vi _a, vi _r, vi fr, vi to) {
    int n = _a.size(), m = fr.size();
    a = _a, r = _r;
    forn(i, 0, m - 1)
        {g[fr[i]].pb(to[i]); rg[to[i]].pb(fr[i]);
        if (fr[i] == to[i]) loop[fr[i]] = 1;}
    forn(i, 0, n - 1)
        if (!u[i]) topsort(i, 1);
    for1(i, o.size() - 1, 0)
        if (!comp[o[i]])
            col(o[i], o[i] + 1, 1);
    forn(i, 0, n - 1)
        if (!r[i] && (sz[comp[i]] > 1 || loop[i]))
            gd1[comp[i]] = 1;
    forn(it, 0, o.size() - 1) {
        int i = o[it];
        for (auto to : g[i])
            if (!r[to] && comp[to]) gd1[comp[i]] |= gd1[comp[to]];
    }
    forn(i, 0, n - 1) if (comp[i]) gd2[i] = gd1[comp[i]];
    o.clear();
    forn(i, 0, n - 1) u[i] = comp[i] = sz[i] = gd1[i] = 0;

    forn(i, 0, n - 1)
        if (!u[i]) topsort(i, 0);
    for1(i, o.size() - 1, 0)
        if (!comp[o[i]])
            col(o[i], o[i] + 1, 0);
    forn(i, 0, n - 1)
        if (gd2[i]) gd1[comp[i]] = 1;
    forn(it, 0, o.size() - 1) {
        int i = o[it];
        for (auto to : g[i])
            gd1[comp[i]] |= gd1[comp[to]];
    }
    vi ans;
    forn(i, 0, n - 1)
        ans.pb(!gd1[comp[i]]);

    o.clear();
    forn(i, 0, n - 1) g[i].clear(), rg[i].clear();
    forn(i, 0, n) comp[i] = u[i] = gd1[i] = gd2[i] = loop[i] = sz[i] = 0;

    return ans;
}
//}
