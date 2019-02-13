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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, s, t[N];
ll a[N], b[N];

bool ok(ll k) {
    b[n] = k;
    ll pa = n, pb = n - 1;
    ll xa = b[n] - s, xb = b[n] - 1;
    while (pa > 0) {
        cerr << pa << " " << xa << " | " << pb << " " << xb << "\n";
        if (pa > pb && xa > xb) {
            if (xa < t[pa]) return 0;
            a[pa] = xa;
            if (xb < xa + s) xb = min(xb, xa - s);
            xa = xa - 1;
            --pa;
        }
        else {
            if (pb == 0) return 0;
            b[pb] = xb;
            if (xa < xb + s) xa = min(xa, xb - s);
            xb = xb - 1;
            --pb;
        }
    }
    forn(i, 1, n) cerr << b[i] << " ";cerr << "\n";
    forn(i, 1, n) cerr << a[i] << " ";cerr << "\n";
    return a[1] >= t[1];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    forn(i, 1, n) cin >> t[i];
    ll l = t[1], r = 1e18;
    cerr << ok(20) << "\n";
    return 0;
    while (l < r) {
    //cerr << l << " " << r << "\n";
        ll m = (l + r) / 2;
        if (ok(m)) r = m;
        else l = m + 1;
    }
    cout << l + s << "\n";
    return 0;

    return 0;
}
