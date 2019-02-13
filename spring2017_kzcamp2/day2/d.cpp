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

const int N = 1e4 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, k;
vi g[N * 2];
int pr[N * 2], u1[N], u2[N];
int ans[N * 2];

bool dfs(int x) {
    if (u1[x]) return 0;
    u1[x] = 1;
    for (auto to : g[x])
        if (pr[to] == -1) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    for (auto to : g[x])
        if (dfs(pr[to])) {
            pr[to] = x;
            pr[x] = to;
            return 1;
        }
    return 0;
}

bool check1(int x) {
    if (u1[x]) return 0;
    u1[x] = 1;
    for (auto to : g[x])
        if (pr[to] == -1) return 1;
    for (auto to : g[x])
        if (check1(pr[to])) return 1;
    return 0;
}

bool check2(int x) {
    if (u2[x - n]) return 0;
    u2[x - n] = 1;
    for (auto to : g[x])
        if (pr[to] == -1) return 1;
    for (auto to : g[x])
        if (check2(pr[to])) return 1;
    return 0;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(i, 1, k) {
        int f, t;
        cin >> f >> t;
        g[f].pb(n + t);
        g[n + t].pb(f);
    }
    forn(i, 1, n + m) pr[i] = -1, ans[i] = 1;
    forn(i, 1, n) {
        if (pr[i] == -1) {
            memset(u1, 0, sizeof u1);
            bool x = 0;
            forn(j, 1, n)
                if (pr[j] == -1) x |= dfs(j);
            if (!x) break;
        }
    }

    forn(i, 1, n + m)
        if (pr[i] == -1) ans[i] = 0;
    forn(i, 1, n) {
        if (pr[i] > 0) {
            memset(u1, 0, sizeof u1);
            u1[i] = 1;
            int to = pr[i];
            pr[to] = -1;
            bool x = 0;
            forn(j, 1, n)
                if (pr[j] == -1)
                    if (check1(j)) {
                        x = 1;
                        break;
                    }
            if (x) ans[i] = 0;
            pr[to] = i;
        }
    }
    forn(i, n + 1, n + m) {
        if (pr[i] > 0) {
            memset(u2, 0, sizeof u2);
            u2[i - n] = 1;
            int to = pr[i];
            pr[to] = -1;
            bool x = 0;
            forn(j, n + 1, n + m)
                if (pr[j] == -1)
                    if (check2(j)) {
                        x = 1;
                        break;
                    }
            if (x) ans[i] = 0;
            pr[to] = i;
        }
    }

    int a = 0, b = 0;
    forn(i, 1, n)
        if (ans[i]) ++a;
    forn(i, n + 1, n + m)
        if (ans[i]) ++b;
    cout << a << "\n";
    forn(i, 1, n)
        if (ans[i]) cout << i << " ";
    cout << "\n" << b << "\n";
    forn(i, n + 1, n + m)
        if (ans[i]) cout << i - n << " ";

    return 0;
}
