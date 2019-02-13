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

const int N = 5e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int _n[N], _q[N];
vi _p[N];
int n, q, off[N], p[N];
int d[N];
pii pr[N];

bool bit(int mask, int i) {
    return mask & (1 << i);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    int mx = 0;
    forn(i, 1, tests) {
        cin >> _n[i] >> _q[i];
        mx = max(mx, _n[i]);
        _p[i].resize(_q[i] + 1);
        forn(j, 1, _q[i])
            cin >> _p[i][j];
    }
    bool ok = 1;
    forn(i, 2, tests) ok &= (_n[i] == _n[1]);
    if (ok && mx <= 18) {
        n = mx;
        d[(1 << n) - 1] = 1;
        for1(mask, (1 << n) - 1, 0) {
            if (d[mask] == 0) continue;
            vi v;
            forn(i, 0, n - 1)
                if (bit(mask, i)) v.pb(i);
            forn(i, 0, v.size() - 3) {
                int to = mask;
                to ^= (1 << v[i]);
                to ^= (1 << v[i + 2]);
                d[to] = d[mask] + 1;
                pr[to] = {mask, v[i + 1] + 1};
            }
        }
    }
    forn(it, 1, tests) {
        n = _n[it], q = _q[it];
        forn(i, 1, q)
            p[i] = _p[it][i];
        p[0] = 0, p[q + 1] = n + 1;
        if (ok && mx <= 18) {
            int mask = 0;
            forn(i, 1, q)
                mask |= (1 << (p[i] - 1));
            int ans = d[mask] - 1;
            cout << ans << "\n";
            if (ans != -1) {
                vi path;
                for (; mask != (1 << n) - 1; mask = pr[mask].F)
                    path.pb(pr[mask].S);
                reverse(path.begin(), path.end());
                for (auto x : path) cout << x << " ";
                cout << "\n";
            }
            continue;
        }

        forn(i, 1, q)
            off[i] = (p[i] == p[i - 1] + 1 || p[i] == p[i + 1] - 1);
        int ans = 0;
        if (q == 0 || (n - q) % 2 == 1) ans = -1;
        if (p[1] > 1 && off[1]) ans = -1;
        if (p[q] < n && off[q]) ans = -1;

        int cur = (p[1] - 1) % 2;
        forn(i, 2, q) {
            int t = (p[i] - p[i - 1] - 1);
            if (off[i - 1] && off[i] && t > 0) ans = -1;
            if (cur && t == 0) ans = -1;
            cur = (t % 2 - cur + 2) % 2;
            if (cur && (t == 0 || off[i])) ans = -1;
        }
        if (cur != (n - p[q]) % 2) ans = -1;
        cout << ans << "\n";
        if (ans != -1) cout << "\n";
    }

    return 0;
}
