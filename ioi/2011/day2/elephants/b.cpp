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

    int n, k;
    int *a;
    set <pii> st;

    void init(int _n, int _k, int og[]) {
        n = _n, k = _k;
        a = og;
        forn(i, 0, n - 1)
            st.insert({a[i], i});
    }

    int get() {
        int ans = 0, r = -1;
        for (auto x : st)
            if (x.F > r) ++ans, r = x.F + k;
        return ans;
    }

    int upd(int x, int y) {
        st.erase({a[x], x});
        a[x] = y;
        st.insert({a[x], x});
        return get();
    }
}

int update(int id, int nv) {
    return kek :: upd(id, nv);
}

void init(int n, int l, int xs[]) {
    kek :: init(n, l, xs);
}


