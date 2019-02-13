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

int n;
vi g[N];
int val[N], tp[N], def[N];
vector <pii> ans;

void build(int x) {
    if (tp[x] == 4) {
        def[x] = val[x];
        return;
    }
    for (auto to : g[x])
        build(to);
    if (tp[x] == 0)
        def[x] = (def[g[x][0]] & def[g[x][1]]);
    if (tp[x] == 1)
        def[x] = (def[g[x][0]] | def[g[x][1]]);
    if (tp[x] == 2)
        def[x] = (def[g[x][0]] ^ def[g[x][1]]);
    if (tp[x] == 3)
        def[x] = (!def[g[x][0]]);
}

void dfs(int x, int xo, int found) {
    if (tp[x] == 4) {
        int b = found == -1 ? (val[x] ^ 1) : found;
        ans.pb({x, b ^ xo});
        return;
    }
    if (tp[x] == 0) {
        if (found == -1) {
            dfs(g[x][0], xo, def[g[x][1]] == 0 ? 0 : found);
            dfs(g[x][1], xo, def[g[x][0]] == 0 ? 0 : found);
        }
        else {
            dfs(g[x][0], xo, found);
            dfs(g[x][1], xo, found);
        }
    }
    if (tp[x] == 1) {
        if (found == -1) {
            dfs(g[x][0], xo, def[g[x][1]] == 1 ? 1 : found);
            dfs(g[x][1], xo, def[g[x][0]] == 1 ? 1 : found);
        }
        else {
            dfs(g[x][0], xo, found);
            dfs(g[x][1], xo, found);
        }
    }
    if (tp[x] == 2) {
        if (found == -1) {
            dfs(g[x][0], xo ^ def[g[x][1]], found);
            dfs(g[x][1], xo ^ def[g[x][0]], found);
        }
        else {
            dfs(g[x][0], xo, found);
            dfs(g[x][1], xo, found);
        }
    }
    if (tp[x] == 3)
        if (found == -1) {
            dfs(g[x][0], xo ^ 1, found);
        }
        else {
            dfs(g[x][0], xo, found);
        }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    map <char, int> mp;
    mp['A'] = 0;
    mp['O'] = 1;
    mp['X'] = 2;
    mp['N'] = 3;
    mp['I'] = 4;
    forn(i, 1, n) {
        string s;
        int a, b;
        cin >> s >> a;
        tp[i] = mp[s[0]];
        if (tp[i] == 4) {
            val[i] = a;
            continue;
        }
        g[i].pb(a);
        if (tp[i] <= 2) {
            cin >> b;
            g[i].pb(b);
        }
    }
    build(1);
    dfs(1, 0, -1);

    sort(ans.begin(), ans.end());
    for (auto p : ans)
        cout << p.S;
    cout << "\n";

    return 0;
}
