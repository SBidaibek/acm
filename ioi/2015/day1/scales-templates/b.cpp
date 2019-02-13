#include "scales.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e7 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

void init(int T) {
}

#define gmin getLightest
#define gmed getMedian
#define gmax getHeaviest
#define gub getNextLightest

void orderCoins() {
    int a[7];
    a[1] = gmin(1, 2, 3);
    a[2] = gmed(1, 2, 3);
    a[3] = 6 - a[1] - a[2];
    a[4] = gmin(4, 5, 6);
    a[5] = gmed(4, 5, 6);
    a[6] = 15 - a[4] - a[5];
    vi v = {a[1], a[2], a[3]};
    forn(i, 4, 6) {
        int p = gub(a[1], a[2], a[3], a[i]);
        if (p != a[1])
            v.insert(find(v.begin(), v.end(), p), a[i]);
        else {
            if (gmin(a[1], a[2], a[i]) == a[i])
                v.insert(find(v.begin(), v.end(), a[1]), a[i]);
            else
                v.push_back(a[i]);
        }
    }
    int res[6];
    forn(i, 0, 5)
        res[i] = v[i];
    answer(res);
}

#undef gmin
#undef gmed
#undef gmax
#undef gub
