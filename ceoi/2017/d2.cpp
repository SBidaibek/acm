#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ld li(pii p1, pii p2) {
    return (p2.S - p1.S) / ld(p1.F - p2.F);
}

struct ch {
    vector <pii> v;

    void build(vector <pii> &a) {
        sort(a.begin(), a.end(), greater <pii> ());
        for (auto p : a) {
            for (; v.size() > 1; v.pop_back())
                if (li(v[v.size() - 2], v[v.size() - 1]) < li(v[v.size() - 2], p))
                    break;
            v.pb(p);
        }
    }

    ll get(ll x) {
        if (v.size() == 1 || x <= li(v[0], v[1]))
            return v[0].F * x + v[0].S;
        int l = 1, r = v.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (x >= li(v[m - 1], v[m])) l = m;
            else r = m - 1;
        }
        return v[l].F * x + v[l].S;
    }
};

int n;
ll h[N], w[N], d[N];

ch t[N];

void add(int x) {
    vector <pii> a;
    for (int i = x + n - 1, len = 1, prv = x + 1; i; i /= 2, len *= 2) {
        int l = x - len + 1;
        forn(j, l, prv - 1)
            a.pb({-2 * h[j], (h[j] * h[j]) + d[j]});
        prv = l;
        t[i].build(a);
        if (i % 2 == 0) break;
    }
}

ll get(int x) {
    ll ans = 1e18;
    for (int l = n, r = n + x - 2; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans = min(ans, t[l++].get(h[x]));
        if (r % 2 == 0) ans = min(ans, t[r--].get(h[x]));
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> h[i];
    ll allw = 0;
    forn(i, 1, n) {
        cin >> w[i];
        allw += w[i];
    }

    d[1] = -w[1];
    add(1);
    forn(i, 2, n) {
//        d[i] = 1e18;
//        forn(j, 1, i - 1) {
//            ll x = -2 * h[j] * h[i] + (h[j] * h[j]) + d[j];
//            d[i] = min(d[i], x);
//        }
        d[i] = get(i);
        d[i] += -w[i] + (h[i] * h[i]);
        add(i);
    }

    cout << d[n] + allw << "\n";


    return 0;
}
