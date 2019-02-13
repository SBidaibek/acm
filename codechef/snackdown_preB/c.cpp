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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

char a[3][N];
int d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(_, 1, ts) {
        int n;
        cin >> n;
        int c = 0;
        forn(i, 1, 2) {
            bool u = 0;
            forn(j, 1, n) {
                cin >> a[i][j];
                u |= (a[i][j] == '*');
                d[j] = 0;
            }
            c += u;
        }
        int ans = 0;
        if (c == 2) ans = 1;
        int p1 = -1, p2 = -1;
        forn(i, 1, n) {
            if (a[1][i] == '.' && a[2][i] == '.') {
                d[i] = d[i - 1];
                continue;
            }
            if (a[1][i] == '*' && a[2][i] == '*') {
                if (p1 != -1 || p2 != -1)
                    d[i] = d[i - 1] + 1;
                else
                    d[i] = 0;
                p1 = i, p2 = i;
                continue;
            }
            if (a[1][i] == '*') {
                if (p1 != -1) {
                    d[i] = d[i - 1] + 1;
                    if (p2 > p1) d[i] = d[p2 - 1] + 1;
                }
                else
                    d[i] = 0;
                p1 = i;
            }
            if (a[2][i] == '*') {
                if (p2 != -1) {
                    d[i] = d[i - 1] + 1;
                    if (p1 > p2) d[i] = d[p1 - 1] + 1;
                }
                else
                    d[i] = 0;
                p2 = i;
            }
        }
        ans += d[n];
        bool f = 0;
        forn(i, 1, n)
            if (a[1][i] == '*' && a[2][i] == '*') f = 1;
        if (!f) {
            int s = 0;
            forn(i, 1, n)
                s += (a[1][i] == '*') + (a[2][i] == '*');
            ans = min(ans, max(0, s - 1));
        }
        cout << ans << "\n";
    }

    return 0;
}
