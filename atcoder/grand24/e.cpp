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

const int N = 5e2 + 10;
const int INF = 1e9 + 9;
//const int B = 1e9 + 7;
int B;

void rlx(ll &a, ll b) {
    a = (a + b) % B;
}

int n, k, m;
ll d[N][N], c[N][N], p[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> B;

    forn(i, 0, n + 10)
        forn(j, 0, i)
            c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % B : 1;

    forn(i, 0, k) d[1][i] = 1;
    for1(j, k, 0)
        p[1][j] = (p[1][j + 1] + d[1][j]) % B;
    forn(i, 2, n + 1) {
        forn(j, 0, k) {
            forn(ni, 1, i - 1) {
                ll cur = p[ni][j + 1] * d[i - ni][j] % B;
                cur = cur * c[i - 2][ni - 1] % B;
                rlx(d[i][j], cur);
            }
        }
        for1(j, k, 0)
            p[i][j] = (p[i][j + 1] + d[i][j]) % B;
    }

    cout << d[n + 1][0] << "\n";

    return 0;
}
