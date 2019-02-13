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

const int N = 2e4 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
vector <pii> q, g[N];
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

ostream & operator << (ostream &out, pii p) {
    return out << "(" << p.F << " " << p.S << ")";
}

void solve() {
    vi o;
    dorder(1, -1, o);
    int x = o.back();
    if (o.size() == 1) {
        assert(q.size() == 0);
        return;
    }
    del[x] = 1;
    int p = 0;
    for (auto e : g[x])
        if (!del[e.F]) p = e.F;
    assert(p);
    vi lng, sh;
    forn(i, 0, q.size() - 1) {
        if (x == q[i].F || x == q[i].S)
            if (p == q[i].F || p == q[i].S)
                sh.pb(i);
            else
                lng.pb(i);
    }
//    cerr << "in: " << x << " -> " << q.size() << "\n";
//    {for (auto w : sh) cerr << w << " ";cerr << "\n";}
//    {for (auto w : lng) cerr << w << " ";cerr << "\n";}
//    {for (auto w : q) cerr << w << " ";cerr << "\n";}
    if (sh.size() + lng.size() == 0) {
        solve();
//    cerr << "out: " << x << " -> " << q.size() << "\n";
//    {for (auto w : sh) cerr << w << " ";cerr << "\n";}
//    {for (auto w : lng) cerr << w << " ";cerr << "\n";}
//    {for (auto w : q) cerr << w << " ";cerr << "\n";}
        return;
    }

    if (sh.size() + lng.size() == 1) {
        for (auto w : sh) {
            q.erase(q.begin() + w);
            solve();
            q.insert(q.begin() + w, {x, p});///????
        }
        for (auto w : lng) {
            if (q[w].F == x) q[w].F = p;
            else q[w].S = p;
            solve();
            if (q[w].F == p) q[w].F = x;
            else q[w].S = x;
        }
//    cerr << "out: " << x << " -> " << q.size() << "\n";
//    {for (auto w : sh) cerr << w << " ";cerr << "\n";}
//    {for (auto w : lng) cerr << w << " ";cerr << "\n";}
//    {for (auto w : q) cerr << w << " ";cerr << "\n";}
        return;
    }

    if (sh.size()) {
        forn(i, 0, lng.size() - 1) {
            int w = lng[i];
            if (q[w].F == x) q[w].F = p;
            else q[w].S = p;
        }
        for1(i, sh.size() - 1, 0)
            q.erase(q.begin() + sh[i]);
        solve();
        forn(i, 0, sh.size() - 1)
            q.insert(q.begin() + sh[i], i % 2 ? pii(x, p) : pii(p, x));
        forn(i, 0, lng.size() - 1) {
            int w = lng[i];
            if (q[w].F == p) q[w].F = x;
            else q[w].S = x;
        }
        if (sh.size() == 1 && q[lng[0]].S == x)
            q[sh[0]] = {x, p};
//    cerr << "out: " << x << " -> " << q.size() << "\n";
//    {for (auto w : sh) cerr << w << " ";cerr << "\n";}
//    {for (auto w : lng) cerr << w << " ";cerr << "\n";}
//    {for (auto w : q) cerr << w << " ";cerr << "\n";}
        return;
    }

    forn(i, 2, lng.size() - 1) {
        int w = lng[i];
        if (q[w].F == x) q[w].F = p;
        else q[w].S = p;
    }
    int a = lng[0], b = lng[1];
    int y = q[a].F != x ? q[a].F : q[a].S;
    int z = q[b].F != x ? q[b].F : q[b].S;
    q.erase(q.begin() + b);
    if (y != z) q[a] = {y, z};
    else q.erase(q.begin() + a);
    solve();
    if (y == z) {
        q.insert(q.begin() + a, pii(y, x));
        q.insert(q.begin() + b, pii(x, y));
    }
    else {
        q.insert(q.begin() + b, q[a].S == z ? pii(x, z) : pii(z, x));
        if (q[a].F == z) q[a].F = x; else q[a].S = x;
    }
    forn(i, 2, lng.size() - 1) {
        int w = lng[i];
        if (q[w].F == p) q[w].F = x;
        else q[w].S = x;
    }
//    cerr << "out: " << x << " -> " << q.size() << "\n";
//    {for (auto w : sh) cerr << w << " ";cerr << "\n";}
//    {for (auto w : lng) cerr << w << " ";cerr << "\n";}
//    {for (auto w : q) cerr << w << " ";cerr << "\n";}
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
    forn(i, 1, n - 1)
        ans_c += min(cov[i], 2);
    cout << ans_c << "\n";
    forn(i, 0, m - 1)
        cout << q[i].F << " " << q[i].S << "\n";

    return 0;
}
