#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int a[N], p[N];
pii d[N];

void dfs(int x, int pr = -1) {
    d[x] = {a[x], -x};
    for (auto to : g[x]) {
        if (to == pr) continue;
        dfs(to, x);
        d[x] = max(d[x], pii(d[to].F - 1, d[to].S));
    }
}

void up(int x, int pr, pii c) {
    set <pii> st;
    st.insert({a[x], -x});
    if (pr > 0) {
        c.F--;
        st.insert(c);
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        st.insert({d[to].F - 1, d[to].S});
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        st.erase({d[to].F - 1, d[to].S});
        up(to, x, *--st.end());
        st.insert({d[to].F - 1, d[to].S});
    }
    st.erase({a[x], -x});
    assert(st.size());
    pii t = *--st.end();
    p[x] = -(t.S);
    st.clear();
}

int u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }

    dfs(1);
    up(1, -1, {0, 0});

    forn(i, 1, n) u[i] = -1;
    int x = 1, c = 0;
    for (; u[x] == -1; x = p[x]) {
        if (c == k) {
            cout << x << "\n";
            return 0;
        }
        u[x] = c++;
    }
    k -= c;
    for (k %= (c - u[x]); k; --k) x = p[x];
    cout << x << "\n";

    return 0;
}
