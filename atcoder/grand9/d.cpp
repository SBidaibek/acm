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
vi g[N];
int c[N][21];

void dfs(int x, int p = -1) {
    for (auto to : g[x]) {
        if (to == p) continue;
        dfs(to, x);
        forn(i, 0, 20) c[x][i] += c[to][i];
    }
    int y = 21;
    for1(i, 20, 0) {
        if (c[x][i] > 1) break;
        if (!c[x][i]) y = i;
    }
    ++c[x][y];
    for1(i, y - 1, 0) c[x][i] = 0;
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
    int ans = 0;
    forn(i, 0, 20)
        if (c[1][i]) ans = i;
    cout << ans << "\n";

    return 0;
}
