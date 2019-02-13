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

int n;
vi g[N];
ll d[N][2];
int c[N], p[N];

void dfs(int x, int pr = -1) {
    for (auto to : g[x])
        if (to != pr) dfs(to, x);
    forn(dad, 0, 1) {
        d[x][dad] = (c[x] - dad > 0 ? p[x] : 0);
        for (auto to : g[x])
            if (to != pr)
                d[x][dad] += d[to][1];
        if (c[x] - dad > g[x].size() - (pr != -1)) continue;
        vi v;
        ll sum = 0;
        for (auto to : g[x])
            if (to != pr) {
                v.pb(d[to][0] - d[to][1]);
                sum += d[to][1];
            }
        sort(v.begin(), v.end());
        v.resize(c[x] - dad);
        for (auto y : v)
            sum += y;
        d[x][dad] = min(d[x][dad], sum);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(_, 1, ts) {
        int n;
        cin >> n;
        forn(i, 1, n - 1) {
            int f, t;
            cin >> f >> t;
            g[f].pb(t);
            g[t].pb(f);
        }
        forn(i, 1, n)
            cin >> p[i];
        forn(i, 1, n)
            cin >> c[i];
        dfs(1);
        cout << d[1][0] << "\n";
        forn(i, 1, n) g[i].clear();
    }

    return 0;
}
