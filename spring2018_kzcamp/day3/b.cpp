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

const int N = 200 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
int d[N][N][N][2], g[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(_, 1, ts) {
        cin >> n;
        vi div;
        forn(i, 1, n)
            if (n % i == 0) div.pb(i);
        int sz = div.size();
        if (sz == 2) {
            cout << n - 1 << "\n";
            continue;
        }
        forn(i, 1, n) g[i] = __gcd(i, n);
        int ans = 0;
        for1(i, n, 1) {
            forn(j, 0, sz - 1) {
                forn(k, 0, sz - 1) {
                    forn(t, 0, 1) {
                        if (j == sz - 1 || k == sz - 1) {
                            if (t == 0)
                                d[i][j][k][t] = (j == sz - 1 ? -1 : +1);
                            else
                                d[i][j][k][t] = (k == sz - 1 ? -1 : +1);
                            continue;
                        }
                        int x = (t == 0 ? div[j] : div[k]);
                        int ptr = (t == 0 ? j : k);
                        d[i][j][k][t] = -1;
                        forn(q, i, n - 1) {
                            x *= g[q];
                            x = __gcd(x, n);
                            while (div[ptr] < x) ++ptr;
                            if ((t == 0 ? d[q + 1][ptr][k][t ^ 1] : d[q + 1][j][ptr][t ^ 1]) == -1) {
                                if (i == 1 && j == 0 && k == 0 && t == 0)ans = q;
                                if (i == 7 && j == 4 && k == 6 && t == 0) cerr << q << "!\n";
                                d[i][j][k][t] = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cerr << d[4][0][4][0] << "\n";
        cout << ans << "\n";
    }

    return 0;
}
