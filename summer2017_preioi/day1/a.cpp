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
typedef vector <ll> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int tc, n, m;
char a[N][N];
int d[N][N], l[N];

ll t1() {
    ll ans = 0;
    forn(r, 1, n) {
        vi v;
        v.pb(0);
        d[r][0] = -1;
        forn(i, 1, n) {
            d[r][i] = a[r][i] == '0' ? 0 : d[r - 1][i] + 1;
            while (d[r][i] <= d[r][v.back()]) v.pop_back();
            l[i] = v.back();
            v.pb(i);
        }
        v.clear();
        v.pb(n + 1);
        for1(i, n, 1) {
            while (d[r][i] < d[r][v.back()]) v.pop_back();
            ans += 1ll * d[r][i] * (v.back() - i) * (i - l[i]);
            v.pb(i);
        }
    }
    forn(r, 1, n) {
        vi v;
        v.pb(0);
        d[r][0] = -1;
        forn(i, 1, n) {
            d[r][i] = a[r][i] == '1' ? 0 : d[r - 1][i] + 1;
            while (d[r][i] <= d[r][v.back()]) v.pop_back();
            l[i] = v.back();
            v.pb(i);
        }
        v.clear();
        v.pb(n + 1);
        for1(i, n, 1) {
            while (d[r][i] < d[r][v.back()]) v.pop_back();
            ans += 1ll * d[r][i] * (v.back() - i) * (i - l[i]);
            v.pb(i);
        }
    }
    return ans;
}

ll t2(int x) {
    forn(i, 1, n) {
        forn(j, 1, n) {
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            int g = d[i][j] - d[max(0, i - m)][j] - d[i][max(0, j - m)] + d[max(0, i - m)][max(0, j - m)];
            if ((a[i][j] - '0') ^ (g & 1) != x) {
                if (i + m - 1 > n || j + m - 1 > n) return INF;
                ++d[i][j];
            }
        }
    }
    return d[n][n];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> tc >> n >> m;
    forn(i, 1, n)
        forn(j, 1, n)
            cin >> a[i][j];
    if (tc == 1)
        cout << t1() << "\n";
    else {
        int x = min(t2(0), t2(1));
        cout << (x == INF ? -1 : x) << "\n";
    }

    return 0;
}
