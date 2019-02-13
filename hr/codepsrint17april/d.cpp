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

const int N = 3e3 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

ll f[N], d[N][N], c[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    d[1][0] = 1;
    forn(n, 1, 3e3) {/*
        vi v;
        forn(i, 1, n) v.pb(i);
        do {
            vi t(1, 0);
            forn(i, 1, n)
                t.pb(v[i - 1]);
            t.pb(0);
            int k = 0;
            forn(i, 1, n)
                if (t[i] < t[i - 1] || t[i] < t[i + 1]) ++k;
            ++c[n][k];
        } while (next_permutation(v.begin(), v.end()));*/
        forn(k, 0, n) {
            int j = n - k;
            int p = (n + 1) - (2 * j);
            d[n + 1][k + 1] = (d[n + 1][k + 1] + d[n][k] * 2 * j) % B;
            d[n + 1][k] = (d[n + 1][k] + d[n][k] * p) % B;
        }
    }
    int q;
    cin >> q;
    forn(i, 1, q) {
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        forn(i, k, n - 1)
            ans = (ans + d[n][i]) % B;
        cout << ans << "\n";
    }

    return 0;
}
