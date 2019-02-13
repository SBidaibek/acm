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
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, q;
int a[N], b[N], ans[N];
pii c[N];
int v[N], sz;
vi g[N];
int d[N];

int dfs(int x) {
    d[x] = 1;
    for (auto to : g[x])
        d[x] = max(d[x], dfs(to) + 1);
    int p = lower_bound(c + 1, c + 1 + q, pii(a[x], 0)) - c;
    ans[c[p].S] = max(ans[c[p].S], d[x]);
    return d[x];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n >> q;
    scanf("%d%d", &n, &q);
    forn(i, 1, n)
        scanf("%d", &a[i]);
        //cin >> a[i];
    forn(i, 1, q) {
        scanf("%d", &b[i]);
        //cin >> b[i];
        c[i] = {b[i], i};
        ans[i] = 1;
    }
    sort(c + 1, c + 1 + q);

    a[0] = INF;
    forn(i, 1, n) {
        while (a[v[sz]] <= a[i]) --sz;
        g[v[sz]].pb(i);
        v[++sz] = i;
    }
    dfs(0);
    forn(i, 2, q)
        ans[c[i].S] = max(ans[c[i].S], ans[c[i - 1].S]);
    forn(i, 1, q)
        cout << ans[i] << " ";

    return 0;
}
