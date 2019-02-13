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

const int N = 5e3 + 1;
const int INF = 1e9 + 9;
const int B = 666013;

int cx[N], cy[N];
int tp[N][N];
int r1, c1, r2, c2, r3, c3, r4, c4;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> r4 >> c4;
    int X = max(max(max(r1, c1), max(r2, c2)), max(max(r3, c3), max(r4, c4)));
    if (r1 > r3) {
        swap(r1, r3); swap(c1, c3);
        swap(r2, r4); swap(c2, c4);
    }
    forn(i, 0, X)
        cx[i] = max(0, min(r2 + i, r4) - max(r1 + i, r3) + 1) + max(0, min(r4 + i, r2) - max(r3 + i, r1) + 1) ;
    if (c1 > c3) {
        swap(r1, r3); swap(c1, c3);
        swap(r2, r4); swap(c2, c4);
    }
    forn(i, 0, X)
        cy[i] = max(0, min(c2 + i, c4) - max(c1 + i, c3) + 1);
    forn(i, 0, X)
        cerr << i << ": " << cx[i] << " " << cy[i] << "\n";
    forn(i, 0, N - 1) {
        tp[i][0] = 1;
        forn(j, 1, i)
            tp[i][j] = (tp[i - 1][j - 1] + tp[i - 1][j]) % B;
    }
    ll ans = 0;
    forn(i, 0, X)
        forn(j, 0, X)
            ans = (ans + 1ll * tp[i + j][i] * cx[i] * cy[j]) % B;
    cout << ans << "\n";

    return 0;
}

