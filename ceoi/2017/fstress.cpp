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
ll my, a[N];
ll d[N][K];

void og(int x, int p = -1) {
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
        my = max(my, d[x][i]);
    for (auto to : g[x])
        if (to != p) og(to, x);
}

ll ans, d1[N][K], d2[N][K];
ll p1[N][K], p2[N][K], p3[N][K];

void dfs(int x, int p = -1) {
    int pr = (p > -1 ? a[p] : 0);
    ll c = 0;
    for (auto to : g[x]) c += a[to];
    d1[x][1] = c - pr;
    d2[x][1] = c;
    //forn(i, 2, k)
    //    d1[x][i] = d2[x][i] = -1e18;
    for (auto to : g[x]) {
        if (to == p) continue;
        dfs(to, x);
        forn(i, 1, k) {
            ans = max(ans, d2[to][i] + p1[x][k - i] - a[to]);
            ans = max(ans, d2[to][i] + p2[x][k - i]);
            ans = max(ans, p3[x][k - i] + d1[to][i]);
        }
        forn(i, 1, k) {
            d1[x][i] = max(d1[x][i], d1[to][i]);
            d1[x][i] = max(d1[x][i], d1[to][i - 1] + (c - pr));
            d2[x][i] = max(d2[x][i], d2[to][i]);
            d2[x][i] = max(d2[x][i], d2[to][i - 1] + (c - a[to]));
            p1[x][i] = max(p1[x][i - 1], d1[to][i - 1] + c);
            p2[x][i] = max(p2[x][i - 1], d1[to][i]);
            p3[x][i] = max(p3[x][i - 1], d2[x][i]);
        }
    }
    ans = max(ans, p1[x][k]);
    ans = max(ans, p3[x][k]);
    //forn(i, 1, k) {
    //    ans = max(ans, d1[x][i] + pr);
    //    ans = max(ans, d2[x][i]);
    //}
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n >> k;
    forn(tc, 1, 1e2) {
    srand(tc);
    ans = my = 0;
    n = 5;
    k = rand() % n + 1;
    forn(i, 1, n) a[i] = rand() % 5;//cin >> a[i];
    vi ed(n + 1);
    forn(i, 2, n) {
        int f, t;
        f = rand() % (i - 1) + 1, t = i;
        ed[i] = f;
        //cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    forn(i, 1, (n <= 1000 ? n : 1))
        og(i);
    dfs(1);
    if (ans != my) {
        freopen("out", "w", stdout);
        cout << n << " " << k << "\n";
        forn(i, 1, n)
            cout << a[i] << " "; cout << "\n";
        forn(i, 2, n)
            cout << ed[i] << " " << i << "\n";
        cerr << ans << " " << my << "\n";
        return 0;
    }
    assert(my == ans);
    //cout << my << "\n";
    forn(i, 1, n) {
        g[i].clear();
        memset(d[i], 0, sizeof d[i]);
        memset(d1[i], 0, sizeof d1[i]);
        memset(d2[i], 0, sizeof d2[i]);
        memset(p1[i], 0, sizeof p1[i]);
        memset(p2[i], 0, sizeof p2[i]);
        memset(p3[i], 0, sizeof p3[i]);
    }
    }

    return 0;
}
