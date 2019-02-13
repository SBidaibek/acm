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

int col[N], ch[N];

void dfsc(int x, int c) {
    col[x] = c;
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
    vi q;
    forn(i, 0, m - 1)
        if (in[i]) q.pb(i);
    int def = get(q);
    vi ans;
    forn(i, 0, m - 1) {
        if (!in[i]) continue;
        in[i] = 0;
        forn(j, 0, n - 1) col[j] = 0;
        dfsc(ef[i], 1);
        dfsc(et[i], 2);
        in[i] = 1;
        vector <pii> tmp;
        q.erase(find(q.begin(), q.end(), i));
        forn(j, 0, m - 1) {
            if (col[ef[j]] == col[et[j]]) continue;
            if (ef[i] != ef[j] && ef[i] != et[j]
                && et[i] != ef[j] && et[i] != et[j]) continue;
            ch[j] = 1;
            q.pb(j);
            tmp.pb({get(q), j});
            q.pop_back();
        }
        q.pb(i);
        sort(tmp.begin(), tmp.end(), greater <pii> ());
        forn(j, 0, tmp.size() - 1)
            if (tmp[j].F == tmp[0].F) gold[tmp[j].S] = 1;
    }
    forn(i, 0, m - 1) if (gold[i]) ans.pb(i);
    return ans;
}

//}
