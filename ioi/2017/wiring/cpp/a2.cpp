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

//    forn(i, 1, n)
//        forn(j, 1, m)
//            cerr << i << " " << j << ": " << D[i][j] << "\n";
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
    vi h(a.size()), t(a.size());
    forn(i, 1, n + m)
        p[i] = p[i - 1] + a[i].F;
    forn(i, 1, n + m)
        if (a[i].S != a[i - 1].S) h[i] = i;
        else h[i] = h[i - 1];
    for1(i, n + m, 1)
        if (a[i].S != a[i + 1].S) t[i] = i;
        else t[i] = t[i + 1];
    vector <ll> c(a.size() + 1);
    vector <ll> n1(a.size() + 1), n2(a.size() + 1);

    forn(i, 1, n + m) d[i] = INF;
    d[0] = 0;
    forn(it, 2, n + m) {
        if (it != h[it]) continue;
        int j = h[it] - 1;
        int k = h[j] - 1;
        if (j - k == 1) {
            c[j] = 0;
            ll mn = d[j - 1];
            for1(z, k, h[k]) {
                c[z] = c[z + 1] + a[j].F - a[z].F;
                mn = min(mn, c[z] + d[z - 1]);
            }
            forn(i, it, t[it]) {
                c[i] = c[i - 1] + a[i].F - a[j].F;
                d[i] = min(d[i], mn + c[i]);
            }
        }
        else {
            c[it] = 0;
            n2[j + 1] = INF;
            n1[h[j] - 1] = INF;
            for1(z, j, h[j])
                c[z] = c[z + 1] + a[it].F - a[z].F;
            forn(z, h[j], j)
                n1[z] = min(n1[z - 1], c[z] + d[z - 1]);
            forn(i, it + 1, min(t[it], it + (j - h[j]))) {
                c[i] = c[i - 1] + a[i].F - a[it].F;
                d[i] = min(d[i], n1[j - (i - it)] + c[i]);
            }
            d[it] = min(d[it], n1[j]);
        //forn(i, it, t[it])
            //cerr << i << ": " << d[i] << " " << a[i].F << " " << a[i].S << "\n";
            c[j] = 0;
            for1(z, j - 1, h[j])
                c[z] = c[z + 1] + a[j].F - a[z].F;
            for1(z, j, h[j])
                n2[z] = min(n2[z + 1], c[z] + d[z - 1]);
            c[it] = a[it].F - a[j].F;
            forn(i, it + 1, t[it]) {
                //if (i == n + m) cerr << n2[j - (i - it)] << " " << c[i] << "\n";
                c[i] = c[i - 1] + a[i].F - a[j].F;
                d[i] = min(d[i], n2[max(h[j], j - (i - it))] + c[i]);
            }
        }
//        forn(i, it, t[it])
//            cerr << i << ": " << d[i] << " " << a[i].F << " " << a[i].S << "\n";
    }
    return d[n + m];
}
