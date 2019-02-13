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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int K = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];
int s[N];
int d[K][K];
int lx[N][2], rx[N][2];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i] * (i % 2 ? -1 : 1);
    }
    ll sum = 0;
    forn(i, 1, n) sum += a[i];

    forn(len, 1, n) {
        forn(l, 1, n - len + 1) {
            int r = l + len - 1;
            d[l][r] = max(
                a[l] + d[l + 1][r] * -1,
                a[r] + d[l][r - 1] * -1
            );
            d[l][r] = max();
            forn(k, l, r) {
=
                if (k == l) d[l][r] = max(d[l][r], sux);
                else
                if (k == r) d[l][r] = max(d[l][r], prx);
                else
                d[l][r] = max(d[l][r], min(prx, sux));
            }
        }
    }

    assert((sum - d[1][n]) % 2 == 0);
    cout << (sum - d[1][n]) / 2 + d[1][n] << " " << (sum - d[1][n]) / 2 << "\n";

    return 0;
}
