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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, k;
int d[N], pr[N];
vi g[N];

void dfs(int x) {
    for (auto to : g[x]) {
        if (to == pr[x]) continue;
        pr[to] = x;
        dfs(to);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, m)
        cin >> d[i];
    int h1, h2;
    cin >> h1 >> h2;
    forn(i, 2, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    dfs(h1), dfs(h2);
    g[h1].pb(h2);
    g[h2].pb(h1);

    ll ans = 0;
    forn(i, 1, n) {
        if (g[i].size() <= 1) {
            forn(j, 1, m) {
                int x = d[j];
                for (int v = i; v; v = pr[v]) {
                    x /= (g[v].size() - 1 + (v == i));
                    if (x < k) break;
                }
                if (x == k) ans += k;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
