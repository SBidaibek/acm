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

int n;
vi o;
int ptr;
vi g[N];

void dfs(int x, int p = -1) {
    o.pb(x);
    for (auto to : g[x]) {
        if (to == p) continue;
        dfs(to, x);
    }
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

int q(pii a) {
    if (a.x > 0 && a.y >= 0) return 1;
    if (a.x <= 0 && a.y > 0) return 2;
    if (a.x < 0 && a.y <= 0) return 3;
    return 4;
}

bool cmp(pii a, pii b) {
    if (q(a) != q(b)) return q(a) < q(b);
    return cp(a, b) > 0;
}

int ans[N];
pii a[N];
map <pii, int> p2i;
int u[N];

void dfs(int p) {
    u[p] = 1;
    int mn = 0;
    forn(i, 1, n) {

    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    dfs(1);
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        assert(p2i.count(a[i]) == 0);
        p2i[a[i]] = i;
    }
    sort(a + 1, a + 1 + n);
    pii s = a[1];
    for1(i, n, 1)
        a[i].x -= s.x, a[i].y -= s.y;
    sort(a + 2, a + 1 + n, [](pii v, pii u) {
        return cp(v, u) > 0;
    });
    for1(i, n, 1)
        a[i].x += s.x, a[i].y += s.y;
    forn(i, 1, n)
        ans[o[i - 1]] = p2i[a[i]];
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}

