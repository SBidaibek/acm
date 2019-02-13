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

const int N = 3e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
ll a[N], b[N], p;
ll d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, m)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ll ans = 0;
    forn(i, 1, n)
        forn(j, 0, m)
            d[i][j] = INF;
    d[0][0] = 0;
    forn(i, 1, n) {
        ll mn = i == 1 ? 0 : INF;
        d[i][0] = INF;
        forn(j, 1, m) {
            d[i][j] = min(d[i][j - 1], max(abs(a[i] - b[j]) + abs(b[j] - p), mn));
            mn = min(mn, d[i - 1][j]);
        }
    }

    cout << d[n][m] << "\n";

    return 0;
}
