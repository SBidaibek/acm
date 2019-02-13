#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool get(vi q) {
    return isSubsequence(q);
}

int n;
int p[N];

vi findSequence(int _n) {
    n = _n;
    int b = 0;
    vi v;
    forn(i, 1, n / 2  + 1) v.pb(b);
    if (get(v)) b ^= 1;

    int len = n / 2;
    for (;len;--len) {
        v.clear();
        forn(i, 1, len) v.pb(b);
        if (get(v)) break;
    }

    if (len == 0) {
        v.clear();
        forn(i, 1, n) v.pb(b ^ 1);
        return v;
    }

    p[0] = -1;
    forn(i, 1, len) {
        for1(j, n - len, 0) {
            v.clear();
            forn(k, 1, i - 1) v.pb(b);
            forn(k, 1, j) v.pb(b ^ 1);
            forn(k, i, len) v.pb(b);
            if (get(v)) {
                p[i] = p[i - 1] + 1 + j;
                break;
            }
        }
    }

    v = vi(n, b ^ 1);
    forn(i, 1, len)
        v[p[i]] = b;
    return v;
}
//
//int main() {
//    #ifdef black
//    freopen("in", "r", stdin);
//    #endif // black
//    ios_base :: sync_with_stdio(0);
//    cin.tie(0);
//
//
//
//    return 0;
//}
