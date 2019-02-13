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

int n;
int a[N], d[N];
vi g[N];
int c[N];

int dfs(int x, int p = -1) {
    if (g[x].size() == 1) {
        c[x] = 1;
        return a[x];
    }
    ll s = 0, mx = 0;
    for (auto to : g[x])
        if (to != p) {
            ll y = dfs(to, x);
            s += y, mx = max(mx, y);
            c[x] += c[to];
        }
    if (c[x] == 1) {
        if (s != a[x]) {
            cout << "NO\n";
            exit(0);
        }
    }
    else {
        if (s < a[x] || a[x] < s - a[x] || s < 2 * (s - a[x])) {
            cout << "NO\n";
            exit(0);
        }
        if (mx > s - mx && (s - a[x]) > (s - mx)) {
            cout << "NO\n";
            exit(0);
        }
    }
    return a[x] - (s - a[x]);
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
    if (n == 2) {
        cout << (a[1] == a[2] ? "YES\n" : "NO\n");
        return 0;
    }
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    queue <int> q;
    forn(i, 1, n)
        if (g[i].size() == 1) {
            d[i] = 1;
            q.push(i);
        }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto to : g[x]) {
            if (!d[to]) {
                d[to] = d[x] + 1;
                q.push(to);
            }
        }
    }
    int r = 1;
    forn(i, 2, n)
        if (d[r] < d[i]) r = i;
    cout << (dfs(r) == 0 ? "YES\n" : "NO\n");

    return 0;
}
