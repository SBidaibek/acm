#include "boxes.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e7 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll d[2][N];

ll delivery(int n, int k, int l, int p[]) {
    int m = l / 2;
    forn(i, 0, n - 1) {
        int j = max(0, i - k + 1);
        d[0][i] = 2 * p[i] + (j > 0 ? d[0][j - 1] : 0);
    }
    for1(i, n - 1, 0) {
        int j = min(n - 1, i + k - 1);
        d[1][i] = 2 * (l - p[i]) + (j < n - 1 ? d[1][j + 1] : 0);
    }
    ll ans = min(d[0][n - 1], d[1][0]);
    forn(i, 0, n - 2) {
        ans = min(ans, d[0][i] + d[1][i + 1]);
        ans = min(ans, d[0][i] + (i + k + 1 < n ? d[1][i + k + 1] : 0) + l);
    }
    for1(i, n - 1, 1)
        ans = min(ans, (i - k - 1 >= 0 ? d[0][i - k - 1] : 0) + d[1][i] + l);
    if (n <= k) ans = min(ans, 1ll * l);
    return ans;
}
