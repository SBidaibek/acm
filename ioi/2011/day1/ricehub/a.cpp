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
    typedef vector <ll> vi;

    const int N = 2e6 + 1;
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    ll p[N];

    int besthub(int n, int mx, int x[], ll k){
        p[1] = x[0];
        forn(i, 2, n)
            p[i] = p[i - 1] + x[i - 1];
        int r = 0;
        ll s = 0;
        int ans = 1;
        forn(i, 0, n - 1) {
            if (r < i) r = i, s = 0;
            else {
                int m = (i + r) / 2;
                s = (1ll * x[m] * (m - i + 1) - (p[m + 1] - p[i]))
                    + ((p[r + 1] - p[m + 1]) - 1ll * x[m] * (r - m));
            }
            while (r < n && s <= k) {
                ++r;
                if (r == n) break;
                int m = (i + r) / 2;
                s = (1ll * x[m] * (m - i + 1) - (p[m + 1] - p[i]))
                    + ((p[r + 1] - p[m + 1]) - 1ll * x[m] * (r - m));
            }
            ans = max(ans, r - i);
        }
        return ans;
    }
}

int besthub(int n, int L, int X[], long long B){
    return kek::besthub(n, L, X, B);
}

