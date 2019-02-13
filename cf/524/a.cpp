#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll s(ll x) {
    return x * (x + 1) / 2;
}

ll f(ll x) {
    if (x == 0) return 0;
    int o = (x + 1) / 2;
    return -(2 * s(o - 1) + o) + (s(x - o) * 2);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    forn(i, 1, q) {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << "\n";
    }

    return 0;
}
