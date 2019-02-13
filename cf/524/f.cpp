#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 1e6 + 10;
const int INF = 1e9 + 9;

int zip(int x, vi &v) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

vector <pii> a[N], up[N];
vector <vi> Q[N];

int t[N];
int n;

void upd(int x, int v) {
    t[x += n - 1] = v;
    for (x >>= 1; x > 0; x >>= 1)
        t[x] = min(t[x * 2], t[x * 2 + 1]);
}

int get(int l, int r) {
    int ans = INF;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ans = min(ans, t[l++]);
        if (!(r & 1)) ans = min(ans, t[r--]);
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int m, k;
    cin >> n >> m >> k;
    forn(i, 1, k) {
        int l, r, p;
        cin >> l >> r >> p;
        a[p].pb({l, r});
    }
    vi v;
    forn(i, 1, n) {
        sort(a[i].begin(), a[i].end());
        vector <pii> cl;
        for (auto p : a[i]) {
            while (cl.size() && p.S <= cl.back().S)
                cl.pop_back();
            cl.pb(p);
        }
        a[i] = cl;
        for (auto p : a[i])
            v.pb(p.F), v.pb(p.S);
    }

    vector <vi> qtmp;
    forn(i, 1, m) {
        int l, r, vl, vr;
        cin >> l >> r >> vl >> vr;
        qtmp.pb({l, r, vl, vr, i});
        v.pb(vl), v.pb(vr);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 1, n)
        for (auto &p : a[i]) {
            p.F = zip(p.F, v), p.S = zip(p.S, v);
            up[p.S].pb({i, p.F});
        }
    for (auto qv : qtmp) {
        int l = qv[0], r = qv[1], vl = zip(qv[2], v), vr = zip(qv[3], v);
        Q[vr].pb({l, r, vl, qv.back()});
    }

    forn(i, 1, n)
        upd(i, -1);
    string ans[m + 1];
    forn(it, 1, v.size()) {
        for (auto u : up[it])
            upd(u.F, u.S);
        for (auto q : Q[it]) {
            ans[q[3]] = (get(q[0], q[1]) >= q[2]) ? "yes" : "no";
        }
    }

    forn(i, 1, m)
        cout << ans[i] << "\n";

    return 0;
}
