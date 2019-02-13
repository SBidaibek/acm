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
ll d1[N][K], d2[N][K];
ll p1[N][K], p2[N][K], p3[N][K], p4[N][K];

void dfs(int x, int p = -1) {
    ll c = 0;
    for (auto to : g[x])
        if (to != p) c += a[to];
    d1[x][1] = c;
    d2[x][1] = c + (p > -1 ? a[p] : 0);
    forn(i, 2, k)
        d1[x][i] = d2[x][i] = -1e18;
    for (auto to : g[x]) {
        if (to != p) dfs(to, x);
        forn(i, 0, k) {
            ans = max(ans, d2[to][i] + p1[x][k - i]);
            ans = max(ans, p2[x][k - i] + d1[to][i]);
        }
        forn(i, 1, k) {
            d1[x][i] = max(d1[x][i], d1[to][i - 1] + c);
            d2[x][i] = max(d2[x][i], d2[to][i - 1] + (c - a[to] + (p > -1 ? a[p] : 0)));
            p1[x][i] = max(p1[x][i - 1], d1[x][i]);
            p2[x][i] = max(p2[x][i - 1], d2[x][i]);
         }
    }
    forn(i, 1, k) {
        ans = max(ans, d1[x][i] + (p > -1 ? a[p] : 0));
        ans = max(ans, d2[x][i]);
    }
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
    dfs(1);
    cout << ans << "\n";

    return 0;
}
