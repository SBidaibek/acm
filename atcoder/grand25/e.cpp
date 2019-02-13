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
    assert(m == q.size());
    vi o;
    dorder(1, -1, o);
    if (o.size() == 1) {
        assert(m == 0);
        return;
    }
    int x = o.back();
    cerr << x << "\n";
    del[x] = 1;
    int p = 0, pe = 0;
    for (auto e : g[x])
        if (!del[e.F]) p = e.F, pe = e.S;
    assert(p);
    vi epos;
    int sh = -1;
    forn(i, 0, m - 1) {
        if (min(q[i].F, q[i].S) == min(x, p) && max(x, p) == max(q[i].F, q[i].S))
            sh = i;
        if (x == q[i].F || x == q[i].S)
            if (epos.size() < 2) epos.pb(i);
    }
    if (epos.size() == 0) {
        solve();
        return;
    }
    if (epos.size() == 1) {
        if (sh != -1) {
            pii save = q[sh];
            q.erase(q.begin() + sh);
            --m;
            solve();
            ++m;
            for1(i, m - 1, sh + 1) ans[i] = ans[i - 1];
            ans[sh] = 0;
            q.insert(q.begin() + sh, save);
            return;
        }
        if (q[epos[0]].F == x) {
            q[epos[0]].F = p;
            solve();
            q[epos[0]].F = x;
        }
        else {
            q[epos[0]].S = p;
            solve();
            q[epos[0]].S = x;
        }
        return;
    }
    if (sh != -1) {
        pii save = q[sh];
        q.erase(q.begin() + sh);
        --m;
        solve();
        ++m;
        q.insert(q.begin() + sh, save);
        for1(i, m - 1, sh + 1)
            ans[i] = ans[i - 1];
        int lng = epos[0];
        if (lng  == sh) lng  = epos[1];
        bool in = (q[lng].S == x) ^ (ans[lng]);
        ans[sh] = (q[sh].F == x) ^ in;
        return;
    }
    int a = epos[0], b = epos[1];
    int y = q[a].F != x ? q[a].F : q[a].S;
    int z = q[b].F != x ? q[b].F : q[b].S;
    if (q[a].F == x) q[a].F = z; else q[a].S = z;
    pii save = q[b];
    q.erase(q.begin() + b);
    --m;
    solve();
    ++m;
    bool dir = ans[a];
    q.insert(q.begin() + b, save);
    for1(i, m - 1, b + 1)
        ans[i] = ans[i - 1];
    ans[a] = (q[a].S != x) ^ dir;
    ans[b] = (q[b].F != x) ^ dir;
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
