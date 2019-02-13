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

int n, l, q;
ll d[N], a[N], s[N];
vi g[N];

void dfs(int x) {
    d[x] = s[a[x] - 1];
    s[a[x]] = (s[a[x]] + d[x]) % B;
    for (auto to : g[x])
        dfs(to);
    s[a[x]] = (s[a[x]] - d[x] + B) % B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> q;
    forn(i, 1, n - 1) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    forn(i, 0, n - 1)
        cin >> a[i];
    //dfs(0);
    ll ans = 0;
    forn(i, 0, q - 1) {
        int v = i % n, p;
        cin >> p;
        cerr << i << " " << v << " " << a[v] << "\n";
        a[v] = p;
        forn(j, 1, l) s[j] = 0;
        s[0] = 1;
        dfs(0);
        ll cur = 0;
        forn(j, 0, n - 1)
            if (a[j] == l)
                cur += d[j];
        cerr << i << " " << v << " " << a[v] << ": " << cur << "\n";
        ans = (ans + cur * (i + 1)) % B;
    }
    cout << ans << "\n";

    return 0;
}
