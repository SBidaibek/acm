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

    bool bit(int x, int i) {
        return x & (1 << i);
    }

    void encode(int n, int a[]) {
        int c = 0, st = 1;
        forn(i, 0, n - 1)
            forn(j, 0, 7)
                if (bit(a[i], j))
                    ++c;
        if (c > n * 4) {
            forn(i, 1, 4) send(0);
            st = 0;
        }
        forn(i, 0, n - 1) {
            forn(j, 0, 3) {
                if (bit(a[i], j) == st)
                    send((j << 6) | i);
                if (bit(a[i], j + 4) == st)
                    send((j << 6) | i), send((j << 6) | i);
            }
        }
    }

    int cnt[(1 << 8)];

    void decode(int n, int l, int x[]) {
        vi ans(n);
        forn(i, 0, 255) cnt[i] = 0;
        forn(i, 0, l - 1) ++cnt[x[i]];
        int st = 1;
        if (cnt[0] >= 4) {
            st = 0;
            for (auto &x : ans)
                x = 255;
            cnt[0] -= 4;
        }
        forn(i, 0, 255) {
            if (!cnt[i]) continue;
            int b = (i >> 6), id = (i % 64);
            if (cnt[i] & 1)
                ans[id] ^= (1 << b);
            if (cnt[i] >> 1)
                ans[id] ^= (1 << (b + 4));
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


