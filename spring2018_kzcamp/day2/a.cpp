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

const int N = 2e6 + 1;
const int K = 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];

    ll ans = 1e18, t = 0;
    //forn(x, 0, (1 << K) - 1) {
    forn(j, -1, K - 1) {
        int x = (j == -1 ? 0 : (1 << j));
        ll cur = 0;
        forn(i, 2, n)
            cur += abs((a[i] ^ x) - (a[i - 1] ^ x));
        if (ans > cur) ans = cur, t = x;
    }

    cout << t << " " << ans << "\n";

    return 0;
}
