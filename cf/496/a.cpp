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

int get(ll a, ll b) {
    cout << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    int a = 0, b = 0, x = 0, y = 0;
    if (get(2, 1) == 3)
    cin >> n >> d;
    forn(i, 1, n)
        cin >> a[i];
    int ans = 2;
    forn(i, 2, n) {
        if (a[i] - a[i - 1] >= 2 * d) ++ans;
        if (a[i] - a[i - 1] > 2 * d) ++ans;
    }
    cout << ans << "\n";

    return 0;
}
