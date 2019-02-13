#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef pair <ld, ld> pnt;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, a[N], q[N], u[N];
bool d[N], b[N];
bool ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int s = 0;
    forn(i, 1, n) {
        cin >> a[i];
        s += a[i];
    }
    sort(a + 1, a + 1 + n);
    //n = unique(a + 1, a + 1 + n) - a - 1;
    cin >> m;
    vector <pii> v;
    forn(i, 1, m) {
        cin >> q[i];
        v.pb({q[i], i});
    }
    sort(v.begin(), v.end());
    int p = 0;
    d[0] = 1;
    forn(i, 1, n) {
        s += a[i];
        for (; p < v.size() && v[p].F < a[i]; ++p)
            ans[v[p].S] = d[v[p].F % a[1]];
        forn(j, 0, a[1] - 1) {
            if (u[j] == i) continue;
            int f = 0;
            vi t;
            for (int x = j; u[x] != i; x = (x + a[i]) % a[1]) {
                u[x] = i;
                f |= d[x];
                t.pb(x);
            }
            if (f)
                for (auto x : t)
                    d[x] = 1;
        }
    }
    for (; p < v.size(); ++p)
        ans[v[p].S] = d[v[p].F % a[1]];
    ll l = 1;
    forn(i, 1, m)
        cout << (ans[i] ? "YES\n" : "NO\n");

    return 0;
}
