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

int n, m, q;
int fr[N], to[N], cost[N], rej[N];
int qf[N], qt[N], ql[N], qr[N], ans[N];
int d[N][31];

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
        else
            vm.pb(x);
    forn(s, 1, n) {
        forn(i, 1, n)
            d[mid][i] = (i == s ? 0 : INF);
        forn(i, mid, r) {
            forn(j, 1, n)
                d[i + 1][j] = d[i][j] + rej[i];
            d[i + 1][to[i]] = min(d[i + 1][to[i]], d[i][fr[i]] + cost[i]);
            d[i + 1][fr[i]] = min(d[i + 1][fr[i]], d[i][to[i]] + cost[i]);
        }
        for1(i, mid, l) {
            forn(j, 1, n)
                d[i - 1][j] = d[i][j] + rej[i - 1];
            d[i - 1][to[i - 1]] = min(d[i - 1][to[i - 1]], d[i][fr[i - 1]] + cost[i - 1]);
            d[i - 1][fr[i - 1]] = min(d[i - 1][fr[i - 1]], d[i][to[i - 1]] + cost[i - 1]);
        }
        for (auto x : vm)
            ans[x] = min(ans[x], d[ql[x]][qf[x]] + q[qr[x]][qt[x]]);
    }
    solve(1, mid - 1, vl);
    solve(mid + 1, r, vr);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
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
        cout << ans[i] << "\n";

        forn(j, 1, n)
            d[l][j] = (j == qf ? 0 : INF);
        forn(j, l, r) {
            forn(k, 1, n)
                d[j + 1][k] = d[j][k] + rej[j];
            d[j + 1][to[j]] = min(d[j + 1][to[j]], d[j][fr[j]] + cost[j]);
            d[j + 1][fr[j]] = min(d[j + 1][fr[j]], d[j][to[j]] + cost[j]);
        }
        cout << (d[r + 1][qt] >= INF ? -1 : d[r + 1][qt]) << "\n";
    }


    return 0;
}
