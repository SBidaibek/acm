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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
vi g[N];
int shit, cnt;
int u[N], c[N];

void dfs(int x) {
    u[x] = 1;
    ++cnt;
    for (auto to : g[x]) {
        if (u[to] && c[to] == c[x]) shit = 1;
        if (!u[to]) {
            c[to] = c[x] ^ 1;
            dfs(to);
        }
    }
}

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
        g[t].pb(f);
    }

    ll a = 0, b = 0, c = 0;
    forn(i, 1, n) {
        if (u[i]) continue;
        if (g[i].size() == 0) {
            ++c;
            continue;
        }
        shit = 0;
        dfs(i);
        if (!shit) ++a;
        else ++b;
    }
    cout << 2 * a * a + 2 * a * b + b * b + (2 * c * n - c * c) << "\n";

    return 0;
}
