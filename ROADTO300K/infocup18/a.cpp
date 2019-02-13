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

int n, m;
int a[N][N];
int b[N][N];
int di[] = {0, -1, 0, +1};
int dj[] = {-1, 0, +1, 0};

bool in(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector <pii> v;
    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            v.pb({a[i][j], (i - 1) * m + j - 1});
        }
    sort(v.begin(), v.end());

    int ans = -1;
    for (auto p : v) {
        int j = p.S % m + 1, i = p.S / m + 1;
        b[i][j] = -a[i][j] - 1;
        forn(d, 0, 3) {
            int ni = i + di[d], nj = j + dj[d];
            if (!in(ni, nj) || a[ni][nj] > a[i][j]) continue;
            b[i][j] = max(b[i][j], b[ni][nj] - 1);
        }
        cerr << i << " " << j << ": " << a[i][j] << " " << b[i][j] << "\n";
        ans = max(ans, a[i][j] + b[i][j]);
    }

    cout << ans << "\n";

    return 0;
}
