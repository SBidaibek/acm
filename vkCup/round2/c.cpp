/*
 _    _    _______   _    _
| |  / /  |  _____| | |  / /
| | / /   | |       | | / /
| |/ /    | |_____  | |/ /
| |\ \    |  _____| | |\ \
| | \ \   | |       | | \ \
| |  \ \  | |_____  | |  \ \
|_|   \_\ |_______| |_|   \_\

*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair < ll, int > PLI;


#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define right(x) x << 1 | 1
#define left(x) x << 1
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mkp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define y1 kekekek

#define fname ""

const ll ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const ld eps = 1e-7;
const int N = 2e6 + 6;

int main() {
	ios_base :: sync_with_stdio(0), cin.    tie(0), cout.tie(0);

    #ifdef black
    freopen("in", "r", stdin);
    #endif // black.out", "w", stdout);


    int n;
    cin >> n;
    ll cnt = 0;
    ll ans = 0;
    ll kek = 0;
    forn(i, 1, n) {
        ll x;
        cin >> x;
        if (x < cnt) {
            ++kek;
            ans += cnt - x - 1;
            continue;
        }x`x
        if (x == cnt) {
            cnt++;
            continue;
        }
        if (x > cnt) {
            int a = 0;
            while (x > cnt && kek) {
                ++cnt;
                --kek;
                ++a;
            }
            ll dif = x - cnt;
            ans += a * (a + 1) / 2 + dif * (dif + 1) / 2;
            cnt = x + 1;
            continue;
        }
    }

    cout << ans << "\n";

	return 0;
}
