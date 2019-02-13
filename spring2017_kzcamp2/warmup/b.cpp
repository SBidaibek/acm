#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
vector <int> g[N];
int u[N];

void dfs(int x) {
    u[x] = 1;
    for (auto to : g[x])
        if (!u[to]) dfs(to);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int all = 1;
    forn(i, 1, n) {
        int k, x;
        cin >> k;
        forn(j, 1, k) {
            cin >> x;
            g[i].pb(n + x);
            g[n + x].pb(i);
        }
        all &= (k == 0);
    }
    if (all) {
        cout << n << "\n";
        return 0;
    }

    int ans = -1;
    forn(i, 1, n) {
        if (u[i]) continue;
        ++ans;
        dfs(i);
    }
    cout << ans << "\n";

    return 0;
}
