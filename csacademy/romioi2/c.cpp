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

const int N = 5e3 + 100;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
struct elem {
    int l, r, c;
    elem() {}
} a[N];

int d[N][N];
int c[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) {
        cin >> a[i].l >> a[i].r >> a[i].c;
        --a[i].r;
    }
    sort(a + 1, a + 1 + n, [](elem x, elem y) {
        return x.r < y.r;
    });
    int r = 0;
    forn(i, 1, n)
        r = max(r, a[i].r);
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int ans = 0;
    forn(i, 0, n)
        forn(j, i + 1, n) {
            forn(k, j, n)
                if (a[i].r < a[k].l && a[k].l <= a[j].r && a[k].l <= a[k].r)
                    c[i][j] += a[k].c;
        }
    forn(i, 0, n) {
        forn(j, 0, m) {
            if (d[i][j] < 0) continue;
            ans = max(ans, d[i][j]);
            if (j == m) continue;
            forn(nxt, i + 1, n) {
                d[nxt][j + 1] = max(d[nxt][j + 1], d[i][j] + c[i][nxt]);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
