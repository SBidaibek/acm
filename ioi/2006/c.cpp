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

bitset <N> a[N];
int ans[N][N];
int cnt[N];

int main() {
    #ifdef black
    #endif // black

    //int K;
    //cin >> K;
    forn(K, 1, 2) {
    char inf[20], ouf[20];
    sprintf(inf, "forbidden%d.in", K);
    sprintf(ouf, "%02d.out", K);
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
    int m, n;
    cin >> m >> n;
    int mx = 1;
    forn(i, 1, n) {
        forn(j, 1, n)
            cin >> a[i][j], cnt[i] += a[i][j];
        if (cnt[mx] < cnt[i]) mx = i;
    }

    cout << "#FILE forbidden " << K << "\n";
    cout << n << "\n";
    forn(i, 1, n)
        forn(j, 1, n)
            cout << ans[i][j] << " \n"[j == n];
    }

    return 0;
}
