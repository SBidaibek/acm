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

int n, m;
vector <pii> q, g[N];
int ans[N];
int del[N], cov[N];

bool dfind(int x, int goal, int p) {
    if (x == goal) return 1;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        if (dfind(to, goal, x)) {
            ++cov[e.S];
            return 1;
        }
    }
    return 0;
}

void dorder(int x, int p, vi &v) {
    if (del[x]) return;
    v.pb(x);
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        dorder(to, x, v);
    }
}

void solve() {
    vi o;
    dorder(1, -1, o);
    if (o.size() == 1) {
        assert(q.size() == 0);
        return;
    }
    int x = o.back();
    cerr << x << "\n";
    del[x] = 1;
    int p = 0, pe = 0;
    for (auto e : g[x])
        if (!del[e.F]) p = e.F, pe = e.S;
    assert(p);
    vi lng, sh;
    forn(i, 0, m - 1) {
        if (x == q[i].F || x == q[i].S)
            if (p == q[i].F || p == q[i].S) sh.pb(i);
            else lng.pb(i);
    }
    if (sh.size() + lng.size() == 0) {
        solve();
        return;
    }

    if (sh.size() + lng.size() == 1) {
        for (auto w : sh) {
            q.erase(q.begin() + w);
            solve();
            for1(i, q.size() - 1, w + 1) ans[i] = ans[i - 1];
            ans[w] = 0;
            q.insert(q.begin() + w, {x, p});///????
        }
        for (auto w : lng) {
            if (q[w].F == x) q[w].S = p;
            else q[w].F = p;
            solve();
            if (q[w].F == p) q[w].S = x;
            else q[w].F = x;
        }
        return;
    }

    if (sh.size()) {
        forn(i, 0, sh.size() - 1)
            q.erase(q.begin() + sh[i]);
        forn(i, 2, lng.size() - 1) {
            int w = lng[i];
            if (q[w].F == x) q[w].S = p;
            else q[w].F = p;
        }
        solve();
        forn(i, 2, lng.size() - 1) {
            int w = lng[i];
            if (q[w].F == p) q[w].S = x;
            else q[w].F = x;
        }
        forn(i, 0, sh.size() - 1) {
            q.insert(q.begin() + sh[i], i % 2 ? {x, p} : {p, x});
            for1(i, q.size() - 1, sh[i] + 1)
                ans[i] = ans[i - 1];
            ans[sh[i]] = 0;
        }
        if (sh.size() == 1)
            ans[sh[0]] = (q[lng[0]].S == x) ^ (ans[lng[0]]);
        return;
    }
    int a = lng[0], b = lng[1];
    int y = q[a].F != x ? q[a].F : q[a].S;
    int z = q[b].F != x ? q[b].F : q[b].S;
    q[a] = {y, z};
    q.erase(q.begin() + b);
    forn(i, 2, lng.size() - 1) {
        int w = lng[i];
        if (q[w].F == x) q[w].S = p;
        else q[w].F = p;
    }
    solve();
    forn(i, 2, lng.size() - 1) {
        int w = lng[i];
        if (q[w].F == p) q[w].S = x;
        else q[w].F = x;
    }
    bool dir = (q[a].s == z) ^ ans[a];
    q.insert(q.begin() + b, save);
    for1(i, m - 1, b + 1)
        ans[i] = ans[i - 1];

    return;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb({t, i});
        g[t].pb({f, i});
    }
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        q.pb({f, t});
        dfind(f, t, -1);
    }

    solve();

    int ans_c = 0;
    forn(i, 1, n = 1)
        ans_c += min(cov[i], 2);
    cout << ans_c << "\n";
    forn(i, 0, m - 1) {
        if (ans[i]) swap(q[i].F, q[i].S);
        cout << q[i].F << " " << q[i].S << "\n";
    }

    return 0;
}
