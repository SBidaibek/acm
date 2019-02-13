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

    const int N = 3e3 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;

    int n, m, r, c;
    int a[N][N], og[N][N];

    bool f(int x) {
        forn(i, 1, n) {
            forn(j, 1, m) {
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (og[i][j] <= x);
                if (i >= r && j >= c)
                    if ((a[i][j] - a[i - r][j] - a[i][j - c] + a[i - r][j - c]) * 2 >= r * c)
                       return 1;
            }
        }
        return 0;
    }

    int solve(int _n, int _m, int _r, int _c, int g[N][N]) {
        n = _n, m = _m, r = _r, c = _c;
        forn(i, 1, n)
            forn(j, 1, m)
                og[i][j] = g[i - 1][j - 1];
        int l = 1, r = n * m;
        while (l < r) {
            int m = (l + r) / 2;
            if (f(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
}

int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
	return kek :: solve(R, C, H, W, Q);
}



