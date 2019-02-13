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

void dfs_a(int x) {
    int c = s[a[x] + 1];
    int y = s[b[x] + 1];
    for (auto to : g[x])
        dfs_a(to);
    if (b[x] == l)
        old[x] = 1;
    else
        old[x] = (s[b[x] + 1] - y + B) % B;
    if (a[x] == l)
        s[a[x]] = (s[a[x]] + 1) % B;
    else
        s[a[x]] = (s[a[x]] + (s[a[x] + 1] - c + B)) % B;
}

void dfs_b(int x) {
    young[x] = s[b[x] - 1];
    s[b[x]] = (s[b[x]] + young[x]) % B;
    for (auto to : g[x])
        dfs_b(to);
    s[b[x]] = (s[b[x]] - young[x] + B) % B;
}

ll d[N][2];

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
    forn(j, 1, l) s[j] = 0;
    s[l + 1] = 1;
    dfs_a(0);
    forn(j, 1, l) s[j] = 0;
    s[0] = 1;
    dfs_b(0);
    forn(j, 0, n - 1) {
        d[j][0] = old[j], d[j][1] = young[j];
        if (a[j] == 1)
            cur = (cur + d[j][0] * d[j][1]) % B;
    }
    cerr << cur << "\n";
    for (int i = 0; i < q; i += n) {
        forn(j, 0, n - 1)
            b[j] = a[j];
        forn(j, 0, min(q - 1 - i, n - 1))
            cin >> b[j];
        forn(j, 1, l) s[j] = 0;
        s[l + 1] = 1;
        dfs_a(0);
        forn(j, 1, l) s[j] = 0;
        s[0] = 1;
        dfs_b(0);
        forn(j, 0, min(q - 1 - i, n - 1)) {
            cerr << j << ": " << old[j] << " " << young[j] << " " << cur << "\n";
            cur = (cur - d[j][0] * d[j][1] % B + B) % B;
            cerr << j << ": " << old[j] << " " << young[j] << " " << cur << "\n";
            d[j][0] = old[j], d[j][1] = young[j];
            cur = (cur + d[j][0] * d[j][1]) % B;
            ans = (ans + cur * (i + j + 1)) % B;
            cerr << j << ": " << old[j] << " " << young[j] << " " << cur << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}
