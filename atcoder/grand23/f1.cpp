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
typedef vector <ll> vi;

const int N = 3e5 + 1;
const int B = 1e9 + 7;

int n;
vi g[N];
int a[N], p[N];
int tin[N], tout[N], timer;

bool anc(int q, int w) {
    if (tin[q] > tin[w]) swap(q, w);
    return tin[q] <= tin[w] && tout[w] <= tout[q];
}

vi ord;

int dfs(int x) {
    tin[x] = ++timer;
    ord.pb(x);
    for (auto to : g[x])
        dfs(to);
    tout[x] = timer;
    cerr << x << ": " << tin[x] << " " << tout[x] << "\n";
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 2, n) {
        cin >> p[i];
        g[p[i]].pb(i);
    //    g[i].pb(p[i]);
    }
    forn(i, 1, n)
        cin >> a[i];
    ll INF = 1ll * n * (n - 1) / 2;

    dfs(1);
    for (int upd = 1; upd;) {
        for (auto x : ord) cerr << x << " ";cerr << "\n";
        upd = 0;
        forn(i, 1, ord.size() - 1) {
            for1(j, i - 1, 0) {
                if (anc(ord[j], ord[i])) break;
                if (a[ord[j]] > a[ord[i]]) {
                    cerr << ord[j] << " " << ord[i] << "\n";
                    for1(k, i, j + 1)
                        swap(ord[k - 1], ord[k]);
                    upd = 1;
                    cerr << ord[j] << " " << ord[i] << "\n";
                    break;
                }
            }
        }
    }

    ll ans = 0, bal = 0;
    for (auto x : ord)
        if (a[x] == 0) ans += bal; else ++bal;
    cout << ans << "\n";

    return 0;
}
