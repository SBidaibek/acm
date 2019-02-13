#include <bits/stdc++.h>
#include "train.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

//namespace fast {
typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 3e5 + 10;
const ll INF = 1e18 + 9;

vi a, r;
vi g[N], rg[N];
int u[N], comp[N], sz[N], loop[N], good[N];
vi o;

void topsort(int x) {
    u[x] = 1;
    for (auto to : g[x])
        if (!u[to]) topsort(to);
    o.pb(x);
}

void col(int x, int c) {
    comp[x] = c;
    ++sz[c];
    //cerr << x << " " << c << "\n";
    for (auto to : rg[x])
        if (!comp[to]) col(to, c);
}

vi who_wins(vi _a, vi _r, vi fr, vi to) {
    int n = _a.size(), m = fr.size();
    a = _a, r = _r;
    forn(i, 0, m - 1)
        {g[fr[i]].pb(to[i]); rg[to[i]].pb(fr[i]);
        if (fr[i] == to[i]) loop[fr[i]] = 1;}
    forn(i, 0, n - 1)
        if (!u[i]) topsort(i);
    //forn(i, 0, n - 1) cerr << i << " = " << comp[i] << "\n";
    for1(i, n - 1, 0)
        if (!comp[o[i]])
            col(o[i], o[i] + 1);
    //forn(i, 0, n - 1) cerr << i << " = " << comp[i] << "\n";
    forn(i, 0, n - 1)
        if (r[i] && (loop[i] || sz[comp[i]] > 1)) good[comp[i]] = 1;
    forn(it, 0, n - 1) {
        int i = o[it];
        for (auto to : g[i])
            good[comp[i]] |= good[comp[to]];
    }
    vi ans;
    forn(i, 0, n - 1)
        ans.pb(good[comp[i]]);
    o.clear();
    forn(i, 0, n - 1) g[i].clear(), rg[i].clear();
    forn(i, 0, n) comp[i] = u[i] = good[i] = loop[i] = sz[i] = 0;
    return ans;
}
//}
