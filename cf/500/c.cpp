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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];
int d[N][N][4], ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];

    a[0] = -1;
    forn(i, 1, n) {
        forn(j, 0, n) {
            forn(s, 0, 3)
                d[i][j][s] = INF;
            if (i == 1) {
                d[1][0][0] = 0;
                d[1][0][2] = max(0, a[1] - a[2] + 1);
                d[1][0][3] = 0;
                continue;
            }
            d[i][j][0] = min(min(d[i - 1][j][0], d[i - 1][j][1]), min(d[i - 1][j][2], d[i - 1][j][3]));
            d[i][j][1] = d[i - 1][j - 1][3] + max(0, a[i] - a[i - 1] + 1);
            d[i][j][2] = d[i][j][0] + max(0, a[i] - a[i + 1] + 1);
            if (a[i + 1] >= a[i - 1])
                d[i][j][2] = min(d[i][j][2], d[i][j][1]);
            else
                d[i][j][2] = min(d[i][j][2], d[i - 1][j - 1][3] + max(0, a[i] - a[i + 1] + 1));
            d[i][j][3] = d[i - 1][j][2];
            //forn(s, 0, 3)
            //    cerr << i << " " << j << " " << s << ": " << d[i][j][s] << "\n";
        }
    }
    forn(i, 1, (n + 1) / 2) {
        ans[i] = min(min(d[n][i][0], d[n][i][1]), d[n][i - 1][3]);
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
