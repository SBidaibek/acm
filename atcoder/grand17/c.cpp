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

int n;
vi g[N];
int a[N];
int u[N], timer;

void calc(int x, int pr, int cur) {
    u[cur] = timer;
    for (auto to : g[x]) {
        if (to == pr) continue;
        cur ^= a[to];
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        calc(to, x, cur ^ a[to]);
    }
}

vi v[N];

void dfs(int x, int pr = -1) {
    int cur = 0;
    for (auto to : g[x]) {
        if (to == pr) continue;
        dfs(to, x);
        cur ^= a[to];
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        if (v[x].size() == 0) v[x] = v[to];
        else {
            vi tmp;
            for (auto y : v[x])
                for (auto z : v[to])
                    tmp.pb(y ^ z);
            v[x] = tmp;
        }
    }
    for (auto to : g[x]) {
        if (to == pr) continue;
        v[x].pb(cur ^ a[to]);
    }
    //if (x == 3) exit(0);
    timer++;
    for (auto y : v[x]) u[y] = timer;
    forn(i, 0, N - 1)
        if (u[i] != timer) {
            a[x] = i;
            return;
        }
}

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
    }
    dfs(1);
    forn(i, 1, n) cerr << i <<": " << a[i] << "\n";
    cout << (a[1] ? "Alice\n" : "Bob\n");

    return 0;
}
