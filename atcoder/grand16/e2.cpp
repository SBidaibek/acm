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
typedef vector <int> vi;

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;
const int K = 1e3;

int n, m;
int f[N], t[N];
int u[K][K], shit[K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m)
        cin >> f[i] >> t[i];
    forn(i, 1, n) {
        u[i][i] = 1;
        for1(j, m, 1) {
            int a = f[j], b = t[j];
            if (!u[i][a] && !u[i][b]) continue;
            if (u[i][a] && u[i][b]) {
                shit[i] = 1;
                break;
            }
            u[i][a] = 1, u[i][b] = 1;
        }
    }
    int ans = 0;
    forn(i, 1, n) {
        forn(j, i + 1, n) {
            if (shit[i] || shit[j]) continue;
            bool fuck = 0;
            forn(k, 1, n)
                if (u[i][k] && u[j][k])
                    fuck = 1;
            if (!fuck) ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}
