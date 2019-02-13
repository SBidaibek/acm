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

const int N = 3e2 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

void gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
    int x1, y1;
    gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
}

bool solve(int a, int b, int c, int g) {
    int x, y;
    if (a > b) swap(a, b);
    gcd(a, b, x, y);
    if (x > 0 && y > 0) return 1;
    x *= c / g, y *= c / g;
    int ag = a / g, bg = b / g;
    int kx = (abs(x) + bg - 1) / bg;
    int ky = (abs(y) + ag - 1) / ag;
    if (x < 0)
        return kx < ky;
    return ky < kx;
}

int n, m, C;
vector <pii> g[N];
vi s[N];
int to[N][N], w[N][N], u[N][N], z[N][N], c[N];
int a[N], b[N], p[N];

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        int k;
        cin >> k;
        if (!k) continue;
        forn(j, 1, k) {
            int t, w;
            cin >> t >> w;
            g[i].pb({t, w});
        }
        g[i].pb(g[i][0]);
        forn(j, 1, k) {
            to[g[i][j].F][i] = g[i][j - 1].F;
            w[g[i][j].F][i] = g[i][j - 1].S;
        }
    }
    cin >> m >> C;
    forn(i, 1, m) {
        cin >> a[i] >> b[i];
        int k;
        cin >> k;
        forn(j, 1, k) {
            int x;
            cin >> x;
            u[i][x] = 1;
        }
    }

    forn(i, 1, m) p[i] = i;
    vi ans;
    forn(i, 1, m) {
        //vector <pii> v;
        forn(j, 1, n) s[j].clear();
        int sz = 0;
        cerr << i << "\n";
        for (int x = a[i], y = b[i]; c[i] == 0 || x != a[i] || y != b[i];) {
            //v.pb({x, c[i]});
            s[x].pb(c[i]);
            int t = to[x][y];
            c[i] += w[x][y];
            x = y, y = t;
            ++sz;
        }
        cerr << i << "\n";
        forn(j, 1, i - 1) {
            bool ok = 0;
            cerr << "ok\n";
            int g = __gcd(c[i], c[j]);
            for (int x = a[j], y = b[j], l = 0; l == 0 || x != a[j] || y != b[j];) {
                for (auto p : s[x])
                    if (p == l || abs(p - l) % g == 0) {// && solve(c[i], c[j], abs(p - l), g))) {
                        ok = 1;
                        break;
                    }
                if (ok) break;
                int t = to[x][y];
                l += w[x][y];
                x = y, y = t;
            }
            cerr << "ok\n";
            if (ok)
                p[f(j)] = i;
            cerr << "ok\n";
                //forn(k, 1, C)
                //    u[i][k] |= u[j][k], u[j][k] |= u[i][k];
        }

        cerr << i << "\n";
    }
    forn(i, 1, m)
        forn(j, 1, C)
            z[f(i)][j] |= u[i][j];
    forn(i, 1, m) {
        int cnt = 0;
        forn(j, 1, C)
            cnt += z[f(i)][j];
        if (cnt == C)
            ans.pb(i);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << "\n";

    return 0;
}
