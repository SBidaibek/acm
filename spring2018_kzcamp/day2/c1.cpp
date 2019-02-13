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

const int N = 30 + 1;
const int K = (1 << 20);
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
pii a[N];
int p[N];
int d[N][K], u[N][K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].F >> a[i].S;
    sort(a + 1, a + 1 + n);
    forn(i, 1, n) {
        for1(j, i - 1, 1)
            if (a[j].F < a[i].S) {
                p[i] = j;
                break;
            }
        assert(p[i] >= p[i - 1]);
    }
    d[1][1] = 1;
    u[1][1] = 1;
    int ans = 0;
    forn(i, 1, n) {
        forn(mask, 0, (1 << i) - 1) {
            if (!u[i][mask]) continue;
            bitset <5> b(mask);
            cerr << a[i].F << " - " << i << " " << b << ": " << d[i][mask] << "\n";
            if (i == n) {
                bool ok = 1;
                forn(i, 1, n)
                    forn(j, i + 1, n)
                        if ((mask & (1 << (i - 1))) && (mask & (1 << (j - 1))) && i <= p[j])
                            ok = 0;
                ans += ok;
                continue;
            }
            int to = mask | (1 << i);
            u[i + 1][to] = 1;
            d[i + 1][to] = (d[i + 1][to] + d[i][mask]) % B;
            forn(k, 1, p[i + 1])
                if (mask & (1 << (k - 1)))
                    u[i + 1][to ^ (1 << (k - 1))] = 1,
                    d[i + 1][to ^ (1 << (k - 1))] = (d[i + 1][to ^ (1 << (k - 1))] + d[i][mask]) % B;
        }
    }
    cout << ans << "\n";

    return 0;
}
