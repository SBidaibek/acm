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

    int n, m, k;
    int a[N], t[N][2];
    pii q[N];

    void u(int x, int d, int i) {
        for (; x <= n; x |= x + 1) t[x][i] += d;
    }

    int g(int x, int i) {
        int ans = 0;
        for (; x > 0; x = (x & (x + 1)) - 1) ans += t[x][i];
        return ans;
    }

    int p[N], root[N], pr[N], good[N];

    int f(int x) {
        return p[x] == x ? x : p[x] = f(p[x]);
    }

    int solve(int _n, int _m, int _k, int *oa, int *ol, int *ob) {
        n = _n, m = _m, k = _k + 1;
        forn(i, 1, n) a[i] = oa[i - 1] + 1;
        forn(i, 1, m) q[i] = {ol[i - 1] + 1, ob[i - 1] + 1};
        forn(i, 1, n) p[i] = i, root[i] = i;

        forn(i, 1, m) {
            cerr << q[i].F << " " << q[i].S << " -> ";
            q[i].F += g(q[i].F, 0), q[i].S += g(q[i].S, 1);
            u(q[i].F + 1, q[i].S - q[i].F, 0);
            u(q[i].F, q[i].S - q[i].F, 1);
            int l = q[i].F, r = q[i].S;
            cerr << l << " " << r << "\n";
            continue;
            //cerr << q[i].F << " " << q[i].S << "\n";
            for (int ptr = l; ptr <= r;) {
                int nxt = f(ptr) + 1;
                if (nxt <= r)
                    p[f(ptr)] = nxt;
                else {
                    assert(f(ptr) == r);
                    root[f(ptr)] = n + i;
                }
                pr[root[f(ptr)]] = n + i;
                ptr = nxt;
            }
            int mx = 0;
            forn(j, l, r - 1) mx = max(mx, a[j]);
            good[i] = mx < k;
        }

        int ans = 0;
        forn(i, 1, n) {
            int cur = 0;
            for (int x = pr[i]; x && good[x - n]; x = pr[x])
                ++cur;
            ans = max(ans, cur);
        }
        return ans;
    }
}


int GetBestPosition(int N, int C, int R, int *K, int *S, int *E) {
    return kek :: solve(N, C, R, K, S, E);
}
