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

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        //int g = __gcd(x, y);
        //x /= g, y /= g;
        //g = __gcd(a, b);
        //a /= g, b /= g;
        if ((x < y) && (a == b)) {
            cout << "-1\n";
            continue;
        }
        //cerr << x << " " << y << " " << a << " " << b << "\n";
        ll l = 1, r = 1e9;
        while (l < r) {
            ll m = (l + r) / 2;
            ll K = (b * m) - y;
            ll k = (a * m) - x;
            if (K < 0 || k > K || k < 0) l = m + 1;
            else r = m;
        }
        ll K = (b * l) - y;
        ll k = (a * l) - x;
        if (K < 0 || k > K || k < 0)
            cout << "-1\n";
        else
            cout << K << "\n";
    }

    return 0;
}
