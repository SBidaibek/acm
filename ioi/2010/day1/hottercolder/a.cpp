#include <bits/stdc++.h>
#include "grader.h"
//#include "hottercolder.h"

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

    int lst;
    int g(int x) {
        return lst = Guess(x);
    }

    int bs(int n) {
        if (n == 1) return 1;
        g(1);
        if (g(n) <= 0) {
            g(1);
            if (g(2) < 0) return 1;
            int l = 2, r = n;
            while (l < r) {
                g(1);
                int m = (l + r) / 2;
                if (g(m) > 0) l = m + 1;
                else r = m;
            }
            {g(1);
            assert(g(l) == 0);}
            return (l + 1) / 2;
        }
        else {
            g(n);
            if (g(n - 1) < 0) return n;
            int l = 1, r = n - 1;
            while (l < r) {
                g(n);
                int m = (l + r + 1) / 2;
                if (g(m) > 0) r = m - 1;
                else l = m;
            }
            {g(n);
            assert(g(l) == 0);}
            return (l + n) / 2;
        }
    }
}

int HC(int N) {
    return kek :: bs(N);
}


