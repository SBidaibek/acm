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

int n, k;
vi g[N];
int ans = 0;

int dfs(int x, int p) {
    int mx = 0;
    for (auto to : g[x])
        mx = max(mx, dfs(to, x));
    if (x == 1) return 0;
    if (mx == k - 1) {
        if (p != 1) ++ans;
        return 0;
    }
    return mx + 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n) {
        int p;
        cin >> p;
        if (i == 1) {
            if (p != 1) ++ans;
            continue;
        }
        g[p].pb(i);
    }
    dfs(1, 1);
    cout << ans << "\n";

    return 0;
}
