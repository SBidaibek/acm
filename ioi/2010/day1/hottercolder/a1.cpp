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
    typedef pair <ll, ll> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;

    int lst;
    int g(int x) {
        int ans = Guess(x);
        lst = x;
        return ans;
    }

    int bs(int n) {
        if (n == 1) return 1;
        if (n == 2) {
            g(1);
            return g(2) < 0 ? 1 : 2;
        }
        if (n == 3) {
            g(1);
            int x = g(3);
            return x == 0 ? 2 : x < 0 ? 1 : 3;
        }
        if (n == 4) {
            g(1);
            int x = g(3);
            return x == 0 ? 2 : x < 0 ? 1 : g(4) > 0 ? 4 : 3;
        }
        int l = 1, r = n;
        while (l < r) {
            if (l == r - 1) {
                if (lst == l)
                    return g(r) < 0 ? l : r;
                if (lst == r)
                    return g(l) < 0 ? r : l;
                if (lst == l - 1)
                    return g(r) == 0 ? l : r;
                if (lst == r + 1)
                    return g(l) == 0 ? r : l;
                assert(0);
            }
            if (l == r - 2) {
                g(l);
                int x = g(r);
                return x == 0 ? l + 1 : x < 0 ? l : r;
            }
            if (l == r - 3) {
                if (lst == l) {
                    int x = g(r - 1);
                    if (x == 0) return r - 2;
                    if (x < 0) return l;
                    return g(r) < 0 ? r - 1 : r;
                }
                if (lst == r + 1) {
                    int x = g(l);
                    if (x == 0) return r - 1;
                    if (x < 0) return r;
                    return g(l + 1) < 0 ? l : l + 1;
                }
                assert(0);
            }
            int m = (l + r) / 2;
            g(m);
            if (g(m + 1) < 0) r = m;
            else l = m + 1;
        }
        return l;
    }
}

int HC(int N) {
    return kek :: bs(N);
}


