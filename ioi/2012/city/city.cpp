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

    int n, d[N];

    int di[] = {0, -1, 0, +1};
    int dj[] = {+1, 0, -1, 0};

    int solve(int n, int *r, int *c) {
        if (n > 2000) {
            vi a;
            forn(i, 0, n - 1) a.pb(r[i]);
            sort(a.begin(), a.end());
            ll ans = 0, sum = 0;
            forn(i, 0, n - 1) {
                ans = (ans + 1ll * i * a[i] - sum + B) % B;
                sum = (sum + a[i]) % B;
            }
            a.clear();
            forn(i, 0, n - 1) a.pb(c[i]);
            sort(a.begin(), a.end());
            sum = 0;
            forn(i, 0, n - 1) {
                ans = (ans + 1ll * i * a[i] - sum + B) % B;
                sum = (sum + a[i]) % B;
            }
            return ans;
        }
        unordered_map <ll, int> mp;
        forn(i, 0, n - 1)
            mp[(1ll << 31) * r[i] + c[i]] = i + 1;
        int ans = 0;
        forn(s, 1, n) {
            forn(j, 1, n) d[j] = -1;
            d[s] = 0;
            queue <int> q;
            q.push(s);
            while (q.size()) {
                int i = q.front();
                q.pop();
                ans = (ans + d[i]) % B;
                forn(j, 0, 3) {
                    int x = r[i - 1] + di[j], y = c[i - 1] + dj[j];
                    if (mp.count((1ll << 31) * x + y)) {
                        int to = mp[(1ll << 31) * x + y];
                        if (d[to] == -1) {
                            d[to] = d[i] + 1;
                            q.push(to);
                        }
                    }
                }
            }
        }
        return ans / 2;
    }
}

int DistanceSum(int N, int *X, int *Y) {
    return kek :: solve(N, X, Y);
}
