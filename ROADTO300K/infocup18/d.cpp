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

const int N = 5e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int a[N], d[N][2];

void dfs1(int x, int p = -1) {
    forn(k, 0, 1)
        d[x][k] = (a[x] == k ? 0 : INF);
    for (auto to : g[x]) {
        if (to == p) continue;
        dfs1(to, x);
        forn(k, 0, 1)
            d[x][k] = min(d[x][k], d[to][k] + 1);
    }
}

int ans;
int up[N][2];

void dfs2(int x, int p = -1) {
    ans = max(ans, min(d[x][a[x]], up[x][a[x]]));
    set <int> s[2];
    forn(k, 0, 1) s[k].insert(up[x][k]);
    for (auto to : g[x])
        if (to != p)
            forn(k, 0, 1)
                s[k].insert(d[to][k] + 1);
    for (auto to : g[x]) {
        if (to == p) continue;
        forn(k, 0, 1) {
            s[k].erase(d[to][k] + 1);
            up[to][k] = 1 + *s[k].begin();
            s[k].insert(d[to][k] + 1);
        }
        dfs2(to, x);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(it, 1, tests) {
        cin >> n;
        forn(i, 1, n) g[i].clear();
        forn(i, 1, n - 1) {
            int f, t;
            cin >> f >> t;
            g[f].pb(t);
            g[t].pb(f);
        }
        int cnt = 0;
        forn(i, 1, n) {
            cin >> a[i];
            if (a[i] == 1) ++cnt;
        }
        if (cnt == 1 || cnt == n - 1) {
            cout << "-1\n";
            continue;
        }
        dfs1(1);
        ans = 0;
        dfs2(1);
        cout << ans << "\n";
        forn(i, 1, n)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
