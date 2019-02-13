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
set <int> ans;

void solve(int i, int j, int q, int k) {
    if (i == p.size()) {
        ll cur = 0;
        forn(z, 1, k)
            if (d[z] == 1) cur = -INF; else cur += d[z] - 1;
        if (cur > 0) ans.insert(cur);
        return;
    }
    if (j == c[i] && q == k + 1)
        solve(i + 1, 0, 1, k);
    if (j < c[i]) {
        int old = d[q];
        d[q] *= p[i];
        solve(i, j + 1, q, k);
        d[q] = old;
    }
    if (q < k || (q == k && j == c[i]))
        solve(i, j, q + 1, k);
}

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

    forn(i, 1, slog) d[i] = 1;
    forn(i, 1, slog)
        solve(0, 0, 1, i);

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
