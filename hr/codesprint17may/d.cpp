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

const int N = 5e4 + 2;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, q, sz;
vi g[N], rg[N], cg[N];
int u[N], c[N], tp[N * 2], qx[N * 2], qy[N * 2];

vi o;

void ts(int x) {
    if (u[x]) return;
    u[x] = 1;
    for (auto to : g[x])
        ts(to);
    o.pb(x);
}

void rdfs(int x, int cp = -1) {
    if (c[x]) return;
    if (cp == -1) cp = ++sz;
    c[x] = cp;
    for (auto to : rg[x])
        rdfs(to, cp);
}

bitset <N> b[N];

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
    }
    cin >> q;
    forn(i, 1, q) {
        cin >> tp[i] >> qx[i] >> qy[i];
        if (tp[i] == 1) {
            if (qy[i])
                g[++n].pb(qx[i]);
            else
                g[qx[i]].pb(++n);
        }
    }

    forn(i, 1, n)
        for (auto to : g[i])
            rg[to].pb(i);
    forn(i, 1, n)
        ts(i);
    reverse(o.begin(), o.end());
    for (auto i : o)
        rdfs(i);
    reverse(o.begin(), o.end());

    for (auto i : o) {
        cerr << i << ": " << c[i] << "\n";
        b[c[i]][c[i]] = 1;
        for (auto to : g[i])
            if (c[to] != c[i])
                b[c[i]] |= b[c[to]];
    }
    forn(i, 1, q) {
        if (tp[i] == 1) continue;
        cout << (b[c[qx[i]]][c[qy[i]]] ? "Yes" : "No") << "\n";
    }

    return 0;
}
