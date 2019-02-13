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
        vi nxt(n, n), lst(n, -1), fst(n, n);
        vi ans(n + k), prv(n);
        forn(i, 0, n - 1) {
            if (lst[q[i]] > -1)
                nxt[lst[q[i]]] = i;
            else
                fst[q[i]] = i;
            lst[q[i]] = i;
        }
        set <pii> st;
        forn(i, 0, k - 1) {
            st.insert({fst[i], i});
            prv[i] = i;
        }
        forn(i, 0, n - 1) {
            int req = q[i];
            if (st.count({i, req})) {
                ans[prv[req]] = 1;
                st.erase({i, req});
                st.insert({nxt[i], req});
            }
            else {
                int id = (--st.end()) -> S;
                ans[prv[id]] = 0;
                st.erase(--st.end());
                st.insert({nxt[i], req});
            }
            prv[req] = k + i;
        }
        for (auto p : st)
            ans[prv[p.S]] = 0;
        forn(i, 0, k + n - 1)
            WriteAdvice(ans[i]);
    }

    void decode(unsigned char *w, int n, int k, int m) {
        set <pii> st;
        forn(i, 0, k - 1)
            st.insert({w[i], i});
        forn(i, 0, n - 1) {
            int req = GetRequest();
            if (st.count({1, req})) {
                st.erase({1, req});
                st.insert({w[k + i], req});
            }
            else {
                PutBack(st.begin() -> S);
                st.erase(st.begin());
                st.insert({w[k + i], req});
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
