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
    const int B = 1e9 + 7;

    void encode(int n, int a[]) {
        vector <pii> v;
        forn(i, 0, n - 1) {
            send(a[i]), send(a[i]);
            v.pb({a[i], i});
        }
        sort(v.begin(), v.end());
        forn(i, 0, n - 1) {
            int x = ((i << 4) | (v[i].S));
            //bitset <8> b(x);
            //cerr << b << "\n";
            send(x);
        }
    }

    int cnt[(1 << 8)];

    void decode(int n, int l, int x[]) {
        forn(i, 0, 255) cnt[i] = 0;
        forn(i, 0, l - 1)
            ++cnt[x[i]];
        vi a, v, ans(n);
        forn(i, 0, 255) {
            forn(j, 1, cnt[i] / 2) a.pb(i);
            if (cnt[i] % 2 == 1) v.pb(i);
        }
        assert(a.size() == n && v.size() == n);
        sort(v.begin(), v.end());
        forn(i, 0, v.size() - 1) {
            int x = (v[i] >> 4), id = (v[i] % 16);
            assert(x == i);
            ans[id] = a[x];
        }
        for (auto x : ans)
            output(x);
    }
}

void encode(int N, int M[]) {
    kek :: encode(N, M);
}

void decode(int N, int L, int X[]) {
    kek :: decode(N, L, X);
}


