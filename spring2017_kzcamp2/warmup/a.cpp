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

const int N = 1e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, k;
map <int, int> x2i, y2i;
int sx, sy;

int ix(int x) {
    if (x2i.count(x) == 0) x2i[x] = ++sx;
    return x2i[x];
}

int iy(int y) {
    if (y2i.count(y) == 0) y2i[y] = ++sy;
    return y2i[y];
}

vector <pii> gx[N], gy[N];
int Sx[N], Sy[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    forn(it, 1, k) {
        int xb, yb, xe, ye;
        cin >> xb >> yb >> xe >> ye;
        if (xb == xe) {
            int i = ix(xb);
            gx[i].pb({min(yb, ye), max(yb, ye)});
        }
        else {
            int i = iy(yb);
            gy[i].pb({min(xb, xe), max(xb, xe)});
        }
    }
    int ans = 0, frow = 0, fcol = 0;
    if ((n - 1 - sx) % 2 == 1) ans ^= m, frow = 1;
    if ((m - 1 - sy) % 2 == 1) ans ^= n, fcol = 1;

    for (auto row : x2i) {
        int x = row.S;
        sort(gx[x].begin(), gx[x].end());
        int r = 0, sum = 0;
        for (auto p : gx[x]) {
            if (p.S <= r) continue;
            sum += p.S - r - max(0, p.F - r);
            r = p.S;
        }
        Sx[x] = sum;
        ans ^= (m - sum);
    }
    for (auto col : y2i) {
        int y = col.S;
        sort(gy[y].begin(), gy[y].end());
        int r = 0, sum = 0;
        for (auto p : gy[y]) {
            if (p.S <= r) continue;
            sum += p.S - r - max(0, p.F - r);
            r = p.S;
        }
        Sy[y] = sum;
        ans ^= (n - sum);
    }
    if (ans == 0) {
        cout << "SECOND\n";
        return 0;
    }
    cout << "FIRST\n";

    if (frow && (ans ^ m) < m)
            forn(i, 1, sx + 1)
                if (x2i.count(i) == 0) {
                    cout << i << " 0 " << i << " " << m - (ans ^ m) << "\n";
                    return 0;
                }
    if (fcol && (ans ^ n) < n)
            forn(i, 1, sy + 1)
                if (y2i.count(i) == 0) {
                    cout << "0 " << i << " " << n - (ans ^ n) << " " << i << "\n";
                    return 0;
                }
    for (auto row : x2i) {
        int x = row.S;
        int v = m - Sx[x];
        if ((ans ^ v) < v) {
            v = v - (ans ^ v);
            int r = 0;
            for (auto p : gx[x]) {
                if (p.S <= r) continue;
                if (p.F > r) {
                    if (v <= p.F - r) {
                        cout << row.F << " 0 " << row.F << " " << r + v << "\n";
                        return 0;
                    }
                    v -= p.F - r;
                }
                r = p.S;
            }
            assert(v);
            cout << row.F << " 0 " << row.F << " " << r + v << "\n";
            return 0;
        }
    }
    for (auto col : y2i) {
        int y = col.S;
        int v = n - Sy[y];
        if ((ans ^ v) < v) {
            v = v - (ans ^ v);
            int r = 0;
            for (auto p : gy[y]) {
                if (p.S <= r) continue;
                if (p.F > r) {
                    if (v <= p.F - r) {
                        cout << "0 " << col.F << " " << r + v << " " << col.F << "\n";
                        return 0;
                    }
                    v -= p.F - r;
                }
                r = p.S;
            }
            assert(v);
            cout << "0 " << col.F << " " << r + v << " " << col.F << "\n";
            return 0;
        }
    }

    return 0;
}
