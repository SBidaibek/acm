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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N], v[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    forn(_, 1, tc) {
        cin >> n;
        forn(i, 0, n)
            g[i].clear(), v[i].clear();
        forn(i, 1, n - 1) {
            int f, t;
            cin >> f >> t;
            g[f].pb(t);
            g[t].pb(f);
        }
        queue <int> q;
        vi d(n + 1);
        forn(i, 1, n)
            if (g[i].size() == 1)
                q.push(i), d[i] = 0;
            else
                d[i] = -1;
        int mx = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            mx = max(mx, d[x]);
            v[d[x]].pb(x);
            for (auto to : g[x])
                if (d[to] == -1) {
                    d[to] = d[x] + 1;
                    q.push(to);
                }
        }
        if (mx == 0 || (mx == 1 && v[1].size() == 1)) {
            cout << "-1\n";
            continue;
        }
        cout << v[mx].back() << " ";
        int lst = v[mx].back();
        v[mx].pop_back();
        if (!v[mx].size()) --mx;
        vi tmp(n + 1, -1);
        forn(i, 0, mx) {
            for (auto to : g[lst]) tmp[to] = i;
            int j = 0, kek = 1;
            while (tmp[v[i][j]] == i) {
                kek = j;
                ++j;
            }
            assert(j < v[i].size());
            forn(it, 1, v[i].size()) {
                if (j != kek) cout << v[i][j] << " ";
                if (it < v[i].size())
                    j = (j == v[i].size() - 1 ? 0 : j + 1);
            }
            if (kek < v[i].size()) {
                cout << v[i][kek] << " ";
                lst = v[i][kek];
            }
            else lst = v[i][j];
        }
        cout << "\n";
    }

    return 0;
}
