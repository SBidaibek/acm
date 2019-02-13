#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e2 + 10;
const int K = 51;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vi p, c;
int d[N];
unordered_map <int, vector <pii>> v;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n0\n";
        return 0;
    }
    int sav = n;
    int slog = 0;
    forn(i, 2, n) {
        if (1ll * i * i > n) break;
        if (n % i != 0) continue;
        p.pb(i);
        c.pb(0);
        for (; n % i == 0; n /= i) ++c.back();
        slog += c.back();
    }
    if (n > 1)
        p.pb(n), c.pb(1), ++slog;
    n = sav;
    cerr << n << "\n";

    v[n].pb({1, 1});
    set <int> q;
    q.insert(n);
    while (q.size()) {
        int x = *--q.end();
        q.erase(--q.end());
        cerr << x << "\n";
        for (auto w : v[x])
            forn(i, w.S + 1, x) {
                if (1ll * i * i > x) break;
                v[x / i].pb({w.S + i - 1, i});
                v[i].pb({w.S + x / i - 1, x / i});
                q.insert(i), q.insert(x / i);
            }
    }
    vi ans;
    sort(v[1].begin(), v[1].end());
    forn(i, 0, v[1].size() - 1)
        if (i == 0 || (v[1][i].F != v[1][i - 1].F))
            ans.pb(v[1][i].F);
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
