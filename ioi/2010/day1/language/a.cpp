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

    ll pen(ll a, ll b) {
        return (a - b) * (a - b);
    }

    int enc[M];
    unordered_map <ll, int> sum[M];

    void findlan(int *a) {
        map <ll, int> cnt;
        forn(i, 1, n - 1)
            cnt[K * a[i - 1] + a[i]]++;
        int bst = 0;
        ll cur = 1e18;
        forn(i, 0, M - 1) {
            if (!enc[i]) continue;
            ll nw = 0;
            for (auto x : cnt)
                nw += pen(x.S, sum[i].count(x.F) ? 0 : sum[i][x.F] / enc[i]);
            if (cur > nw)
                bst = i, cur = nw;
        }
        int ans = language(bst);
        ++enc[ans];
        for (auto x : cnt) sum[ans][x.F] += x.S;
    }
}

void excerpt(int *E) {
    kek :: findlan(E);
}

