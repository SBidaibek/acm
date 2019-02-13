#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, c[N], a[N], u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> c[i];
    forn(i, 1, n)
        cin >> a[i];

    ll ans = 0;
    forn(i, 1, n) {
        bool ok = 0;
        int x = i;
        for (; !u[x]; x = a[x]) u[x] = 1;
        if (u[x] == 2) {
            for (x = i; u[x] == 1; x = a[x]) u[x] = 2;
            continue;
        }
        int mn = c[x];
        for (int y = a[x]; y != x; y = a[y])
            mn = min(mn, c[y]);
        ans += mn;
        for (x = i; u[x] == 1; x = a[x]) u[x] = 2;
    }
    cout << ans << "\n";

    return 0;
}

