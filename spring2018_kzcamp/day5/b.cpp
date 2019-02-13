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

const int N = 2e4 + 10;
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

vector <pii> solve(int l, int r) {
    --l;
    vector <pii> ans;
    if (l == 0) {
        ans.pb({1, r});
        return ans;
    }
    vector <pii> v1, v2;
    forn(i, 1, r) {
        v1.pb({i, r / i});
        i += (r % i) / (r / i);
    }
    int sz1 = v1.size();
    v1.pb({r + 1, 0});
    forn(i, 1, l) {
        v2.pb({i, l / i});
        i += (l % i) / (l / i);
    }
    int sz2 = v2.size();
    v2.pb({l + 1, 0});

//    for (auto p :v1) cerr << p << " ";cerr << sz1 << "\n";
//    for (auto p :v2) cerr << p << " ";cerr << sz2 << "\n";

    int p2 = 0;
    forn(p1, 0, sz1 - 1) {
        //cerr << p1 << " " << p2 << "\n";
        for (; p2 < sz2 && v1[p1].S <= v2[p2].S; ++p2);
        if (p2 == sz2) {
            ans.pb({l + 1, r});
            break;
        }
        for (; p2 < sz2 && v1[p1].F >= v2[p2 + 1].F; ++p2);
        if (p2 == sz2) {
            ans.pb({l + 1, r});
            break;
        }

        for (; p2 + 1 < sz2 && v2[p2 + 1].F < v1[p1 + 1].F; ++p2)
            ans.pb(inter({v1[p1].F, v1[p1 + 1].F - 1}, {v2[p2].F, v2[p2 + 1].F - 1}));
        if (v2[p2].F < v1[p1 + 1].F)
            ans.pb(inter({v1[p1].F, v1[p1 + 1].F - 1}, {v2[p2].F, v2[p2 + 1].F - 1}));
        if (p2 == sz2) {
            ans.pb({l + 1, r});
            break;
        }
    }
//    cerr << l << " " << r << "\n";
//    for (auto p :ans) cerr << p << " ";cerr << "\n";
//    vi c1, c2;
//    for (auto p : ans) forn(i, p.F, p.S) c1.pb(i);
//    forn(i, 1, r) if (r / i > l / i) c2.pb(i);
//    assert(c1 == c2);
    return ans;
}

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

        vector <pii> v2 = solve(ln, lx);
        vector <pii> v1 = solve(wn, wx);

        int ptr = 0;
        int ans = 1;
        //for (auto p :v1) cerr << p << " ";cerr <<  "\n";
        //for (auto p :v2) cerr << p << " ";cerr << "\n";
        for (auto p : v1) {
            for (; ptr < v2.size() && v2[ptr].S < p.F; ++ptr);
            if (ptr == v2.size()) break;

            //cerr << p << " " << v2[ptr] << " 1\n";
            for (; ptr < v2.size() - 1 && v2[ptr + 1].F <= p.S; ++ptr)
                ans = max(ans, min(p.S, v2[ptr].S));
            if (v2[ptr].F <= p.S)
                ans = max(ans, min(p.S, v2[ptr].S));
            //cerr << p << " " << v2[ptr] << " 2\n";
        }
//        int slow = 1;
//        forn(i, 1, min(wx, lx))
//            if (wx / i > (wn - 1) / i && (lx / i) > (ln - 1) / i) slow = i;
//        cerr << slow << " " << ans << "\n";
        //assert(slow == ans);
        cout << ans << "\n";
    }

    return 0;
}
