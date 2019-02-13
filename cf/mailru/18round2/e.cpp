#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s, m, k;
int a[N], p[N];
int l[N], r[N];
vi q[N];
int d[N][N];

int getmaxbelow(int W) {
    forn(i, 1, n)
        p[i] = p[i - 1] + (a[i] <= W);
    memset(d, 0, sizeof d);
    forn(i, 1, n) {
        forn(j, 1, m) {
            d[i][j] = d[i - 1][j];
            for (auto prv : q[i]) {
                forn(k, prv, i)
                    d[i][j] = max(d[i][j], d[k - 1][j - 1] + p[i] - p[k - 1]);
            }
        }
    }
    int ans = 0;
    forn(i, 1, m)
        ans = max(ans, d[n][i]);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m >> k;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, s) {
        cin >> l[i] >> r[i];
        q[r[i]].pb(l[i]);
    }

    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (getmaxbelow(m) >= k)
            r = m;
        else l = m + 1;
    }
    if (l > 1e9) l = -1;
    cout << l << "\n";

    return 0;
}

