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

    typedef struct node* node_ptr;

    struct node {
        int y, sz, x;
        node_ptr l, r;
        node() {
            y = rand();
            sz = 1;
            l = r = 0;
        }
    } nds[N];
    int n_sz;

    node_ptr new_node(int x) {
        nds[n_sz].x = x;
        return &nds[n_sz++];
    }

    int gsz(node_ptr t) {
        return t ? t -> sz : 0;
    }

    void recalc(node_ptr t) {
        if (!t) return;
        t -> sz = gsz(t -> l) + 1 + gsz(t -> r);
    }

    void Merge(node_ptr &w, node_ptr l, node_ptr r) {
        if (!l || !r) {
            w = l ? l : r;
            return;
        }
        if (l -> y > r -> y)
            Merge(l -> r, l -> r, r), w = l;
        else
            Merge(r -> l, l, r -> l), w = r;
        recalc(w);
    }

    void Split(node_ptr w, node_ptr &l, node_ptr &r, int s) {
        if (!w) {
            l = r = 0;
            return;
        }
        if (w -> x <= s)
            Split(w -> r, w -> r, r, s), l = w;
        else
            Split(w -> l, l, w -> l, s), r = w;
        recalc(w);
    }

    void Dplit(node_ptr w, node_ptr &l, node_ptr &r, int x) {
        if (!w) {
            l = r = 0;
            return;
        }
        if (gsz(w -> l) + 1 <= x)
            Dplit(w -> r, w -> r, r, x - (gsz(w -> l) + 1)), l = w;
        else
            Dplit(w -> l, l, w -> l, x), r = w;
        recalc(w);
    }


    bool bit(int x, int p) {
        return x & (1 << p);
    }

    void encode(int *q, int n, int k, int m) {
        int lg = 1;
        while ((1 << lg) < k) ++lg;
        vi nxt(n, n), lst(n, -1), fst(n, n);
        forn(i, 0, n - 1) {
            if (lst[q[i]] > -1)
                nxt[lst[q[i]]] = i;
            else
                fst[q[i]] = i;
            lst[q[i]] = i;
        }
        set <pii> st;
        node_ptr root = 0;
        forn(i, 0, k - 1) {
            st.insert({fst[i], i});
            Merge(root, root, new_node(i));
        }
        forn(i, 0, n - 1) {
            int req = q[i];
            if (st.count({i, req})) {
                st.erase({i, req});
                st.insert({nxt[i], req});
            }
            else {
                //for (auto x : st) cerr << "(" << x.F << " " << x.S << ") ";
                //cerr << "| ";
                int id = (--st.end()) -> S;
                node_ptr L, R;
                Split(root, L, R, id);
                int cnt = gsz(L) - 1;
                //cerr << id << ": " << cnt << "\n";
                forn(j, 0, lg - 1)
                    WriteAdvice(bit(cnt, j));
                Merge(root, L, R);
                st.erase(--st.end());
                st.insert({nxt[i], req});
            }
        }
    }

    void decode(unsigned char *w, int n, int k, int m) {
        int lg = 1, cur = 0;
        while ((1 << lg) < k) ++lg;
        set <int> st;
        node_ptr root = 0;
        forn(i, 0, k - 1) {
            st.insert(i);
            Merge(root, root, new_node(i));
        }
        forn(i, 0, n - 1) {
            int req = GetRequest();
            cerr << i << ": ";for (auto x : st) cerr << x    << " ";
            cerr << "\n";
            if (!st.count(req)) {
                int x = 0;
                forn(j, 0, lg - 1)
                    x += (w[cur++] << j);
                cerr << x << "\n";
                node_ptr L, R, M;
                Dplit(root, L, R, x);
                Dplit(R, M, R, 1);
                int id = M -> x;
                PutBack(x);
                Merge(root, L, R);
                st.erase(x);
                st.insert(req);
                Split(root, L, R, req);
                Merge(L, L, new_node(req));
                Merge(root, L, R);
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
