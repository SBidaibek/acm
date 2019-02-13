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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

void relax(int &a, int b) {
    a = min(a, b);
}

int n, f, t;
int g[N], a[N];

int d[N][N][2];
int h[N * N], timer;

int slow() {
    forn(i, 1, n)
        forn(j, 1, n)
            d[i][j][0] = d[i][j][1] = INF;
    d[f][f][0] = d[f][f][1] = 0;
    forn(len, 1, n) {
        forn(l, 1, n - len + 1) {
            int r = l + len - 1;
            forn(_, 0, 3) {
                int p = _ % 2;
                if (d[l][r][p] == INF) continue;
                relax(d[l][r][p ^ 1], d[l][r][p] + (r - l));
                ++timer;
                forn(i, l, r) h[a[i]] = timer;
                if (p == 0 && l > 1 && h[g[l - 1]] == timer)
                    relax(d[l - 1][r][p], d[l][r][p] + 1);
                if (p == 1 && r < n && h[g[r]] == timer)
                    relax(d[l][r + 1][p], d[l][r][p] + 1);
            }
        }
    }
    int ans = INF;
    forn(i, 1, n) {
        ans = min(ans, min(d[i][t][0], d[i][t][1]));
        ans = min(ans, min(d[t][i][0], d[t][i][1]));
    }
    return ans == INF ? -1 : ans;
}

int fast() {

}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> f >> t;
    forn(i, 1, n - 1)
        cin >> g[i];
    forn(i, 1, n)
        cin >> a[i];
    if (f > t) {
        reverse(a + 1, a + 1 + n);
        reverse(g + 1, g + n);
        f = n - f + 1;
        t = n - t + 1;
    }

    cout << slow() << "\n";

    return 0;
}
