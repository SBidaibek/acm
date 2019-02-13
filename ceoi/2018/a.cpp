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

int n, m;
vi a[N], b[N];
ll d[N][N][K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        a[i].resize(3);
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    cin >> m;
    forn(i, 1, m) {
        b[i].resize(3);
        cin >> b[i][1] >> b[i][0] >> b[i][2];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    forn(i, 1, n) {
        forn(j, 1, m) {
            forn(cash, 0, 50) {
                d[i][j][cash] = max(d[i - 1][j][cash], d[i][j - 1][cash]);
                if (b[j][0] > a[i][0]) {
                    if (cash >= b[j][1])
                        d[i][j][cash] = max(d[i][j][cash],
                                        d[i][j - 1][cash - b[j][1]] + b[j][2]);
                    continue;
                }
                if (cash >= b[j][1])
                    d[i][j][cash] = max(d[i][j][cash],
                                    d[i][j - 1][cash - b[j][1]] + b[j][2]);
                else
                if (cash + a[i][1] >= b[j][1])
                    d[i][j][cash] = max(d[i][j][cash],
                                    d[i - 1][j - 1][cash + a[i][1] - b[j][1]] - a[i][2] + b[j][2]);
                else
                    d[i][j][cash] = max(d[i][j][cash],
                                    d[i - 1][j][cash + a[i][1]] - a[i][2]);
            }
        }
    }

    cout << d[n][m][0] << "\n";

    return 0;
}
