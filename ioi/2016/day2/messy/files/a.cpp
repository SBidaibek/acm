#include <bits/stdc++.h>

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

    int n;
    vi g[N];

    void init(int _n) {
        n = _n;
    }

    void add_edge(int a, int b) {
        ++a, ++b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int d[N];

    int get() {
        int mx = 1, c3 = 0, c4 = 0;
        forn(i, 1, n) {
            if (g[i].size() > g[mx].size()) mx = i;
            c3 += (g[i].size() == 3);
            c4 += (g[i].size() > 3);
            d[i] = 0;
            for (auto to : g[i])
                if (g[to].size() == 3) ++d[i];
        }
        if (g[mx].size() < 3) return n;
        if (g[mx].size() > 3) return c4 > 1 ? 0 : (d[mx] == c3);
        int ans = 0;
        forn(i, 1, n)
            if (d[i] + (g[i].size() == 3) == c3) ++ans;
        return ans;
    }
}


std::vector<int> restore_permutation(int n, int w, int r) {
    return kek :: solve(n, w, r);
    add_element("0");
    compile_set();
    check_element("0");
    return std::vector<int>();
}


