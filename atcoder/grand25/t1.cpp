#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k;
pii a[N];
vector <pii> g[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vi v;
	cin >> n >> k;
	forn(i, 1, n) {
	    cin >> a[i].x >> a[i].y;
	    v.pb(a[i].x + a[i].y);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 1, n)
	    g[lower_bound(v.begin(), v.end(), a[i].x + a[i].y) - v.begin()].pb(a[i]);
    forn(i, 0, v.size() - 1)
        sort(g[i].begin(), g[i].end(), greater <pii> ());
    sort(a + 1, a + 1 + n);

    vi vx;
    forn(i, 1, n) vx.pb(a[i].x);
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

    ll sum = 0;
    set <pii> sl, sr;
    forn(i, 1, n) {
        sr.insert({a[i].x + a[i].y, i});
        sum += a[i].x - a[1].x + a[i].y
        while (sr.size() > k) sr.erase(sr.rbegin());
    }
    int ptr = 1;
    int p1 = 0;
    forn(i, 1, vx.size() - 1) {
        for (; ptr <= n && a[ptr].x == vx[i - 1]; ++ptr) {
            sum -= a[i].x - vx[i - 1] + a[i].y;
            sr.erase({a[i].x + a[i].y, i});
            sum += vx[i] - a[i].x + a[i].y;
            sl.erase({-a[i].x + a[i].y, i});
        }
        for (;;) {

            pl = max(pl, lower_bound(v.begin(), v.end(), vx[i]) - v.begin());
            for (auto p : v[pl]) {
                if (p.x < vx[i]) break;
            }
        }
    }

    return 0;
}
