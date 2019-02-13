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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k;
ll a[N];

ll g(int l, int r) {
    ll ans = 1;
    for (l += n - 1, r += n - 1;  l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans = (ans * a[l++]) % k;
        if (r % 2 == 0) ans = (ans * a[r--]) % k;
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n) {
        int x = 0;
        cin >> x;
        a[i + n - 1] = x % k;
    }
    for1(i, n - 1, 1)
        a[i] = (a[i * 2] * a[i * 2 + 1]) % k;
    ll ans = 0;
    forn(i, 1, n) {
        if (g(i, n) != 0) break;
        int l = i, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (g(i, m) == 0) r = m;
            else l = m + 1;
        }
        ans +=  n - l + 1;
    }
    cout << ans << "\n";

    return 0;
}
