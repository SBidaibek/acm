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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int v1[N], v2[N], b1[N], b2[N];

int solve(int l, int r, pii *ans) {
    --l;
    int szans = 0;
    if (l == 0) {
        ans[szans++] = {1, r};
        return szans;
    }
    int sz1 = 0, sz2 = 0;
    forn(i, 1, r) {
        b1[sz1] = r / i;
        v1[sz1++] = i;
        i += (r % i) / (r / i);
    }
    v1[sz1] = r + 1;
    forn(i, 1, l) {
        b2[sz2] = l / i;
        v2[sz2++] = i;
        i += (l % i) / (l / i);
    }
    v2[sz2] = l + 1;

    int p2 = 0;
    forn(p1, 0, sz1 - 1) {
        for (; p2 < sz2 && b1[p1] <= b2[p2]; ++p2);
        if (p2 == sz2) {
            ans[szans++] = {l + 1, r};
            break;
        }
        for (; p2 < sz2 && v1[p1] >= v2[p2 + 1]; ++p2);
        if (p2 == sz2) {
            ans[szans++] = {l + 1, r};
            break;
        }
        for (; p2 + 1 < sz2 && v2[p2 + 1] < v1[p1 + 1]; ++p2)
            ans[szans++] = pii(max(v1[p1], v2[p2]), min(v1[p1 + 1] - 1, v2[p2 + 1] - 1));
        if (v2[p2] < v1[p1 + 1])
            ans[szans++] = pii(max(v1[p1], v2[p2]), min(v1[p1 + 1] - 1, v2[p2 + 1] - 1));
        if (p2 == sz2) {
            ans[szans++] = {l + 1, r};
            break;
        }
    }
    return szans;
}

pii u1[N], u2[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(it, 1, ts) {
        int wn, wx, ln, lx;
        cin >> wn >> wx >> ln >> lx;

        int sz1 = solve(ln, lx, u1);
        int sz2 = solve(wn, wx, u2);

        int ptr = sz2 - 1;
        int ans = 1;
        for1(i, sz1 - 1, 0) {
            pii p = u1[i];
            for (; ptr >= 0 && u2[ptr].F > p.S; --ptr);
            if (u2[ptr].S >= p.F) {
                ans = min(u2[ptr].S, p.S);
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
