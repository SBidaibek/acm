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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int L = 20;

int n, q;
int to[N], d[N];
vector <pii> g[N];
int p[N][L];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int k = 0;
    cin >> n >> q;
    vector <pii> v;
    forn(i, 1, n) {
        int f;
        cin >> f >> to[i] >> d[i];
        g[f].pb({d[i], i});
        v.pb({d[i], i});
        k = max(k, max(f, to[i]));
    }
    forn(i, 1, k)
        sort(g[i].begin(), g[i].end(), [](pii a, pii b) {
            return pii(d[a.S], to[a.S]) < pii(d[b.S], to[b.S]);
        });
    sort(v.begin(), v.end(), greater <pii> ());
    for (auto e : v) {
        int i = e.S;
        if (!g[to[i]].size() || g[to[i]].back().F <= d[i])
            p[i][0] = i;
        else
            p[i][0] = upper_bound(g[to[i]].begin(), g[to[i]].end(), pii(d[i], n + 1)) -> S;
        forn(j, 1, L - 1)
            p[i][j] = p[p[i][j - 1]][j - 1];
    }

    forn(i, 1, q) {
        int x, s, f;
        cin >> x >> s >> f;
        if (s == f || !g[x].size() || g[x].back().F < s) {
            cout << x << "\n";
            continue;
        }
        int e = lower_bound(g[x].begin(), g[x].end(), pii(s, 0)) -> S;
        if (d[e] >= f) {
            cout << x << "\n";
            continue;
        }
        for1(j, L - 1, 0)
            if (d[p[e][j]] < f) e = p[e][j];
        cout << to[e] << "\n";
    }

    return 0;
}
