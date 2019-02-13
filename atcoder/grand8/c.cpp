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

ll a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 1, 7)
        cin >> a[i];

    ll ans = 0;
    ans = max(ans, (a[1] / 2 + a[4] / 2 + a[5] / 2) * 2);
    if (a[1] && a[4] && a[5])
        ans = max(ans, 3 * ((a[1] - 1) / 2 + (a[4] - 1) / 2 + (a[5] - 1) / 2) * 2);
    ll mn = min(a[1], min(a[4], a[5]));
    ans = max(ans, 3 * mn + ((a[1] - mn) / 2 + (a[4] - mn) / 2 + (a[5] - mn) / 2) * 2);

    cout << ans + a[2] << "\n";

    return 0;
}

