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

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int L = 20;

vi g[N];
int lvl[N];
int p[N][L];

void dfs(int x) {
    forn(i, 1, L - 1)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (auto to : g[x]) {
        p[to][0] = x;
        lvl[to] = lvl[x] + 1;
        dfs(to);
    }
}

int lca(int a, int b) {
    if (lvl[a] < lvl[b]) swap(a, b);
    for1(i, L - 1, 0)
        if (lvl[p[a][i]] >= lvl[b]) a = p[a][i];
    if (a == b) return lvl[a];
    for1(i, L - 1, 0)
        if (p[a][i] != p[b][i]) a = p[a][i], b = p[a][i];
    return lvl[p[a][0]];
}

int m;
pii t[N * 2];

pii get(int l, int r) {
    pii ans = {INF, INF};
    for(l += m - 1, r += m - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ans = min(ans, t[l++]);
        if (!(r & 1)) ans = min(ans, t[r--]);
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    forn(i, 2, n) {
        cin >> a[i];
        g[a[i]].pb(i);
    }
    dfs(1);
    m = n - 1;
    forn(i, 1, n - 1)
        t[i + m - 1] = {lca(i, i + 1), i};
    for1(i, m - 1, 1)
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    forn(i, 1, q) {
        int l, r;
        cin >> l >> r;
        if (r - l == 1) {
            cout << max(lvl[l], lvl[r]) << "\n";
            continue;
        }
        pii p1 = get(l, r - 2);
        pii p2 = get(l + 1, r - 1);
        //cerr << p1.F << " " << p2.F << "  = " << l << " " << r - 2 << "\n";
        int mn = get(l, r - 1).S;
        if (mn == l) ++mn;
        int cur = lca(mn - 1, mn + 1);
        cur = min(cur, get(l, mn - 2).F);
        cur = min(cur, get(mn + 1, r - 1).F);
        if (max(p1.F, p2.F) >= cur) {
            if (p1.F >= p2.F)
                cout << r << " " << p1.F << "\n";
            else
                cout << l << " " << p2.F << "\n";
        }
        else {
            cout << mn << " " << cur << "\n";
        }
    }

    return 0;
}

