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

const int N = 3e5 + 10;
const ll INF = 1e18 + 9;

ll d[N][2];

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

    d[0][0] = 0;
    d[0][1] = INF;
    int j = 1;
    forn(i, 1, m) {
        d[i][0] = INF;
        d[i][1] = INF;
        int prv = j;
        while (j < n && r[j + 1] <= b[i]) ++j;
        if (i == m && j < n) {
            forn(k, prv + 1, j + 1) {
                if (i == 1 && k != prv + 1) continue;
                ll l = (pr[k - 1] - pr[prv]) - 1ll * b[i - 1] * (k - 1 - prv);
                ll r = 1ll * b[i] * (j - k + 1) - (pr[j] - pr[k - 1]);
                d[i][1] = min(d[i][1], min(d[i - 1][0], d[i - 1][1]) + l + r);
            }
            d[i][1] += pr[n] - pr[j] - 1ll * b[i] * (n - j);
            continue;
        }
        else {
            if (prv < j) {
                forn(k, prv + 1, j) {
                    if (i == 1 && k != prv + 1) continue;
                    ll l = (pr[k - 1] - pr[prv]) - 1ll * b[i - 1] * (k - 1 - prv);
                    ll r = 1ll * b[i] * (j - k + 1) - (pr[j] - pr[k - 1]);
            cerr << i << ": " << prv << " " << j << " " << d[i][0] << " " << d[i][1] << "\n";
                    d[i][k < j] = min(d[i][k < j], min(d[i - 1][0], d[i - 1][1]) + l + r);
                }
            }
            d[i][0] = min(d[i - 1][1] + abs(b[i] - b[i - 1]), d[i - 1][0] + abs(b[i] - r[j]));
            if (j < n)
                d[i][0] = min(d[i][0], min(d[i - 1][0], d[i - 1][1]) + abs(b[i] - r[j + 1]));
            cerr << i << ": " << prv << " " << j << " " << d[i][0] << " " << d[i][1] << "\n";
        }
    }
    return min(d[m][0], d[m][1]);
}
