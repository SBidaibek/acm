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
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int d[2][N];

void relax(int n, int k, int val) {
    d[n][k] += val;
    if (d[n][k] >= B) d[n][k] -= B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    d[0][0] = 1;
    forn(i, 0, n - 1) {
        forn(j, 0, k) {
            if (j < k)
                relax((i & 1) ^ 1, j + 1, a * d[i & 1][j] % B),
                relax((i & 1) ^ 1, 0, b * d[i & 1][j] % B);
            else
                relax((i & 1) ^ 1, k, (a + b) * d[i & 1][j] % B);
            d[i & 1][j] = 0;
        }
    }
    cout << d[n & 1][k] << "\n";

    return 0;
}
