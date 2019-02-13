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

const int N = 2e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, a[N];
bitset <N * N> d;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    int s = 0;
    forn(i, 1, n) {
        cin >> a[i];
        d |= (d << a[i]);
        s += a[i];
    }
    forn(i, max(1, s / 2), s)
        if (d[i]) {cout << i << "\n"; return 0;}

    return 0;
}
