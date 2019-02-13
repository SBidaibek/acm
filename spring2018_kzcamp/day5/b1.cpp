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

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

pii inter(const pii &a, const pii &b) {
    pii ans = {max(a.F, b.F), min(a.S, b.S)};
    return ans;
}

ostream & operator << (ostream &out, pii p) {
    out << "(" << p.F << " "<< p.S << ")";
    return out;
}

pii v1[N], v2[N];

int solve(int l, int r, pii *ans) {
    --l;
    int szans = 0;
    if (l == 0) {
        ans[szans++] = {1, r};
        return szans;
    }
    int sz1 = 0, sz2 = 0;
    forn(i, 1, r) {
        v1[sz1++] = {i, r / i};
        i += (r % i) / (r / i);
    }
    v1[sz1] = {r + 1, 0};
    forn(i, 1, l) {
        v2[sz2++] = {i, l / i};
        i += (l % i) / (l / i);
    }
    v2[sz2] = {l + 1, 0};

    int p2 = 0;
    forn(p1, 0, sz1 - 1) {
        for (; p2 < sz2 && v1[p1].S <= v2[p2].S; ++p2);
        if (p2 == sz2) {
            ans[szans++] = {l + 1, r};
            break;
        }
        for (; p2 < sz2 && v1[p1].F >= v2[p2 + 1].F; ++p2);
        if (p2 == sz2) {
            ans[szans++] = {l + 1, r};
            break;
        }
        for (; p2 + 1 < sz2 && v2[p2 + 1].F < v1[p1 + 1].F; ++p2)
            ans[szans++] = inter({v1[p1].F, v1[p1 + 1].F - 1}, {v2[p2].F, v2[p2 + 1].F - 1});
        if (v2[p2].F < v1[p1 + 1].F)
            ans[szans++] = inter({v1[p1].F, v1[p1 + 1].F - 1}, {v2[p2].F, v2[p2 + 1].F - 1});
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

        int ptr = 0;
        int ans = 1;
        forn(i, 0, sz1 - 1) {
            pii p = u1[i];
            for (; ptr < sz2 && u2[ptr].S < p.F; ++ptr);
            if (ptr == sz2) break;
            for (; ptr < sz2 - 1 && u2[ptr + 1].F <= p.S; ++ptr)
                ans = max(ans, min(p.S, u2[ptr].S));
            if (u2[ptr].F <= p.S)
                ans = max(ans, min(p.S, u2[ptr].S));
        }
        cout << ans << "\n";
    }

    return 0;
}
