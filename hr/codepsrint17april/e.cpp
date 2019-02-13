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

const int N = 2e6 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int d[N][2];
vi g[N];
int n, a[N];

void cdp(int x, int p = -1) {
    d[x][1] = a[x];
    for (auto to : g[x]) {
        if (to == p) continue;
        cdp(to, x);
        int v = max(d[to][0], d[to][1]);
        d[x][0] = max(d[x][0], v);
        if (d[to][1] > 0) d[x][1] += d[to][1];
    }
}

ll ans = 0;

void dfs(int x, int p = -1) {
    ll s = a[x];
    multiset <int> st;
    for (auto to : g[x]) {
        int v = max(d[to][0], d[to][1]);
        if (v > 0) st.insert(v);
        if (d[to][1] > 0) s += d[to][1];
    }
    vi sav(2);
    sav[0] = d[x][0], sav[1] = d[x][1];
    for (auto to : g[x]) {
        if (to == p) continue;
        int v = max(d[to][0], d[to][1]);
        if (v > 0) st.erase(st.find(v));
        if (d[to][1] > 0) s -= d[to][1];
        d[x][0] = (st.size() ? *st.rbegin() : 0);
        d[x][1] = s;
        ans = max(ans, 1ll * d[x][0] * v);
        ans = max(ans, 1ll * d[x][1] * v);
        dfs(to, x);
        if (v > 0) st.insert(v);
        if (d[to][1] > 0) s += d[to][1];
    }
    d[x][0] = sav[0], d[x][1] = sav[1];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    cdp(1);
    dfs(1);
    memset(d, 0, sizeof d);
    forn(i, 1, n)
        a[i] *= -1;
    cdp(1);
    dfs(1);
    cout << ans << "\n";

    return 0;
}
