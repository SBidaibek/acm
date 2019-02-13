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

    bool bit(int x, int p) {
        return x & (1 << p);
    }

    int mp[3][3] = {
    {-1, 0, +1},
    {0, -1, +1},
    {+1, 0, -1}
    };

    vi g[N], t[N];
    int pr[N], d[N], used[N];

    void dfs(int x) {
        used[x] = 1;
        for (auto to : g[x])
            if (!used[to]) {
                pr[to] = x;
                dfs(to);
            }
    }

    void tree_dfs(int x, int p = -1) {
        pr[x] = p;
        for (auto to : t[x])
            if (to != p) tree_dfs(to, x);
    }

    void encode(int n, int k, int m, int *f, int *to) {
        forn(i, 0, m - 1) {
            g[f[i]].pb(to[i]);
            g[to[i]].pb(f[i]);
        }
        dfs(0);
        forn(i, 1, n - 1) {
            forn(b, 0, 9)
                encode_bit(bit(pr[i], b));
            t[pr[i]].pb(i);
            t[i].pb(pr[i]);
        }
        forn(i, 0, k - 1) {
        int cenc = 0;
            forn(j, 0, n - 1) d[j] = -1;
            queue <int> q;
            d[i] = 0;
            q.push(i);
            while (q.size()) {
                int x = q.front();
                q.pop();
                for (auto to : g[x]) {
                    if (d[to] != -1) continue;
                    d[to] = d[x] + 1;
                    q.push(to);
                }
            }
            tree_dfs(i);
            vi cnt(3);
            forn(j, 0, n - 1) {
                if (j == i) continue;
                int z = d[j] - d[pr[j]];
                ++cnt[z + 1];
            }
            int mx = 0;
            forn(j, 1, 2)
                if (cnt[mx] < cnt[j]) mx = j;
            assert(cnt[mx] * 3 >= n - 1);
            forn(b, 0, 1)
                encode_bit(bit(mx, b));
            map <int, int> rev_mp;
            forn(j, 0, 2)
                rev_mp[mp[mx][j]] = j;
            forn(j, 0, n - 1) {
                if (j == i) continue;
                int z = rev_mp[d[j] - d[pr[j]]];
                if (z == 0)
                    {encode_bit(0); cenc++;}
                if (z == 1)
                    {encode_bit(1); encode_bit(0); cenc += 2;}
                if (z == 2)
                    {encode_bit(1); encode_bit(1); cenc += 2;}
            }
        }
    }

    void decode(int n, int k) {
        forn(i, 0, n - 1) t[i].clear();
        forn(i, 1, n - 1) {
            pr[i] = 0;
            forn(b, 0, 9)
                pr[i] |= (decode_bit() << b);
            t[pr[i]].pb(i);
            t[i].pb(pr[i]);
        }
        forn(i, 0, k - 1) {
            tree_dfs(i);
            vi dif(n);
            forn(j, 0, n - 1) d[j] = -1;
            d[i] = 0;
            int mx = 0;
            forn(b, 0, 1)
                mx |= (decode_bit() << b);
            forn(j, 0, n - 1) {
                if (j == i) continue;
                int x = decode_bit();
                if (x > 0) x = (x * 2 + decode_bit()) - 1;
                dif[j] = mp[mx][x];
            }
            forn(it, 1, n)
                forn(j, 0, n - 1)
                    if (d[j] == -1 && d[pr[j]] != -1)
                        d[j] = d[pr[j]] + dif[j];
            forn(j, 0, n - 1)
                hops(i, j, d[j]);
        }
    }
}

void encode(int nv, int nh, int ne, int *v1, int *v2){
    kek :: encode(nv, nh, ne, v1, v2);
}

void decode(int nv, int nh) {
    kek :: decode(nv, nh);
}



