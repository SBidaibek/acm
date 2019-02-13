#include <bits/stdc++.h>
#include "xylophone.h"

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

void detect_pitch(int n) {
    vi a(n), p(n);
    forn(i, 1, n - 1) {
        int d = ask(i - 1, i);
        bool ok = 1;
        a[i] = a[i - 1] + d;
        int mnp = min(a[i - 1], a[i - 1] + d), mxp = max(a[i - 1], a[i - 1] + d);
        int mnn = min(a[i - 1], a[i - 1] - d), mxn = max(a[i - 1], a[i - 1] - d);
        for1(j, i - 2, 0) {
            mnp = min(mnp, a[j]);
            mnn = min(mnn, a[j]);
            mxp = max(mxp, a[j]);
            mxn = max(mxn, a[j]);
            if (mxp - mnp != mxn - mnn) {
                if (mxp - mnp != ask(j, i))
                    ok = 0;
                break;
            }
        }
        if (!ok)
            a[i] = a[i - 1] - d;
    }
    int mn = 0;
    forn(i, 0, n - 1) mn = min(mn, a[i]);
    forn(i, 0, n - 1) a[i] += -mn;
    forn(i, 0, n - 1)
        p[a[i]] = i;
    if (p[0] > p[n - 1])
        forn(i, 0, n - 1)
            a[i] = n - 1 - a[i];
    forn(i, 0, n - 1)
        answer(i, a[i]);
}
