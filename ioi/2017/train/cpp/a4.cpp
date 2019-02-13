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

vi a, r;
vi g[N], rg[N];
int cnt[N], d[N], b[N];
int del[N];

vi who_wins(vi _a, vi _r, vi fr, vi to) {
    int n = _a.size(), m = fr.size();
    a = _a, r = _r;
    forn(i, 0, m - 1)
        {g[fr[i]].pb(to[i]); rg[to[i]].pb(fr[i]);}
    vi ans(n);
    int sz = n;
    for (queue <int> q;;) {
        int sav = sz;
        forn(i, 0, n - 1) cnt[i] = g[i].size() - b[i], d[i] = 0;
        forn(i, 0, n - 1) if (!del[i] && r[i]) q.push(i), d[i] = 1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto to : rg[x]) {
                if (del[to] || d[to]) continue;
                if (a[to])
                    d[to] = 1, q.push(to);
                else
                    if (--cnt[to] == 0)
                    d[to] = 1, q.push(to);
            }
        }
        forn(i, 0, n - 1)
            if (!del[i] && d[i] == 0) {
                del[i] = 1, --sz;
                for (auto to : rg[i]) ++b[to];
            }

        forn(i, 0, n - 1) cnt[i] = g[i].size(), d[i] = 0;
        forn(i, 0, n - 1) if (del[i]) q.push(i), d[i] = 1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto to : rg[x]) {
                if (d[to]) continue;
                if (!a[to])
                    d[to] = 1, q.push(to);
                else
                    if (--cnt[to] == 0)
                    d[to] = 1, q.push(to);
            }
        }
        forn(i, 0, n - 1)
            if (!del[i] && d[i] == 1) {
                del[i] = 1, --sz;
                for (auto to : rg[i]) ++b[to];
            }
        if (sz == sav) break;
    }
    forn(i, 0, n - 1)
        if (!del[i]) ans[i] = 1;
    forn(i, 0, n - 1) g[i].clear(), rg[i].clear();
    forn(i, 0, n - 1) del[i] = b[i] = 0;
    return ans;
}
