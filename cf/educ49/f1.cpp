#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int p[N], u[N];
int m[N];

bool dfs(int x) {
    if (u[x]) return 0;
    u[x] = 1;
    for (auto to : g[x])
        if (!m[to] || dfs(m[to])) {
            m[to] = x;
            p[x] = to;
            return 1;
        }
    return 0;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    //n = 1e6;
    vector <pii> q(n + 1);
    vi w;
    forn(i, 1, n) {
        //a = (1ll * rand() * rand()) % int(1e9) + 1;
        //b = (1ll * rand() * rand()) % int(1e9) + 1;
        cin >> q[i].F >> q[i].S;
        w.pb(q[i].F), w.pb(q[i].S);
    }
    sort(w.begin(), w.end());
    w.resize(unique(w.begin(), w.end()) - w.begin());
    forn(i, 1, n) {
        int a = lower_bound(w.begin(), w.end(), q[i].F) - w.begin() + 1;
        int b = lower_bound(w.begin(), w.end(), q[i].S) - w.begin() + 1;
        g[a].pb(i);
        g[b].pb(i);
    }
    int k = w.size();
    forn(i, 1, k) {
        forn(j, 1, k) u[j] = 0;
        dfs(i);
    }
    int ans = 0;
    forn(i, 1, n)
        if (!m[i]) {
            cout << "-1\n";
            return 0;
        }
        else
            ans = max(ans, w[m[i] - 1]);
    cout << ans << "\n";

    return 0;
}
