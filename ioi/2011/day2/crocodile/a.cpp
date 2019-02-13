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
    typedef pair <ll, ll> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;

    int ex[N];
    pii d[N];
    vector <pii> g[N];

    pii rlx(pii p, ll x) {
        assert(p.F >= p.S);
        if (p.S > x) {p.F = p.S; p.S = x;}
        else p.F = min(p.F, x);
        return p;
    }

    int travel_plan(int n, int m, int e[][2], int w[], int psz, int p[]) {
        forn(i, 0, psz - 1)
            ex[++p[i]] = 1;
        forn(i, 0, m - 1) {
            forn(j, 0, 1) ++e[i][j];
            forn(j, 0, 1) g[e[i][j]].pb({e[i][1 - j], w[i]});
        }
        set < pair <pii, int> > st;
        forn(i, 1, n) {
            if (ex[i]) {
                d[i] = {0, 0};
                st.insert({d[i], i});
            }
            else d[i] = {INF, INF};
        }
        while (st.size()) {
            int x = st.begin() -> S;
            st.erase(st.begin());
            for (auto to : g[x]) {
                pii nw = rlx(d[to.F], d[x].F + to.S);
                if (nw != d[to.F]) {
                    st.erase({d[to.F], to.F});
                    d[to.F] = nw;
                    st.insert({d[to.F], to.F});
                }
            }
        }
        return d[1].F;
    }
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {
    kek :: travel_plan(N, M, R, L, K, P);
}

