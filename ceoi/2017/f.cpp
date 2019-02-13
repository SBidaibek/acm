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
const int K = 101;

int n, k;
vi g[N];
ll ans, a[N];
ll d[N][K];

void dfs(int x, int p = -1) {
    ll c = 0;
    for (auto to : g[x])
        if (to != p) c += a[to];
    if (p == -1) {
        d[x][1] = c;
        forn(i, 2, k) d[x][i] = -1e18;
    }
    else
        forn(i, 1, k)
            d[x][i] = max(d[p][i], d[p][i - 1] + c);
    forn(i, 1, k)
        ans = max(ans, d[x][i]);
    for (auto to : g[x])
        if (to != p) dfs(to, x);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n) cin >> a[i];
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    forn(i, 1, (n <= 1000 ? n : 1))
        dfs(i);
    cout << ans << "\n";

    return 0;
}
