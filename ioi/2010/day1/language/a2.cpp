#include <bits/stdc++.h>
#include "grader.h"
//#include "cluedo.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace kek {
    typedef long long ll;
    typedef pair <ll, ll> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;
    const ll K = (1 << 16);
    const int M = 56;

    int n = 100;

    ll pen(ld a, ld b) {
        return (a - b) * (a - b);
    }

    int enc[M];
    ll sum[M][K], has[M][K];
    int common[K], space = -1;
    ll sumlen[M], sumcnt[M];
    int t;

    void findlan(int *a) {
        if (++t == 500) {
            ///rebuild
            ld mx = 0;
            forn(c, 0, K - 1) {
                ld mn = 1e9;
                bool shit = 0;
                forn(i, 0, M - 1) {
                    if (!has[i][c]) {
                        shit = 1;
                        break;
                    }
                    mn = min(mn, has[i][c] / ld(enc[i]));
                }
                if (shit) continue;
                if (mn > mx) mx = mn, space = c;
                //if (mn > 0.05)
                //    common[c] = 1;
            }
            assert(space != -1);
        }
        vi cnt(K), v, ls;
        if (space != -1) ls.pb(0);
        forn(i, 0, n - 1) {
            if (cnt[a[i]] == 0) v.pb(a[i]);
            cnt[a[i]]++;
            if (space != -1) {
                if (a[i] == space) ls.pb(0);
                else ++ls.back();
            }
        }
        int bst = 0;
        ll cur = 1e18;
        ld mavlen = 0;
        if (space != -1) {
            for (auto x : ls) mavlen += x;
            mavlen /= ls.size();
        }
        forn(i, 0, M - 1) {
            if (!enc[i]) continue;
            ll nw = 0;
            for (auto x : v) {
                if (common[x]) continue;
                if (sum[i][x] == 0)
                    nw += 40;
                nw += pen(cnt[x], sum[i][x] / enc[i]);
                if (space != -1)
                        nw += 10000 * pen(mavlen, sumlen[i] / ld(sumcnt[i]));
            }
            if (bst == -1 || (cur > nw))
                bst = i, cur = nw;
        }
        int ans = language(bst);
        ++enc[ans];
        sumcnt[ans] += ls.size();
        for (auto x : ls) sumlen[ans] += x;
        for (auto x : v) sum[ans][x] += cnt[x], has[ans][x]++;

    }
}

void excerpt(int *E) {
    kek :: findlan(E);
}

