#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int b[11][N];
int a[11][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    forn(i, 1, m)
        forn(j, 1, n) {
            cin >> a[i][j];
            b[i][a[i][j]] = j;
        }
    ll ans = 0;
    forn(i, 1, n) {
        forn(len, 1, n - i + 2) {
            bool ok = (i + len - 1 <= n);
            forn(j, 1, m) {
                ok &= (a[1][i + len - 1] == a[j][b[j][a[1][i]] + len - 1]);
                if (!ok) break;
            }
            if (!ok) {
            if (len > 1) i += len - 2; ans += (1ll * len * (len - 1)) / 2; break;}
        }
    }
    cout << ans << "\n";

    return 0;
}

