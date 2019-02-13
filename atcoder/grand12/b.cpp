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

int n, m, q;
vi g[N];
int d[N][11];
int a[N], col[N];
int dist[N], u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    cin >> q;
    forn(i, 1, q) {
        int v, x;
        cin >> v >> x >> col[i];
        forn(j, 0, x)
            d[v][j] = i;
    }
    forn(i, 1, n) {
        queue <int> q;
        q.push(i);
        dist[i] = 0;
        int mx = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            u[x] = i;
            mx = max(mx, d[x][dist[x]]);
            if (dist[x] == 10) continue;
            for (auto to : g[x]) {
                if (u[to] == i) continue;
                u[to] = i;
                dist[to] = dist[x] + 1;
                q.push(to);
            }
        }
        if (mx)
            a[i] = col[mx];
    }
    forn(i, 1, n)
        cout << a[i] << "\n";

    return 0;
}
