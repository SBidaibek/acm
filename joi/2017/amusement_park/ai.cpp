#include <bits/stdc++.h>
#include "Ioi.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

#define N kekkeasd
#define INF asomasd
#define B kaskkasd

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

#define g sekas
#define used laksdas
#define c ekek
#define ans asdasd

vi g[N];
int used[N], c[N];
ll ans;

int cnt;
int id[N], pr[N];
int got[N], sz[N];

int gen(int x) {
    id[x] = cnt++;
    used[x] = 1;
    for (auto to : g[x])
        if (!used[to]) {
            pr[to] = x;
            sz[x] += gen(to);
        }
    return ++sz[x];
}

int still = 60;

void dfs(int x, ll v) {
    used[x] = 1;
    if (!got[id[x] % 60]) {
        --still;
        ans |= (v << (id[x] % 60));
        got[id[x] % 60] = 1;
    }
    if (!still) return;
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x] && !got[id[to] % 60]) {
            dfs(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x]) {
            bool shit = 0;
            if (sz[to] >= 60) shit = 1;
            else {
                forn(k, id[to], id[to] + sz[to] - 1)
                    if (!got[k % 60]) shit = 1;
            }
            if (!shit) return;
            dfs(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x]) {
            dfs(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    if (!used[pr[x]]) {
        dfs(pr[x], Move(pr[x]));
        if (!still) return;
    }
}

void DFS(int x, ll v) {
    used[x] = 1;
    if (!got[id[x] % 60]) {
        --still;
        ans |= (v << (id[x] % 60));
        got[id[x] % 60] = 1;
    }
    if (!still) return;
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x] && !got[id[to] % 60]) {
            DFS(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x]) {
            bool shit = 0;
            if (sz[to] >= 60) shit = 1;
            else {
                forn(k, id[to], id[to] + sz[to] - 1)
                    if (!got[k % 60]) shit = 1;
            }
            if (!shit) continue;
            DFS(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    for (auto to : g[x]) {
        if (!used[to] && to != pr[x]) {
            DFS(to, Move(to));
            if (!still) return;
            Move(x);
        }
    }
    if (!used[pr[x]]) {
        DFS(pr[x], Move(pr[x]));
        if (!still) return;
    }
}

ll Ioi(int n, int m, int f[], int t[], int ver, int val, int tc) {
    forn(i, 0, m - 1) {
        g[f[i]].pb(t[i]);
        g[t[i]].pb(f[i]);
    }
    forn(i, 0, n - 1) pr[i] = -1;
    gen(0);
    forn(i, 0, n - 1) used[i] = 0;
    if (tc > 2) dfs(ver, val);
    else DFS(ver, val);
    return ans;
}

#undef g
#undef used
#undef c
#undef ans

#undef N
#undef INF
#undef B
