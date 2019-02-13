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

const int N = 2e4 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
vi g[N];
int u[N], in[N], cnt[N], d[N], id[N];
vi v[N];

int dp(int x) {
    if (u[x]) return d[x];
    u[x] = 1;
    for (auto to : g[x])
        d[x] = max(d[x], dp(to) + 1);
    return d[x];
}

int s[N];

int slow(int x, int del) {
    if (x == del) return -1;
    if (u[x]) return s[x];
    u[x] = 1;
    for (auto to : g[x])
        s[x] = max(s[x], slow(to, del) + 1);
    return s[x];
}

int good[N], p[N], len[N];

int fs(int x) {
    return p[x] == x ? x : p[x] = fs(p[x]);
}

vi q[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) p[i] = i;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        ++in[t];
        p[fs(f)] = fs(t);
    }

    forn(i, 1, n)
        if (!in[i]) dp(i);
    multiset <int> com;
    forn(i, 1, n)
        len[fs(i)] = max(len[fs(i)], d[i]);
    forn(i, 1, n) {
        if (fs(i) == i) com.insert(len[i]);
        q[fs(i)].pb(i);
    }
    int ans = *--com.end();
    forn(col, 1, n) {
        if (fs(col) != col) continue;
        if (q[col].size() == 1) continue;
        sort(q[col].begin(), q[col].end(), [](int x, int y) {return d[x] > d[y];});
        int mx = d[q[col][0]];
        for (auto x : q[col]) {
            if (d[x] == mx) good[x] = 1;
            if (!good[x]) continue;
            for (auto to : g[x]) if (d[to] == d[x] - 1) good[to] = 1;
        }
        for (auto x : q[col]) {
            if (good[x]) ++cnt[d[x]];
            for (auto to : g[x])
                if (d[to] < d[x] - 1)
                    v[d[x] - 1].pb(d[x] - d[to] - 1), v[d[to]].pb(-(d[x] - d[to] - 1));
        }
        int res = 0;
        multiset <int> st;
        for1(i, mx, 0) {
            for (auto x : v[i]) {
                if (x < 0) st.erase(st.find(-x));
                else st.insert(x);
            }
            if (cnt[i] != 1) continue;
            int cur = min(i, mx - i) + 1;
            if (st.size()) cur = min(cur, *st.begin());
            res = max(res, cur);
        }

        com.erase(com.find(mx));
        int cur = mx - res;
        if (com.size()) cur = max(cur, *--com.end());
        com.insert(mx);
        ans = min(ans, cur);

        for (auto x : q[col]) {
            cnt[d[x]] = 0;
            for (auto to : g[x])
                if (d[to] < d[x] - 1)
                    v[d[x] - 1].clear(), v[d[to]].clear();
        }
    }
    cout << ans << "\n";

    return 0;
}
