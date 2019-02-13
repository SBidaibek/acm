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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, k;
pii a[N];
map <pii, int> mp;
int u[N], l[N], r[N], d[N], t[N];

int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};

void dfs(int x) {
    l[u[x]] = min(l[u[x]], a[x].x);
    r[u[x]] = max(r[u[x]], a[x].x);
    d[u[x]] = min(d[u[x]], a[x].y);
    t[u[x]] = max(t[u[x]], a[x].y);
    forn(dr, 0, 3) {
        int i = a[x].x + di[dr];
        int j = a[x].y + dj[dr];
        if (mp.count({i, j}) == 0) continue;
        int to = mp[{i, j}];
        if (!u[to]) {
            u[to] = u[x];
            dfs(to);
        }
    }
}

int dist(int l1, int r1, int l2, int r2) {
    int x = max(1, max(l1, l2) - min(r1, r2));
    if (x <= 2) return 1;
    else return INF;
}

int D[N], used[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, k) {
        cin >> a[i].x >> a[i].y;
        mp[a[i]] = i;
    }
    vi v;
    int s = 0, f = 0;
    forn(i, 1, k) {
        if (u[i]) continue;
        u[i] = i;
        l[i] = m + 1, r[i] = 0;
        t[i] = 0, d[i] = n + 1;
        dfs(i);
        v.pb(i);
    }
    forn(i, 1, k) {
        if (a[i] == pii(1, 1))
            s = u[i];
        if (a[i] == pii(n, m))
            f = u[i];
    }
    for (auto x : v)
        if (x != s) D[x] = INF;
    forn(i, 1, v.size()) {
        int mn = -1;
        for (auto x : v)
            if (used[x] == 0 && (mn == -1 || D[mn] > D[x])) mn = x;
        if (D[mn] == INF) break;
        used[mn] = 1;
        for (auto x : v) {
            D[x] = min(D[x], D[mn] + dist(l[x], r[x], l[mn], r[mn]));
            D[x] = min(D[x], D[mn] + dist(d[x], t[x], d[mn], t[mn]));
        }
    }
    int ans = D[f];
    if (!f) {
        ans = INF;
        for (auto x : v) {
            if (r[x] >= n - 1) ans = min(ans, D[x] + 1);
            if (d[x] >= m - 1) ans = min(ans, D[x] + 1);
            //ans = min(ans, D[x] + dist(l[x], r[x], n, n));
            //ans = min(ans, D[x] + dist(d[x], t[x], m, m));
        }
    }
    if (ans >= INF) ans = -1;
    cout << ans << "\n";

    return 0;
}
