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
vi g[N];
int sz[N];

int dfs(int x, int p = -1) {
    sz[x] = 1;
    for (auto to : g[x]) {
        if (to == p) continue;
        sz[x] += dfs(to, x);
    }
    return sz[x];
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

pii operator - (pii a, pii b) {
    return {a.x - b.x, a.y - b.y};
}

int ans[N];
pii a[N];
int used[N];

pii refp;

bool cmp(int x, int y) {
    return cp(a[x] - refp, a[y] - refp) > 0;
}

void solve(int p, int x, int pr, vi v) {
    ans[x] = p;
    vi t;
    refp = a[p];
    sort(v.begin(), v.end(), cmp);
    //cerr << p << " " << x << ": ";
    //for (auto y : v) cerr << y << " ";
    //cerr << "\n";
    int ptr = 0;
    if (g[x][ptr] == pr) ++ptr;
    for (auto i : v) {
        int to = g[x][ptr];
        t.pb(i);
        if (t.size() == sz[to]) {
            t.pop_back();
            solve(i, to, x, t);
            t.clear();
            ++ptr;
            if (g[x][ptr] == pr) ++ptr;
        }
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
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    int s = 1;
    forn(i, 2, n)
        if (a[s] > a[i])
            s = i;
    vi v;
    forn(i, 1, n)
        if (i != s) v.pb(i);
    solve(s, 1, -1, v);
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}

