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

const int N = 3e3 + 10;
const int K = 51;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
vi a[N], b[N];
ll d[3][N * 2][K * 2];

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
    forn(cash, 0, 50)
        d[1][0][cash] = (cash >= b[1][1] ? b[1][2] : 0);
    forn(di, 2, n + m) {
        int q = (di & 1);
        forn(i, 0, n + 1)
            forn(cash, 0, 50)
                d[2][i][cash] = d[q][i][cash];
        if (di <= m) {
            int j = di - 0;
            forn(cash, 0, 50)
                d[q][0][cash] = max(d[q ^ 1][0][cash],
                    cash >= b[j][1] ? d[q ^ 1][0][cash - b[j][1]] + b[j][2] : 0);
        }
        forn(i, max(1, di - m), min(n, di - 1)) {
            int j = di - i;
            forn(cash, 0, 50) {
                d[q][i][cash] = max(d[q ^ 1][i - 1][cash], d[q ^ 1][i][cash]);
                if (b[j][0] > a[i][0]) {
                    if (cash >= b[j][1])
                        d[q][i][cash] = max(d[q][i][cash],
                                        d[q ^ 1][i][cash - b[j][1]] + b[j][2]);
                    continue;
                }
                if (cash >= b[j][1])
                    d[q][i][cash] = max(d[q][i][cash],
                                    d[q ^ 1][i][cash - b[j][1]] + b[j][2]);
                else
                if (cash + a[i][1] >= b[j][1])
                    d[q][i][cash] = max(d[q][i][cash],
                                    d[2][i - 1][cash + a[i][1] - b[j][1]] - a[i][2] + b[j][2]);
                else
                    d[q][i][cash] = max(d[q][i][cash],
                                    d[q ^ 1][i - 1][cash + a[i][1]] - a[i][2]);
            }

        }
    }

    cout << d[(n + m) & 1][n][0] << "\n";

    return 0;
}
