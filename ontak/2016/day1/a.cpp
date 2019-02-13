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

int n, k, m;
ll w[N], lvl[N];
ll a[N], b[N], s;
vi g[N];

int fc(int x, int p, int q, int &c) {
    int sz = 1;
    for (auto to : g[x])
        if (!lvl[to] && to != p)
            sz += fc(to, x, q, c);
    if (c == 0 && sz * 2 >= q) c = x;
    return sz;
}

set <ll> st, good;

void gen(int x, int p, ll cur) {
    st.insert(cur);
    for (auto to : g[x])
        if (to != p && !lvl[to])
            gen(to, x, cur + a[to]);
}

bool ass(int x, int p, ll cur) {
    bool ans = good.count(cur);
    for (auto to : g[x])
        if (to != p && !lvl[to])
            ans |= ass(to, x, cur + a[to]);
    b[x] |= ans;
    return ans;
}

void cd(int x, int sz = n, int dep = 1) {
    int c = 0;
    fc(x, 0, sz, c);
    if (c) x = c;
    lvl[x] = dep;
    st.clear(), good.clear();
    for (auto to : g[x])
        if (!lvl[to])
            gen(to, x, a[to]);
    st.insert(0);
    for (auto v : st)
        if (v + a[x] <= s && st.count(s - v - a[x]))
            good.insert(s - v - a[x]), good.insert(v);
    if (good.size()) {
        b[x] = 1;
        for (auto to : g[x])
            if (!lvl[to])
                ass(to, x, a[to]);
    }
    if (s == a[x])
        b[x] = 1;
    for (auto to : g[x])
        if (!lvl[to])
            cd(to, sz / 2, dep + 1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    forn(i, 1, k) {
        w[i] = ((1ll * rand() * rand()) % ll(12e9)) ^ (1ll * rand() << 16 | rand()) + 1;
        s += w[i];
    }
    forn(i, 1, n) {
        cin >> a[i];
        a[i] = w[a[i]];
    }
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >>  t;
        g[f].pb(t);
        g[t].pb(f);
    }
    cd(1);
    forn(i, 1, m) {
        int x;
        cin >> x;
        cout << (b[x] ? "YES" : "NO") << "\n";
    }

    return 0;
}


