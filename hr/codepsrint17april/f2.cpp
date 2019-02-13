#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];

int ans[N];
pii a[N];
map <pii, int> p2i;
int u[N];
int d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
        ++d[f], ++d[t];
    }
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        assert(p2i.count(a[i]) == 0);
        p2i[a[i]] = i;
    }
    //dfs(1);
    forn(it, 1, n) {
        int s = 0;
        forn(i, 1, n)
            if (!u[i] && (s == 0 || a[s] > a[i]))
                s = i;
        int x = 0;
        vi b(n + 1);
        forn(i, 1, n)
            if (ans[i] == 0 && d[i] > 1)
                for (auto to : g[i])
                    if (ans[to] == 0) b[to];
        forn(i, 1, n)
            if (d[i] == 1 || (it == n && ans[i] == 0)) {
                x = i;
                break;
            }
        ans[x] = s;
        for (auto to : g[x])
            --d[x], --d[to];
        u[s] = 1;
    }
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}

