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

struct edge {
    int to, flow, cap;
    edge() : to(0), flow(0), cap(0) {}
    edge(int t, int f, int c) : to(t), flow(f), cap(c) {}
} es[N];

int n, m, k, e_sz;
int sink, target;
vi g[N];

void add_edge(int f, int t, int c) {
    g[f].pb(e_sz);
    es[e_sz++] = edge(t, 0, c);
    g[t].pb(e_sz);
    es[e_sz++] = edge(f, 0, 0);
}

int d[N];

bool bfs() {
    forn(i, 1, target) d[i] = -1;
    d[sink] = 0;
    queue <int> q;
    q.push(sink);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto id : g[x]) {
            edge &e = es[id];
            if (e.flow < e.cap && d[e.to] == -1) {
                d[e.to] = d[x] + 1;
                q.push(e.to);
            }
        }
    }
    return d[target] != -1;
}

int head[N];

int dfs(int x, int cur) {
    if (!cur || x == target) return cur;
    for (int &i = head[x]; i < g[x].size(); ++i) {
        edge &e = es[g[x][i]];
        if (e.cap == e.flow || d[e.to] != d[x] + 1) continue;
        if (dfs(e.to, min(cur, e.cap - e.flow))) {
            int nf = min(cur, e.cap - e.flow);
            es[g[x][i]].flow += nf;
            es[g[x][i] ^ 1].flow -= nf;
            return nf;
        }
    }
    return 0;
}

int F;

int MF() {
    while (bfs()) {
        forn(i, 1, target) head[i] = 0;
        while (int nf = dfs(sink, INF))
            F += nf;
    }
    return F;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    forn(_, 1, t) {
        cin >> n >> m >> k;
        vector <pii> e;
        forn(i, 1, m) {
            int f, t;
            cin >> f >> t;
            if (f == n) continue;
            e.pb({f, t});
        }
        sink = 1, target = n * n + 1;
        forn(i, 1, n - 1)
            add_edge(n * i + n, target, INF);
        F = 0;
        forn(i, 1, n - 1) {
            for (auto x : e) {
                if (x.F == 1) {
                    if (i == 1) add_edge(x.F, x.S + n, 1);
                }
                else {
                    if (g[x.F + (i - 1) * n].size())
                        add_edge(x.F + (i - 1) * n, x.S + i * n, 1);
                }
            }
            if (MF() >= k) {
                cout << i << "\n";
                break;
            }
            if (i == n - 1) cout << "-1\n";
        }
        e_sz = 0;
        forn(i, 1, target)
            g[i].clear();
    }

    return 0;
}
