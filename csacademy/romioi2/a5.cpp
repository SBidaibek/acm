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
ll old[N], young[N], a[N], b[N], s[N];
vi g[N];
ll d1[N][2], d2[N][2];

void dfs1(int x) {
    int ca = s[a[x] + 1];
    int cb = s[b[x] + 1];
    for (auto to : g[x])
        dfs1(to);
    if (a[x] == l) d1[x][0] = 1;
    else d1[x][0] = (s[a[x] + 1] - ca + B) % B;
    if (b[x] == l) d1[x][1] = 1;
    else d1[x][1] = (s[b[x] + 1] - cb + B) % B;
    s[a[x]] = (s[a[x]] + d1[x][0]) % B;
}

void dfs2(int x) {
    d2[x][0] = s[a[x] - 1];
    d2[x][1] = s[b[x] - 1];
    s[b[x]] = (s[b[x]] + d2[x][1]) % B;
    for (auto to : g[x])
        dfs2(to);
    s[b[x]] = (s[b[x]] - d2[x][1] + B) % B;
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
    forn(i, 0, n - 1) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll ans = 0, cur = 0;
    forn(j, 1, l) s[j] = 0; s[l + 1] = 1;
    dfs1(0);
    forn(j, 1, l) s[j] = 0; s[0] = 1;
    dfs2(0);
    forn(j, 0, n - 1)
        if (a[j] == 1)
            cur = (cur + d1[j][0] * d2[j][0]) % B;
    for (int i = 0; i < q; i += n) {
        forn(j, 0, n - 1)
            b[j] = a[j];
        forn(j, 0, min(q - 1 - i, n - 1))
            cin >> b[j];
        forn(j, 1, l) s[j] = 0; s[l + 1] = 1;
        dfs1(0);
        forn(j, 1, l) s[j] = 0; s[0] = 1;
        dfs2(0);
        forn(j, 0, min(q - 1 - i, n - 1)) {
            cur = (cur - d1[j][0] * d2[j][0] % B + B) % B;
            cur = (cur + d1[j][1] * d2[j][1]) % B;
            ans = (ans + cur * (i + j + 1)) % B;
            a[j] = b[j];
        }
    }
    cout << ans << "\n";

    return 0;
}
