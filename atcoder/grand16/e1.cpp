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
typedef vector <int> vi;

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;
const int K = 1e3;

int n, m;
int f[N], t[N];
int d[K], dist[K];
int w[K][K];
vi g[K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        cin >> f[i] >> t[i];
        if (!w[f[i]][t[i]]) {
            w[f[i]][t[i]] = i;
            w[t[i]][f[i]] = i;
        }
    }
    forn(i, 1, n)
        forn(j, 1, n)
            if (w[i][j]) g[i].pb(j);
    int ans = 0;
    forn(i, 1, n) {
        forn(j, i + 1, n) {
            if (w[i][j]) continue;
            forn(k, 1, n) {
                d[k] = (k == i || k == j) ? -1 : 0;
                dist[k] = (k == i || k == j) ? 1 : 0;
            }
            queue <int> q;
            q.push(i), q.push(j);
            while (q.size()) {
                int x = q.front();
                q.pop();
                for (auto to : g[x]) {
                    if (dist[to] && dist[to] <= dist[x]) continue;
                    if (d[to] > w[x][to]) d[to] = w[x][to];
                    if (!d[to]) {
                        dist[to] = dist[x] + 1;
                        d[to] = w[x][to];
                        q.push(to);
                    }
                }
            }
            bool shit = 0;
            forn(e, 1, m) {
                if (e < max(d[f[e]], d[t[e]])) shit = 1;
                if (shit) break;
            }
            if (!shit) ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}
