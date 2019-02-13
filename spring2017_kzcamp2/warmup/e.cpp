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
vi g[N], v;
set <int> st;
int u[N];

void dfs(int x) {
    u[x] = 1;
    v.pb(x);
    int p = 0;
    vi d;
    for (auto to : st) {
        while (p < g[x].size() && to > g[x][p]) ++p;
        if (p < g[x].size() && to == g[x][p]) {
            ++p;
            continue;
        }
        d.pb(to);
    }
    for (auto to : d)
        st.erase(to);
    for (auto to : d)
        if (!u[to]) dfs(to);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    scanf("%d%d", &n, &m);
    forn(i, 1, m) {
        int f, t;
        scanf("%d%d", &f, &t);
        g[f].pb(t);
        g[t].pb(f);
    }
    vector <vi> ans;
    forn(i, 1, n) {
        st.insert(i);
        sort(g[i].begin(), g[i].end());
    }
    forn(i, 1, n) {
        if (u[i]) continue;
        st.erase(i);
        v.clear();
        dfs(i);
        ans.pb(v);
    }
    cout << ans.size() << "\n";
    for (auto w : ans) {
        cout << w.size() << " ";
        for (auto x : w) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
