#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <ll> vi;

const int N = 1e5 + 10;
const int K = 7e3 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

short g[K][K];
bitset <K> b[N], tmp;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 0, K - 1)
        g[i][0] = g[0][i] = i;
    forn(i, 1, K - 1)
        forn(j, 1, K - 1)
            g[i][j] = i > j ? g[i - j][j] : g[i][j - i];

    int n, q;
    cin >> n >> q;
    forn(it, 1, q) {
        int tp, x, v, z;
        cin >> tp >> x >> v;
        if (tp == 2 || tp == 3) cin >> z;
        if (tp == 1) {
            b[x].reset();
            b[x].set(v);
        }
        if (tp == 2) {
            b[x] = b[v] ^ b[z];
        }
        if (tp == 3) {
            tmp.reset();4к

            for (int i = b[v]._Find_first(); i < K; i = b[v]._Find_next(i))
                for (int j = b[z]._Find_first(); j < K; j = b[z]._Find_next(j))
                    tmp.flip(g[i][j]);
            b[x] = tmp;
        }
        if (tp == 4) {
            putchar('0' + b[x][v]);
        }
    }


    return 0;
}
