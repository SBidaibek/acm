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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];

int dfs(int x) {
    if (!g[x].size()) return 0;
    vi v;
    for (auto to : g[x])
        v.pb(dfs(to));
    sort(v.begin(), v.end(), greater <int> ());
    int ans = 0;
    forn(i, 1, v.size())
        ans = max(ans, v[i - 1] + i);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 2, n) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    cout << dfs(1) << "\n";

    return 0;
}
