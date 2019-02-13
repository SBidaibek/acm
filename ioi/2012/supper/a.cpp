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
    const int B = 1e9;

    bool bit(int x, int p) {
        return x & (1 << p);
    }

    void encode(int *q, int n, int k, int m) {
        int lg = 1;
        while ((1 << lg) < n) ++lg;
        forn(i, 0, n - 1)
            forn(j, 0, lg - 1)
                WriteAdvice(bit(q[i], j));
    }

    void decode(unsigned char *w, int n, int k, int m) {
        vi q(n);
        int lg = 1;
        while ((1 << lg) < n) ++lg;
        vi nxt(n, n), lst(n, -1), fst(n, n);
        forn(i, 0, n - 1) {
            if (lst[q[i]] > -1)
                nxt[lst[q[i]]] = i;
            else
                fst[q[i]] = i;
            lst[q[i]] = i;
        }
        set <pii> st;
        forn(i, 0, k - 1)
            st.insert({fst[i], i});
        forn(i, 0, n - 1) {
            cerr << i << ": ";
            for (auto x : st) cerr << "(" << x.F << " " << x.S << ") ";
            cerr << "\n";
            int req = GetRequest();
            assert(req == q[i]);
            if (st.count({i, req})) {
                st.erase({i, req});
                st.insert({nxt[i], req});
            }
            else {
                PutBack((--st.end()) -> S);
                st.erase(--st.end());
                st.insert({nxt[i], req});
            }
        }
    }
}

void ComputeAdvice(int *C, int N, int K, int M) {
    kek :: encode(C, N, K, M);
}

void Assist(unsigned char *A, int N, int K, int R) {
    kek :: decode(A, N, K, R);
}
