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

int n;
char a[4][N];
int d[N][4];

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
        cin >> n;
        forn(i, 1, 3)
            forn(j, 1, n)
                cin >> a[i][j];
        if (a[1][1] == '#' || a[2][1] == '#' || a[2][n] == '#' || a[3][n] == '#') {
            cout << "0\n";
            continue;
        }
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        d[1][2] = 1;
        forn(i, 2, n) {
            d[i][1] = d[i][2] = d[i][3] = 0;
            if (a[1][i] == '.' && a[2][i] == '.')
                d[i][1] = d[i - 1][2], d[i][2] = d[i - 1][1];
            if (a[3][i] == '.' && a[2][i] == '.')
                d[i][3] = d[i - 1][2], d[i][2] = (d[i - 1][3] + d[i][2]) % B;
        }
        cout << d[n][3] << "\n";
    }

    return 0;
}
