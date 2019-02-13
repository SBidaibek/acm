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

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    int ans = 2e9 + 30;
    if (x <= y)
        ans = min(ans, y - x);
    if (-x <= y)
        ans = min(ans, y + x + 1);
    if (x <= -y)
        ans = min(ans, -y - x + 1);
    if (-x <= -y)
        ans = min(ans, -y + x + 2);
    cout << ans << "\n";

    return 0;
}
