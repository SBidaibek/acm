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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int z[5][5], a[N][N];
bitset <N> b[N];
int ans[N][N];
int cnt[N];

int main() {
    #ifdef black
    #endif // black

    //int K;
    //cin >> K;
    forn(K, 2, 2) {
    char inf[20], ouf[20];
    sprintf(inf, "forbidden%d.in", K);
    sprintf(ouf, "%02d.out", K);
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
    int m, n;
    cin >> m >> n;
    forn(i, 1, m)
        forn(j, 1, m)
            cin >> z[i][j];
    int mx = 1;
    forn(i, 1, n) {
        forn(j, 1, n)
            cin >> a[i][j], cnt[i] += a[i][j], b[i][j] = a[i][j];
        if (cnt[mx] < cnt[i]) mx = i;
        //cerr << i << " " << cnt[i] << "\n";
    }
    forn(i, 1, n)
        ans[mx][i] = a[mx][i], ans[i][mx] = a[i][mx];
    //cout << "#FILE forbidden " << K << "\n";
    cout << n << "\n";
    forn(i, 1, n)
        forn(j, 1, n)
            cout << ans[i][j] << " \n"[j == n];

    forn(i, 1, n)
        forn(j, 1, n)
            a[i][j] = b[i][j] = ans[i][j] = 0;
    forn(i, 1, n)
        cnt[i] = 0;
    }

    return 0;
}
