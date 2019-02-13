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
typedef vector <ll> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, m, q;
pii a[N];
int cx[N], cy[N];
vi vx[N], vy[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    forn(i, 1, q) {
        cin >> a[i].x >> a[i].y;
        ++cx[a[i].x], ++cy[a[i].y];
        vx[a[i].x].pb(i);
        vy[a[i].y].pb(i);
    }

    multiset <ll> sx, sy;
    forn(i, 1, n) sx.insert(cx[i]);
    forn(i, 1, m) sy.insert(cy[i]);

    ll ans = 0;
    forn(x, 1, n) {
        for (auto i : vx[x]) {
            sy.erase(sy.find(cy[a[i].y]));
            --cy[a[i].y];
            sy.insert(cy[a[i].y]);
        }
        ans = max(ans, cx[x] + *sy.rbegin());
        for (auto i : vx[x]) {
            sy.erase(sy.find(cy[a[i].y]));
            ++cy[a[i].y];
            sy.insert(cy[a[i].y]);
        }
    }

    cout << n + m - 1 - ans << "\n";

    return 0;
}
