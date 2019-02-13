#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e5 + 3, K = 102;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, s, len, q, id[N];
vector <pii> g[N], rg[N];
ll dist[K][N], rdist[K][N];
ll d[K][K], tmp[K][K], path[K][K];
bool bar[N];

void Dijkstra(int x) {
    forn(i, 1, n) dist[x][i] = INF;
    dist[x][id[x]] = 0;
    set <pii> st;
    st.insert({0, id[x]});
    while (st.size()) {
        int v = st.begin() -> S;
        st.erase(st.begin());
        //if (bar[v] && v != id[x]) continue;
        for (auto to : g[v])
            if (dist[x][to.F] > dist[x][v] + to.S) {
                st.erase({dist[x][to.F], to.F});
                dist[x][to.F] = dist[x][v] + to.S;
                st.insert({dist[x][to.F], to.F});
            }
    }
}

void RDijkstra(int x) {
    forn(i, 1, n) rdist[x][i] = INF;
    rdist[x][id[x]] = 0;
    set <pii> st;
    st.insert({0, id[x]});
    while (st.size()) {
        int v = st.begin() -> S;
        st.erase(st.begin());
        //if (bar[v] && v != id[x]) continue;
        for (auto to : rg[v])
            if (rdist[x][to.F] > rdist[x][v] + to.S) {
                st.erase({dist[x][to.F], to.F});
                rdist[x][to.F] = rdist[x][v] + to.S;
                st.insert({rdist[x][to.F], to.F});
            }
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> len >> q;
    forn(i, 1, s) {
        cin >> id[i];
        bar[id[i]] = 1;
    }
    forn(i, 1, m) {
        int f, t, w;
        cin >> f >> t >> w;
        g[f].pb({t, w});
        rg[t].pb({f, w});
    }

    forn(i, 1, s) {
        Dijkstra(i);
        RDijkstra(i);
        forn(j, 1, s)
            path[i][j] = dist[i][id[j]];
        path[i][i] = INF;
    }
    int cnt = 0;
    --len;
    forn(step, 0, 6) {
        if (len & (1 << step)) {
            if (cnt++ == 0)
                memcpy(d, path, sizeof d);
            else {
                forn(i, 1, s) {
                    forn(j, 1, s) {
                        tmp[i][j] = min(INF, d[i][1] + path[1][j]);
                        forn(k, 2, s)
                            tmp[i][j] = min(tmp[i][j], d[i][k] + path[k][j]);
                    }
                }
                memcpy(d, tmp, sizeof d);
            }
        }
        forn(i, 1, s) {
            forn(j, 1, s) {
                tmp[i][j] = min(INF, path[i][1] + path[1][j]);
                forn(k, 2, s)
                    tmp[i][j] = min(tmp[i][j], path[i][k] + path[k][j]);
            }
        }
        memcpy(path, tmp, sizeof path);
    }
    if (len == 0) {
        forn(i, 1, s)
            forn(j, 1, s)
                d[i][j] = (i == j ? 0 : INF);
    }

    forn(i, 1, q) {
        int f, t;
        cin >> f >> t;
        ll ans = INF;
        forn(j, 1, s)
            forn(k, 1, s)
                ans = min(ans, rdist[j][f] + d[j][k] + dist[k][t]);
        cout << (ans == INF ? -1 : ans) << "\n";
    }

    return 0;

}
