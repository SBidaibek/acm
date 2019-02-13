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

const int N = 15000;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll f[N], d[N][21];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[1] = 1, f[2] = 2;
    forn(i, 3, N - 1)
        f[i] = (f[i - 1] + f[i - 2]);

    forn(i, 0, 20) d[0][i] = 1;
    forn(i, 1, f[15] * 15) {
        forn(j, 1, 20)
            d[i][j] = (d[i][j - 1] + (i >= f[j] ? d[i - f[j]][j - 1] : 0)) % B;
    }

    int n;
    cin >> n;
    ll s = 0;
    forn(i, 1, n) {
        int x;
        cin >> x;
        s += f[x];
        cout << d[s][20] << "\n";
    }

    return 0;
}
