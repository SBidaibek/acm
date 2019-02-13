#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <ll> ans(n + 1);
    vector <pii> a(n + 1);
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    forn(i, 1, m) {
        int u, v;
        cin >> u >> v;
        ll mx = min(a[u].x + a[v].y, a[u].y + a[v].x);
        ans[u] -= mx;
        ans[v] -= mx;
    }
    vector <pii> v;
    forn(i, 1, n)
        v.pb({a[i].x - a[i].y, i});
    sort(v.begin(), v.end());
    vi v2i(n + 1);
    vi sx(n + 1), sy(n + 1);
    forn(i, 1, n)
        v2i[v[i - 1].second] = i;
    forn(i, 1, n) {
        sx[i] = sx[i - 1] + a[v[i - 1].second].x;
        sy[i] = sy[i - 1] + a[v[i - 1].second].y;
    }
    forn(i, 1, n) {
        ans[i] += 1ll * a[i].y * (v2i[i] - 1) + sx[v2i[i] - 1];
        ans[i] += 1ll * a[i].x * (n - v2i[i]) + (sy[n] - sy[v2i[i]]);
    }
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}

