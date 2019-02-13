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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k;
vector <pii> g[N];
int dep[N], d[N], up[N], bat[N];

void build(int x, int p) {
    dep[x] = 0;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        build(to, x);
        dep[x] = max(dep[x], dep[to] + e.S);
    }
}

void calc(int x, int p) {
    multiset <int> st;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        st.insert(dep[to] + e.S);
    }
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        st.erase(st.find(dep[to] + e.S));
        bat[to] = st.size() ? *st.rbegin() : 0;
        up[to] = max(bat[to], up[x]) + e.S;
        st.insert(dep[to] + e.S);
        calc(to, x);
    }
}

bool found = 0;

void dfs(int x, int rad, int p) {
    d[x] = INF;
    if (dep[x] <= rad) d[x] = 1;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        dfs(to, rad, x);
        if (bat[to] <= rad)
            d[x] = min(d[x], d[to] + 1);
    }
    if (up[x] <= rad) {
        if (d[x] <= k) found = 1;
        int cnt = 0, sum = 0;
        for (auto e : g[x]) {
            int to = e.F;
            if (to == p) continue;
            if (dep[to] + e.S > rad) {
                ++cnt;
                sum += d[to];
            }
        }
        if (cnt <= 2 && sum <= k - 1) found = 1;
    }
}

bool ok(int rad) {
    found = 0;
    dfs(1, rad, -1);
    return found;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n - 1) {
        int f, t, w;
        cin >> f >> t >> w;
        g[f].pb({t, w});
        g[t].pb({f, w});
    }
    build(1, -1);
    calc(1, -1);
//    forn(i, 1, n) {
//        cerr << i << ": " << dep[i] << " " << bat[i] << " " << up[i] << "\n";
//    }

    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (!ok(m)) l = m + 1;
        else r = m;
    }
    cout << l << "\n";

    return 0;
}
