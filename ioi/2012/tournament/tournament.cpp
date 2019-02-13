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

    typedef struct node* node_ptr;

    struct node {
        int y, sz, c, sum;
        node_ptr l, r;
        node() {
            y = rand();
            sz = 1, c = 1, sum = 1;
            l = r = 0;
        }
    } nds[N];

    int gsz(node_ptr t) {
        return t ? t -> sz : 0;
    }

    int gsum(node_ptr t) {
        return t ? t -> sum : 0;
    }

    void recalc(node_ptr t) {
        if (!t) return;
        t -> sz = gsz(t -> l) + 1 + gsz(t -> r);
        t -> sum = gsum(t -> l) + t -> c + gsum(t -> r);
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

    void Split(node_ptr w, node_ptr &l, node_ptr &r, int x) {
        if (!w) {
            l = r = 0;
            return;
        }
        if (gsz(w -> l) + 1 <= x)
            Split(w -> r, w -> r, r, x - (gsz(w -> l) + 1)), l = w;
        else
            Split(w -> l, l, w -> l, x), r = w;
        recalc(w);
    }

    int n, m, k;
    int a[N], t[N];
    pii q[N];

    int p[N], ver[N], pr[N], good[N], cnt[N];

    int f(int x) {
        return p[x] == x ? x : p[x] = f(p[x]);
    }

    int gmax(int l, int r) {
        int ans = 0;
        for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) ans = max(ans, t[l++]);
            if (r % 2 == 0) ans = max(ans, t[r--]);
        }
        return ans;
    }

    int solve(int _n, int _m, int _k, int *oa, int *ol, int *ob) {
        n = _n, m = _m, k = _k + 1;
        forn(i, 1, n) a[i] = oa[i - 1] + 1;
        forn(i, 1, m) q[i] = {ol[i - 1] + 1, ob[i - 1] + 1};
        forn(i, 1, n) p[i] = i, ver[i] = i, t[i + n - 1] = a[i];
        for1(i, n - 1, 1) t[i] = max(t[i * 2], t[i * 2 + 1]);

        node_ptr root = 0;
        forn(i, 1, n)
            Merge(root, root, &nds[i]);

        forn(i, 1, m) {
            node_ptr L, R, M;
            Split(root, L, R, q[i].S);
            q[i].S = gsum(L);
            Split(L, L, M, q[i].F - 1);
            q[i].F = gsum(L) + 1;
            int tmp = gsum(M);
            M = &nds[n + i];
            M -> c = M -> sum = tmp;
            Merge(L, L, M);
            Merge(root, L, R);
            int ptr = q[i].F, r = q[i].S;
            while (ptr <= r) {
                int nxt = f(ptr) + 1;
                pr[ver[f(ptr)]] = n + i;
                if (nxt > r)
                    ver[f(ptr)] = n + i;
                else
                    p[f(ptr)] = f(nxt);
                ptr = nxt;
            }
            good[i] = gmax(q[i].F, r - 1) < k;
        }

        for1(i, n + m, n + 1)
            if (good[i - n]) cnt[i] = cnt[pr[i]] + 1;

        int ans = 0, at = 0;
        forn(i, 1, n) {
            int cur = 0;
            cur = cnt[pr[i]];
            //for (int x = pr[i]; x && good[x - n]; x = pr[x])
            //    ++cur;
            if (ans < cur) at = i - 1;
            ans = max(ans, cur);
        }
        return at;
    }
}


int GetBestPosition(int N, int C, int R, int *K, int *S, int *E) {
    return kek :: solve(N, C, R, K, S, E);
}
