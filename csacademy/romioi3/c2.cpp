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

const int N = 3e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, q;
int fr[N], to[N], cost[N], rej[N];
int qf[N], qt[N], ql[N], qr[N];
ll d[31], ans[N], sav[N];
vi Q[N];

void solve(int l, int r, vi &v) {
    if (!v.size()) return;
    int mid = (l + r) / 2;
    vi vl, vm, vr;
    for (auto x : v)
        if (qr[x] < mid)
            vl.pb(x);
        else
        if (ql[x] > mid)
            vr.pb(x);
        else {
            Q[ql[x]].pb(x);
            Q[qr[x] + 1].pb(x);
            vm.pb(x);
        }
    if (vm.size())
    forn(s, 1, n) {
        ll u = 0;
        forn(i, 1, n)
            d[i] = (i == s ? 0 : INF);
        for (auto x : Q[mid]) sav[x] += d[qf[x]];
        for1(i, mid - 1, l) {
            u += rej[i];
            ll nto = min(d[to[i]], d[fr[i]] - rej[i] + cost[i]);
            ll nfr = min(d[fr[i]], d[to[i]] - rej[i] + cost[i]);
            d[to[i]] = nto, d[fr[i]] = nfr;
            for (auto x : Q[i])
                sav[x] += d[qf[x]] + u;
        }
        u = 0;
        forn(i, 1, n)
            d[i] = (i == s ? 0 : INF);
        forn(i, mid, r) {
            u += rej[i];
            ll nto = min(d[to[i]], d[fr[i]] - rej[i] + cost[i]);
            ll nfr = min(d[fr[i]], d[to[i]] - rej[i] + cost[i]);
            d[to[i]] = nto, d[fr[i]] = nfr;
            for (auto x : Q[i + 1])
                sav[x] += d[qt[x]] + u;
        }
        for (auto x : vm) {
            ans[x] = min(ans[x], sav[x]);
            sav[x] = 0;
        }
    }
    forn(i, l, r + 1)
        Q[i].clear();
    solve(1, mid - 1, vl);
    solve(mid + 1, r, vr);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    forn(i, 1, m)
        cin >> fr[i] >> to[i] >> cost[i] >> rej[i];
    vi v;
    forn(i, 1, q) {
        cin >> qf[i] >> qt[i] >> ql[i] >> qr[i];
        ans[i] = INF;
        v.pb(i);
    }
    solve(1, m, v);
    forn(i, 1, q)
        cout << (ans[i] >= INF ? -1 : ans[i]) << "\n";

    return 0;
}
