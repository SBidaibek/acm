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

int n, m;
vi g[N];
int u[N], in[N], cnt[N], p[N], d[N];

int dp(int x) {
    if (u[x]) return d[x];
    u[x] = 1;
    set <int> st;
    for (auto to : g[x]) {
        d[x] = max(d[x], dp(to) + 1);
        st.insert(dp(to));
        if (st.size() > 2) st.erase(st.begin());
    }
    if (++cnt[d[x]] == 1) p[d[x]] = -1;
    for (auto to : g[x])
        if (d[to] == d[x] - 1)
            if (st.size() > 1) p[d[to]] = max(p[d[to]], *st.begin());
    return d[x];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        ++in[t];
    }

    forn(i, 1, n)
        if (!in[i]) dp(i);
    int mx = 0;
    forn(i, 1, n)
        mx = max(mx, d[i]);
    int ans = 0;
    forn(i, 0, mx) {
        if (cnt[i] != 1) continue;
        int cur = min(i, mx - i) + 1;
        if (p[i] > -1) cur = min(cur, i - p[i]);
        ans = max(ans, cur);
    }
    cout << mx - ans << "\n";

    return 0;
}
