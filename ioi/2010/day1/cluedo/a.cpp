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

    void solve() {
        int a = 1, b = 1, c = 1;
        while (int r = Theory(a, b, c)) {
            if (r == 1) ++a;
            if (r == 2) ++b;
            if (r == 3) ++c;
        }
    }
}

void Solve() {
    kek :: solve();
}


