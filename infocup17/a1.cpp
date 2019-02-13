#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <int> vi;

const int N = 512 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int query(vector <int> islands);

vi G[N];
vi o, w;
int pos[N];

void dfs(int x, int p = -1) {
    o.pb(x);
    pos[x] = w.size();
    w.pb(x);
    for (auto to : G[x]) {
        if (to == p) continue;
        dfs(to, x);
        w.pb(x);
    }
}

int findEgg(int n, vector <PII> e) {
    forn(i, 1, n)
        G[i].clear();
    for (auto p : e)
        G[p.F].pb(p.S), G[p.S].pb(p.F);
    o.clear();
    dfs(1);
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        vi v, u(n + 1);
        forn(i, pos[o[l]], pos[o[m]]) {
            if (!u[w[i]]) v.pb(w[i]);
            u[w[i]] = 1;
        }
        if (!query(v))
            l = m + 1;
        else
            r = m;
    }
    return o[l];
}
/*
int X, Q;
vector < int > g[512+10];

int main() {
    ifstream fin("in");
    ofstream fout("out");

    int n, nr;
    vector < pair < int, int > > v;
    vector < int > Eggs;

    fin >> n >> nr; //there are nr Easter Eggs
    for (int i = 1; i <= nr; ++i) {
        int x; fin >> x; //the i-th Easter Eggs
        Eggs.push_back(x);
    }

    //the bridges
    for (int i = 1; i < n; ++i) {
        int x, y; fin >> x >> y;
        v.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (vector < int > :: iterator it = Eggs.begin(); it != Eggs.end(); ++it) {
        Q = 0; X = *it;
        fout << findEgg(n, v) << '\n';
        fout << Q << '\n';
        fout << '\n';
    }
}

bool used[512+10], is[512+10];

void browse(int node) {
    used[node] = 1;
    for (vector < int > :: iterator it = g[node].begin(); it != g[node].end(); ++it) {
        if (used[*it]) continue;
        if (is[*it]) browse(*it);
    }
}

bool beautiful(vector < int > v) {
    int n = (int)v.size();

    memset(used, 0, sizeof(used));
    memset(is, 0, sizeof(is));

    for (int i = 0; i < n; ++i)
        is[v[i]] = 1;

    browse(v[0]);
    for (int i = 0; i < n; ++i)
        if (!used[v[i]]) return 0;
    return 1;
}

int query(vector < int > v) {
    if (!beautiful(v)) {
        fprintf(stderr, "The query-islands are not beautiful");
        printf("The query-islands are not beautiful");
        exit(0);
    }

    bool res = 0; Q++;
    for (vector < int > :: iterator it = v.begin(); it != v.end(); ++it)
        res |= (X == *it);
    return res;
}
*/
