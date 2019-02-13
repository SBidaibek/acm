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
typedef vector <int> vi;

const int N = 6e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

int n, m, d, k;
string s[N];
vi a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d >> k;
    a[0].resize(m + 2);
    a[n + 1].resize(m + 2);
    forn(i, 1, n) {
        s[i].resize(m + 2);
        a[i].resize(m + 2);
        forn(j, 1, m)
            cin >> s[i][j];
    }
    forn(i, 1, n)
        forn(j, 1, m)
            if (s[i][j] == 'S') {
                a[max(1, i - d)][max(1, j - d)]++;
                a[max(1, i - d)][min(m, j + d) + 1]--;
                a[min(n, i + d) + 1][max(1, j - d)]--;
                a[min(n, i + d) + 1][min(m, j + d) + 1]++;
            }
    int ans = 0;
    forn(i, 1, n) {
        forn(j, 1, m) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (s[i][j] == 'M' && a[i][j] >= k) ++ans;
        }
    }

    cout << ans << "\n";

    return 0;
}

