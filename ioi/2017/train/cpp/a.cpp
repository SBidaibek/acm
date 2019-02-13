#include <bits/stdc++.h>
#include "train.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 3e5 + 10;
const int K = 2e2;
const ll INF = 1e18 + 9;

vi g[N];

vi who_wins(vi a, vi r, vi fr, vi to) {
    int n = a.size(), m = fr.size();
    forn(i, 0, m - 1)
        g[fr[i]].pb(to[i]);
    vi ans(n + 1);
    for1(i, n - 1, 0) {
        bool loop = 0, nxt = 0;
        for (auto t : g[i])
            if (t == i) loop = 1;
            else nxt = 1;
        if (a[i]) {
            if (loop && r[i] == 1) ans[i] = 1;
            else if (nxt) ans[i] = ans[i + 1];
            else ans[i] = 0;
        }
        else {
            if (loop && r[i] == 0) ans[i] = 0;
            else if (nxt) ans[i] = ans[i + 1];
            else ans[i] = 1;
        }
    }
    ans.pop_back();
    return ans;
}
