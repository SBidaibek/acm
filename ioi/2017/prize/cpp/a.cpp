#include <bits/stdc++.h>
#include "prize.h"

using namespace std;

#define forn(i, x, n) foor (int i = int(x); i <= int(n); ++i)
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
const int K = 447;

vi a[N];
int counter;

vi get(int x) {
    --x;
    if (a[x].size()) return a[x];
    if (++counter > 1e4) assert(0);
    a[x] = ask(x);
    return a[x];
}

int find_best(int n) {
    int mx = 0;
    forn(i, 1, K + 1) {
        vi v = get(i);
        mx = max(mx, v[0] + v[1]);
        if (v[0] + v[1] == 0) return (i - 1);
    }
    int cnt = 0;

    forn(i, 1, K + 1)
        if (get(i)[0] + get(i)[1] != mx) ++cnt;
    for (int i = K + 2; i <= n;) {
        for (;;++i) {
            vi v = get(i);
            if (v[0] + v[1] == 0) return (i - 1);
            else if (v[0] + v[1] < mx) ++cnt;
            else break;
        }
        int l = i, r = n;
        while (l < r) {
            int m = (l + r + 1) / 2;
            vi v = get(m);
            if (v[0] + v[1] == 0) return (m - 1);
            if (v[0] + v[1] == mx) {
                if (v[0] == cnt) l = m;
                else r = m - 1;
            }
            else
                r = m - 1;
        }
        i = l + 1;
    }
    assert(0);

	return 0;
}

