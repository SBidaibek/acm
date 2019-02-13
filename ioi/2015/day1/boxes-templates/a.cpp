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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int d[2][N];

ll delivery(int n, int k, int l, int p[]) {
    int m = l / 2;
    ll ans = 0;
    forn(i, 0, n - 1) {
        int l = max(0, i - k + 1);
        d[0][i] = 2 * p[i] + (l > 0 ? d[0][l - 1] : 0);
    }
    for1(i, n - 1, 0) {
        int r = min(n - 1, i + k - 1);
        d[1][i] = 2 * (n - p[i]) + (r < n - 1 ? d[1][r + 1] : 0);
    }
    ll ans = min(d[0][n - 1], d[1][0]);
    forn(i, 0, n - 2) {
        ans = min(ans, d[0][i] + d[1][i + 1]);
        ans = min(ans, d[0][i] + d[1][i + k] + n);
    }
    int p1 = 0, p2 = n - 1;
    while (p1 <= m) {
        int r = min(n - 1, p1 + k - 1);
        if (p[r] > m) break;
        ans += 2 * r;
        p1 = r + 1;
    }
    while (p2 > m) {
        int l = max(0, p2 - k + 1);
        if (p[l] <= m) break;
        ans += (n - l) * 2;
        p2 = l - 1;
    }
    cerr << p1 << " " << p2 << ": " << ans << "\n";
    if (p1 <= p2) {
        ll c = 2 * n;
        if (p2 - p1 + 1 <= k) {
            c = min(c, 2ll * p[p2]);
            c = min(c, 2ll * (n - p[p1]));
            c = min(c, 1ll * n);
        }
        forn(i, max(p1, p2 - k), min(p2 - 1, p1 + k - 1))
            c = min(c, 2ll * p[i] + 2ll * (n - p[i + 1]));
        ans += c;
    }
    return ans;
}
