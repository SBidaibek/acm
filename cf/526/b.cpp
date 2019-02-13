#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    if (a == b || k == 1) {
        cout << n << "\n";
        return 0;
    }

    ll ans = 0;
    ll cur = 0;
    ll free = 0;
    int i = 0;
    while (a[i] == b[i]) ++i;
    ans = i + 2, k -= 2, cur = 2;
    forn(j, i + 1, n - 1) {
        if (k == 0) {
            ans += ((n - 1) - j + 1) * cur;
            break;
        }
        ans += cur;
        ll sides = (a[j] != 'b') + (b[j] != 'a');
        //ll new_free = free * 2 + sides;
        ll add = min(k, free + sides);
        ans += add;
        cur += add;
        k -= add;
        free += free + sides;
    }

    cout << ans << "\n";

    return 0;
}
