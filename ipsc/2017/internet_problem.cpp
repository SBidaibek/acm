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

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
vi g[N], r[N];
int u[N], c[N], sz[N], d[N];
vi o;

void ts(int x) {
    if (u[x]) return;
    u[x] = 1;
    for (auto to : g[x]) ts(to);
    o.pb(x);
}

void dfs(int x, int col) {
    if (c[x]) return;
    c[x] = col;
    ++sz[col];
    for (auto to : r[x])
        dfs(to, col);
}

bool cmp(int a, int b) {
    return d[a] < d[b];
}

int faggot[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        forn(i, 1, n)
            faggot[i] = 0;
        forn(i, 1, m) {
            int f, t;
            cin >> f >> t;
            if (f == t) faggot[f] = 1;
            g[f].pb(t);
            r[t].pb(f);
        }
        forn(i, 2, n) d[i] = -1;
        d[1] = 0;
        o.clear();
        forn(i, 1, n) ts(i);
        int k = 0;
        reverse(o.begin(), o.end());
        for (auto i : o)
            if (!c[i]) dfs(i, ++k);

        queue <int> q;
        q.push(1);
        vi cnt(n);
        vi ans;
        while (q.size()) {
            int x = q.front();
            q.pop();
            ++cnt[d[x]];
            for (auto to : g[x]) {
                if (d[to] == -1) {
                    d[to] = d[x] + 1;
                    q.push(to);
                }
            }
        }
        if (d[n] == -1) {
            cout << "0\n\n";
            continue;
        }
        forn(x, 1, n)
            if (d[x] != -1 && sz[c[x]] == 1 && cnt[d[x]] == 1 && !faggot[x]) ans.pb(x);
        cout << ans.size() << "\n";
        sort(ans.begin(), ans.end(), cmp);
        for (auto x : ans) cout << x << " ";
        cout << "\n";

        forn(i, 1, n)
            c[i] = 0, u[i] = 0, sz[i] = 0, g[i].clear(), r[i].clear();
    }

    return 0;
}
