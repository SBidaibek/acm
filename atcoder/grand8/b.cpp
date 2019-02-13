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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, a[N];
ll p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    ll ans = 0;
    forn(i, 1, n - k) {
        p[i] = p[i - 1];
        if (a[i] > 0) p[i] += a[i];
    }
    ans = p[n - k];
    ll mx = 0, s = 0;
    for1(i, n, n - k + 1) {
        s += a[i];
        if (i == n - k + 1)
            mx = max(mx, s + p[n - k]);
        else
            if (i - k >= 1)
                mx = max(mx, s + p[i - k - 1]);
    }
    ans = max(ans, mx);
    cout << ans << "\n";

    return 0;
}

