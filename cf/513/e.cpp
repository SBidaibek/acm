#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vi g[N];
int lvl[N];
ll so[N], se[N];
ll co[N], ce[N];
vi v[N];

ll dfs(int x, int p) {
    ll ans = 0;
    v[x].pb(x);
    ++ce[x];
    for (auto to : g[x]) {
        if (to == p) continue;
        lvl[to] = lvl[x] + 1;
        ans += dfs(to, x);
        if (v[x].size() > v[to].size()) {
            for (auto y : v[to]) {
                int d = (lvl[y] - lvl[x]);
                if (d % 2 == 0) {
                    ans += ce[x] * (d / 2) + se[x];
                    ans += co[x] * (d / 2) + co[x] + so[x];
                }
                else {
                    ans += ce[x] * (d / 2) + ce[x] + se[x];
                    ans += co[x] * (d / 2) + co[x] + so[x];
                }
                v[x].pb(y);
            }
            se[x] += so[to] + co[to];
            ce[x] += co[to];
            so[x] += se[to];
            co[x] += ce[to];
        }
        else {
            for (auto y : v[x]) {
                int d = (lvl[y] - lvl[x] + 1);
                if (d % 2 == 0) {
                    ans += ce[to] * (d / 2) + se[to];
                    ans += co[to] * (d / 2) + co[to] + so[to];
                }
                else {
                    ans += ce[to] * (d / 2) + ce[to] + se[to];
                    ans += co[to] * (d / 2) + co[to] + so[to];
                }
                v[to].pb(y);
            }
            swap(v[x], v[to]);
            se[x] += so[to] + co[to];
            ce[x] += co[to];
            so[x] += se[to];
            co[x] += ce[to];
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    cout << dfs(1, -1) << "\n";

    return 0;
}

