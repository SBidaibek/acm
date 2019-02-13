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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
int sz[N];
vi g[N];

int dfs(int x, int p = -1) {
    sz[x] = 1;
    for (auto to : g[x])
        if (to != p)
            sz[x] += dfs(to, x);
    return sz[x];
}

void fc(int x, int s, int &c, int p = -1) {
    for (auto to : g[x])
        if (to != p) fc(to, s, c, x);
    if (sz[x] * 2 >= s && c == 0) c = x;
}

ll d[N];

ll dp(int x, int p = -1) {
    ll ans = 0, cur = 1, sum = 0;
    for (auto to : g[x]) {
        if (to == p) continue;
        ans += dp(to, x);
        ans += cur * (d[to] + sz[to]) + sz[to] * sum;
        sum += (d[to] + sz[to]), cur += sz[to];
        d[x] += d[to] + sz[to];
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    ll ans = 0;
    vi v;
    forn(i, 1, n) {
        if (sz[i]) continue;
        int c = 0;
        fc(i, dfs(i), c);
        dfs(c);
        ans += dp(c);
        ans += (n - sz[c]) * d[c];
        v.pb(sz[c]);
    }
    if (v.size() > 1) {
        sort(v.begin(), v.end());
        ll sum = v[0];
        forn(i, 1, v.size() - 2) {
            ans += 2 * v[i] * sum;
            sum += v[i];
        }
        ans += v.back() * sum;
    }
    cout << ans << "\n";

    return 0;

}
