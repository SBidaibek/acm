#include <bits/stdc++.h>
#include "wiring.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 2e3 + 10;
const ll INF = 1e18 + 9;

ll d[N][N];

ll sub1(vi r, vi b) {
    int n = r.size(), m = b.size();
    r.insert(r.begin(), 0);
    b.insert(b.begin(), 0);

    forn(i, 0, n)
        forn(j, 0, m)
            d[i][j] = INF;
    d[0][0] = 0;
    forn(i, 1, n)
        forn(j, 1, m)
            d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + abs(r[i] - b[j]);

    return d[n][m];
}

ll d[n][2];

ll min_total_length(vi r, vi b) {
    if (r.back() > b.back()) swap(r, b);
    int n = r.size(), m = b.size();
    r.insert(r.begin(), -1);
    b.insert(b.begin(), -1);
    vi pr(r.size()), pb(b.size());
    forn(i, 1, n)
        pr[i] = pr[i - 1] + r[i];
    forn(i, 1, m)
        pb[i] = pb[i - 1] + b[i];

    ll ans = 0;
    int j = 1;
    forn(i, 1, m) {
        ll cur = INF;
        int prv = j;
        while (j < n && r[j + 1] <= b[i]) ++j;
        if (prv < j) {
            forn(k, prv + 1, j) {
                if (i == 1 && k != prv + 1) continue;
                ll l = (pr[k - 1] - pr[prv]) - 1ll * b[i - 1] * (k - 1 - prv);
                ll r = 1ll * b[i] * (j - k + 1) - (pr[j] - pr[k - 1]);
                cerr << i << ": " << prv << " " << j << " " << ans + l + r << "\n";
                cur = min(cur, ans + l + r);
            }
        }
        else
            cur = ans + abs(b[i] - b[i - 1]);
        ans = cur;
        cerr << i << ": " << prv << " " << j << " " << ans << "\n";
    }

    return ans;
}
