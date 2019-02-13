#include <bits/stdc++.h>
#include "bubblesort2.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef long double ld;

//const int N = 2e6 + 10;
const int INF = 1e9 + 19;
const int B = 1e9 + 7;

int slow_count(vi a) {
    int ans = 0;
    forn(i, 0, a.size() - 1) {
        int cur = 0;
        forn(j, 0, i - 1)
            if (a[j] <= a[i]) ++cur;
        ans = max(ans, i - cur);
    }
    return ans;
}

vi count_scans(vi a, vi qp, vi qd) {
    int n = a.size(), q = qp.size();
    vi ans;
    forn(it, 0, q - 1) {

        a[qp[it]] = qd[it];
        ans.pb(slow_count(a));
    }
    return ans;
}

