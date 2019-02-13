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
            forn(j, 0, 7)
                if (a[i] & (1 << j))
                    send((j << 5) | i);
        }
    }

    int cnt[(1 << 8)];

    void decode(int n, int l, int x[]) {
        vi ans(n);
        forn(i, 0, l - 1) {
            int b = (x[i] >> 5), id = (x[i] % 32);
            ans[id] |= (1 << b);
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


