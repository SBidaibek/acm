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
typedef vector <ll> vi;

const int N = 2e6 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
vi o;
int ptr;
vi g[N];
int sz[N];

int dfs(int x, int p = -1) {
    sz[x] = 1;
    o.pb(x);
    for (auto to : g[x]) {
        if (to == p) continue;
        sz[x] += dfs(to, x);
    }
    return sz[x];
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

int q(pii a) {
    if (a.x > 0 && a.y >= 0) return 1;
    if (a.x <= 0 && a.y > 0) return 2;
    if (a.x < 0 && a.y <= 0) return 3;
    return 0;
}

bool cmp(pii a, pii b) {
    if (q(a) != q(b)) return q(a) < q(b);
    return cp(a, b) > 0;
}

int ans[N];
pii a[N];
map <pii, int> p2i;
int used[N];

void solve(int p, int x, int pr = -1) {
    used[p] = 1;
    ans[x] = p;
    vi v;
    forn(i, 1, n)
    for (auto to : g[x]) {
        if (to == pr) continue;
        int mn = 0;
        forn(i, 1, n) {
            if (used[i]) continue;
            pii u = {a[i].x - a[p].x, a[i].y - a[p].y};
            bool shit = 0;
            forn(j, 1, n)
                if (!used[j] && j != i) {
                    pii v = {a[j].x - a[i].x, a[j].y - a[i].y};
                    if (cp(u, v) < 0) {
                        shit = 1;
                        break;
                    }
                }
            if (!shit) {
                mn = i;
                break;
            }
            //if (mn == 0 || cmp(u, v))
            //    mn = i, v = u;
        }
        used[mn] = 1;
        //cerr << x << " " << p << " " << mn << "\n";
        solve(mn, to, x);
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    dfs(1);
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        assert(p2i.count(a[i]) == 0);
        p2i[a[i]] = i;
    }
    int s = 1;
    forn(i, 2, n)
        if (a[s] > a[i])
            s = i;
    solve(s, 1);
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}

