#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e3 + 10;
const int INF = 1e9 + 9;
//const int B = 1e9 + 7;
int B;

void rlx(ll &a, ll b) {
    a = (a + b) % B;
}

int n, k, m;
ll d[N][N], p[N][N], c[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> B;

    forn(i, 0, n + n)
        forn(j, 0, i)
            c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % B : 1;

    d[0][0] = 1;
    forn(j, 0, k - 1) {
        forn(i, 0, n) {
            if (!d[j][i]) continue;

            forn(add, 0, n - i) {
                if (i == 0) {
                    rlx(d[j + 1][i + add], d[j][i]);
                    continue;
                }
                ll q = 1;
                forn(fadd, 0, n - i - add) {
                    rlx(d[j + 1][add + i + fadd],
                    d[j][i] * (add ? c[i + add - 1][add] : 1) % B * q);
                    //cerr << j << " " << i << " -> " << j + 1 << " " << i + add + fadd
                    //<< "| " << d[j][i] * (add ? c[i + add - 1][add] : 1) % B * q << "\n";
                    if (fadd == 0) q = (i + add  + 1) % B;
                }
            }
        }
    }
    forn(j, 0, k)
        forn(i, 0, n)
            cerr << j << " " << i << " " << d[j][i] << "\n";
    cout << d[k][n] << "\n";

    return 0;
}
