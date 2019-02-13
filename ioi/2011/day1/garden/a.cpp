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

    const int L = 21;
    int u[N], esz;
    vi g[N], id[N];
    int nxt[N][L];
    int eto[N], ef[N], start[N];

    void count_routes(int n, int m, int s, int e[][2], int q, int w[]) {
        forn(i, 0, m - 1) {
            forn(j, 0, 1) ++e[i][j];
            forn(j, 0, 1) g[e[i][j]].pb(e[i][1 - j]);
        }
        forn(x, 1, n) {
            if (!g[x].size()) continue;
            for (auto to : g[x]) {
                id[x].pb(++esz);
                eto[esz] = to, ef[esz] = x;
                if (to == g[x][0]) start[esz] = 1;
            }
        }
        forn(x, 1, n) {
            forn(i, 0, g[x].size() - 1) {
                int to = g[x][i];
                if (g[to].size() == 1)
                    nxt[id[x][i]][0] = id[to][0];
                else
                    if (g[to][0] == x)
                        nxt[id[x][i]][0] = id[to][1];
                    else
                        nxt[id[x][i]][0] = id[to][0];
            }
        }
        forn(j, 1, L - 1)
            forn(i, 1, esz)
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        int cyc = 0;
        vi tin(esz + 1);
        {
            int c = 0, x = 1;
            for (; !tin[x]; x = nxt[x][0])
                tin[x] = ++c;
            cyc = c - tin[x] + 1;
        }
        ++s;
        {
            int cmp = 0;
            forn(i, 1, esz) {
                if (u[i] || eto[i] != s) continue;
                set <int> st;
                int x = i;
                for (; !u[x]; x = nxt[x][0]) {
                    st.insert(x); u[x] = 1;}
                if (st.count(x))
                    ++cmp;
            }
            assert(cmp <= 2);
        }
        vi sav(esz, -1);
        forn(it, 0, q - 1) {
            int k = w[it] - 1;
            while (k >= esz) {
                 k %= cyc;
                 while (k + cyc < esz) k += cyc;
            }
            if (sav[k] > -1) {
                answer(sav[k]);
                continue;
            }
            int ans = 0;
            forn(i, 1, esz) {
                if (!start[i]) continue;
                int x = i;
                for1(j, L - 1, 0)
                    if (k & (1 << j))
                        x = nxt[x][j];
                if (eto[x] == s) ++ans;
            }
            answer(ans);
        }
    }
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
    kek :: count_routes(N, M, P, R, Q, G);
}

