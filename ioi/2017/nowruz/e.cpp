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

const int N = 1e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vector <pii> g[N], v[N];
pii q[N];

bool dfs(int x, int goal, int p, vector <pii> &ans) {
    if (x == goal) return 1;
    for (auto e : g[x]) {
        int to = e.F;
        if (to == p) continue;
        if (dfs(to, goal, x, ans)) {
            ans.pb({e.S, x < to});
            return 1;
        }
    }
    return 0;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n = 5;
    int m = 5;
    forn(it, 1, 100) {
        cerr << "test " << it << "\n";
        srand(it);
        forn(i, 1, n) g[i].clear();
        vector <pii> e;
        forn(i, 2, n) {
            int p = rand() % (i - 1) + 1;
            g[p].pb({i, e.size()});
            g[i].pb({p, e.size()});
            e.pb({i, p});
            cerr << p << " " << i << "\n";
        }
        cerr << "-\n";
        vi cnt(n - 1);
        forn(i, 1, m) {
            q[i] = {rand() % n + 1, rand() % n + 1};
            while (q[i].F == q[i].S)
                q[i].S = rand() % n + 1;
            v[i].clear();
            assert(dfs(q[i].F, q[i].S, -1, v[i]));
            reverse(v[i].begin(), v[i].end());
            for (auto p : v[i])
                ++cnt[p.F];
        }

        int best = 0, ans = 0;
        forn(mask, 0, (1 << m) - 1) {
            vi mp(n - 1);
            forn(i, 1, m) {
                bool b = (mask & (1 << (i - 1)));
                for (auto p : v[i]) {
                    int o = (b ^ p.S) + 1;
                    if (mp[p.F] == 0) mp[p.F] = o;
                    else
                        if (mp[p.F] == 3 - o) mp[p.F] = 3;
                }
            }
            int cur = 0;
            forn(i, 0, n - 2) {
                cur += ((mp[i] > 0) + (mp[i] > 2));
            }
            if (cur > best)
                best = cur, ans = mask;
        }
        vi mp(n - 1);
        int mask = ans;
        forn(i, 1, m) {
            bool b = (mask & (1 << (i - 1)));
            for (auto p : v[i]) {
                int o = (b ^ p.S) + 1;
                if (mp[p.F] == 0) mp[p.F] = o;
                else
                    if (mp[p.F] == 3 - o) mp[p.F] = 3;
            }
        }

        forn(i, 0, n - 2)
            if (cnt[i] > 1)
                assert(mp[i] == 3);
    }

    return 0;
}
