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

const int N = 3e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, Q;

int f[N];

int g(int x) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) ans += f[x];
    return ans;
}

void u(int x, int d) {
    for (; x <= n; x |= x + 1) f[x] += d;
}

int a[N];
set <int> st[N];

ll solve1() {
    n = m;
    forn(i, 1, n) {
        int x;
        cin >> x;
        assert(x == i);
    }
    forn(i, 1, n) {
        cin >> a[i];
        st[a[i]].insert(i);
    }
    forn(i, 1, 5e4)
        if (st[i].size())
            u(*st[i].begin(), +1);
    ll ans = 0;
    forn(i, 1, Q) {
        int tp, r, c, x;
        cin >> tp >> c >> r >> x;
        if (tp == 1) {
            if (a[c] == x) continue;
            bool ok = 0;
            if (c == *st[a[c]].begin())
                u(c, -1), ok = 1;
            st[a[c]].erase(c);
            if (ok && st[a[c]].size())
                u(*st[a[c]].begin(), +1);
            ok = 0, a[c] = x;
            if (st[x].size() && *st[x].begin() > c)
                u(*st[x].begin(), -1), ok = 1;
            st[x].insert(c);
            if (ok || st[x].size() == 1)
                u(*st[x].begin(), +1);
        }
        else {
            if (x >= c) ans += g(min(x, n));
        }
    }
    return ans;
}

int id(int i, int j) {
    return (i - 1) * m + j;
}

pii mt[N];
int p[N], sz[N], L[N];
int di[] = {+1, 0, -1, 0};
int dj[] = {0, +1, 0, -1};

int fp(int x) {
    return x == p[x] ? x : p[x] = fp(p[x]);
}

void mrg(int x, int y) {
    x = fp(x), y = fp(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    p[y] = x;
    for (auto z : st[y]) st[x].insert(z);
    sz[x] += sz[y];
}

ll solve_slow() {
    forn(i, 1, n)
        forn(j, 1, m) {
            int l;
            cin >> l;
            mt[id(i, j)] = {l, id(i, j)};
            L[id(i, j)] = l;
        }
    sort(mt + 1, mt + 1 + n * m);
    mt[n * m + 1] = {2e9, 0};
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[id(i, j)];
    ll ans = 0;
    forn(it, 1, Q) {
        int tp, r, c, x;
        cin >> tp >> c >> r >> x;
        if (tp == 1)
            a[id(r, c)] = x;
        else {
            if (L[id(r, c)] > x) continue;
            forn(i, 1, n * m)
                p[i] = sz[i] = 0, st[i].clear();
            forn(i, 1, n * m + 1) {
                if (mt[i].F != mt[i - 1].F && mt[i].F > x) {
                    ans += st[fp(id(r, c))].size();
                    break;
                }
                int cur = mt[i].S;
                p[cur] = cur, sz[cur] = 1, st[cur].insert(a[cur]);
                int x = (cur - 1) / m + 1, y = (cur - 1) % m + 1;
                forn(dir, 0, 3) {
                    int tx = x + di[dir], ty = y + dj[dir];
                    if (1 <= tx && tx <= n && 1 <= ty && ty <= m && p[id(tx, ty)])
                        mrg(cur, id(tx, ty));
                }
            }
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> Q;
    if (n == 1 && Q > 5e2) {
        cout << solve1() << "\n";
        return 0;
    }
    cout << solve_slow() << "\n";

    return 0;
}
