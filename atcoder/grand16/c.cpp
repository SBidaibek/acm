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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

void yes() {
    cout << "Yes\n";
}

void no() {
    cout << "No\n";
    exit(0);
}

ll a[N][N], d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll C = 10;
    int n, m, h, w;
    cin >> n >> m >> h >> w;
    forn(i, 1, n) {
        forn(j, 1, m) {
            a[i][j] = ((i - 1) % h == 0 && (j - 1) % w == 0 ? C * (h * w - 1) - 1 : -C);
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
            if (i >= h && j >= w) {
                if (d[i][j] - d[i - h][j] - d[i][j - w] + d[i - h][j - w] >= 0)
                    no();
            }
        }
    }
    if (d[n][m] <= 0) no();
    yes();
    forn(i, 1, n) {
        forn(j, 1, m)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
