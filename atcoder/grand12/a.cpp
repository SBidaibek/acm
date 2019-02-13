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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
int a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n * 3)
        cin >> a[i];
    sort(a + 1, a + 1 + 3 * n);
    int p = n * 3 - 1;
    ll ans = 0;
    forn(i, 1, n) {
        ans += a[p];
        p -= 2;
    }
    cout << ans << "\n";

    return 0;
}
