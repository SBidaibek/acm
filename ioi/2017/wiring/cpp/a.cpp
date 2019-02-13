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
const int K = 2e2;
const ll INF = 1e18 + 9;

ll D[K][K];

ll slow(vi r, vi b) {
    int n = r.size(), m = b.size();
    r.insert(r.begin(), 0);
    b.insert(b.begin(), 0);

    forn(i, 0, n)
        forn(j, 0, m)
            D[i][j] = INF;
    D[0][0] = 0;
    forn(i, 1, n)
        forn(j, 1, m)
            D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + abs(r[i] - b[j]);

    forn(i, 1, n)
        forn(j, 1, m)
            cerr << i << " " << j << ": " << D[i][j] << "\n";
    cerr << "slow = " << D[n][m] << "\n";
    return D[n][m];
}

ll d[N];

ll min_total_length(vi r, vi b) {
    if (r.back() > b.back()) swap(r, b);
    int n = r.size(), m = b.size();
    r.insert(r.begin(), -1);
    b.insert(b.begin(), -1);
    vector <ll> pr(r.size()), pb(b.size());
    forn(i, 1, n)
        pr[i] = pr[i - 1] + r[i];
    forn(i, 1, m)
        pb[i] = pb[i - 1] + b[i];

    vector <pii> a(1, {-1, -1});
    forn(i, 1, n) a.pb({r[i], 0});
    forn(i, 1, m) a.pb({b[i], 1});
    sort(a.begin() + 1, a.end());
    vector <ll> p(a.size());
    vi h(a.size());
    forn(i, 1, n + m)
        p[i] = p[i - 1] + a[i].F;
    forn(i, 1, n + m)
        if (a[i].S != a[i - 1].S) h[i] = i;
        else h[i] = h[i - 1];

    d[0] = 0;
    forn(i, 1, n + m) {
        //cerr << "start " << i << " " << a[i].F << " " << a[i].S << "\n";
        d[i] = INF;
        vi c(2), q(2);
        ++c[a[i].S];
        q[a[i].S] = i;
        for1(j, i - 1, 1) {
            ++c[a[j].S];
            q[a[j].S] = j;
            if (c[0] > 1 && c[1] > 1) break;
            if (c[0] == 0 || c[1] == 0) continue;
            int x = 0;
            if (c[0] == 1) x = q[0]; else x = q[1];
            ll cost = (p[i] - p[x]) - 1ll * a[x].F * (i - x)
                    + 1ll * a[x].F * (x - j) - (p[x - 1] - p[j - 1]);
            d[i] = min(d[i], d[j - 1] + cost);
            //cerr << d[i] << " " << j << " tp1\n";
        }
        if (i == h[i]) continue;
        for (int j = h[i] - 2; j > 0 && a[j].S != a[i].S; --j) {
            ll cost = 0;
            int leni = i - h[i] + 1;
            int lenj = h[i] - j;
            if (leni >= lenj) {
                int k = h[i] + lenj - 1;
                cost = (p[k] - p[h[i] - 1]) - (p[h[i] - 1] - p[j - 1])
                    + (p[i] - p[k]) - a[h[i] - 1].F * (i - k);
            }
            else {
                int k = h[i] - leni;
                cost = (p[i] - p[h[i] - 1]) - (p[h[i] - 1] - p[k - 1])
                    + a[h[i]].F * (k - j) - (p[k - 1] - p[j - 1]);
            }
            //ll cost = (p[i] - p[h[i]]) - 1ll * a[h[i] - 1].F * (i - h[i])
            //        + 1ll * a[h[i]].F * (h[i] - j - 1) - (p[h[i] - 2] - p[j - 1]);
            d[i] = min(d[i], d[j - 1] + cost);
            //cerr << d[i] << " " << j << " tp2\n";
        }
        //cerr << i << ": " << d[i] << "\n";
    }
    //cerr << "fast = " << d[n + m] << "\n";
    return d[n + m];
}
