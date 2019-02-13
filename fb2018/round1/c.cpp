#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
int h[N];
int pos[N], neg[N];

bool ok(int range) {
    ll l = h[1] - range, r = h[1] + range;
    forn(i, 2, n) {
        //cerr << h[i] << " " << neg[i] << " " << pos[i] << "\n";
        ll cl = h[i] - range, cr = h[i] + range;
        //cerr << cl << " " << cr << "\n";
        //cerr << l << " " << r << "\n-\n";
        l = max(cl, l - neg[i]);
        r = min(cr, r + pos[i]);
        if (l > r) return 0;
//        l = max(l, 1ll * h[i] - range);
//        r = max(r, 1ll * h[i] - range);
//        l = min(l, 1ll * h[i] + range);
//        r = min(r, 1ll * h[i] + range);
    }
    return 1;
}

int fr[N], to[N], up[N], dw[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(it, 1, tests) {
        cout << "Case #" << it << ": ";
        cin >> n >> m;
        forn(i, 1, 2) cin >> h[i];
        {
            ll w, x, y, z;
            cin >> w >> x >> y >> z;
            forn(i, 3, n)
                h[i] = (w * h[i - 2] + x * h[i - 1] + y) % z;
        }
        forn(i, 1, n)
            pos[i] = INF, neg[i] = INF;
        forn(i, 1, m) {
            cin >> fr[i] >> to[i] >> up[i] >> dw[i];
            if (fr[i] < to[i])
                forn(j, fr[i] + 1, to[i])
                    pos[j] = min(pos[j], up[i]), neg[j] = min(neg[j], dw[i]);
            else
                forn(j, to[i] + 1, fr[i])
                    pos[j] = min(pos[j], dw[i]), neg[j] = min(neg[j], up[i]);
        }

        forn(i, 1, n)
            h[i] *= 2, pos[i] *= 2, neg[i] *= 2;
        //forn(i, 1, n)
        //    cout << h[i] << " ";cerr << "\n";

        //cerr << ok(30) << "\n";return 0;
        int l = 0, r = 2e6 + 1e5;
        while (l < r) {
            ll m = (l + r) / 2;
            if (!ok(m)) l = m + 1;
            else r = m;
        }
        cout << fixed;
        cout << ld(l) / 2 << "\n";
    }

    return 0;
}
