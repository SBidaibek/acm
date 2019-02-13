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

const int N = 2e5 + 2;
const int K = (1 << 26);
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool bit(int mask, int i) {
    return mask & (1 << i);
}

int n, a[N];
int mba;
bool d[K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        if (a[i] == (1 << 26)) {
            assert(0);
            mba = 1;
            continue;
        }
        a[i] ^= (1 << 26) - 1;
        d[a[i]] = 1;
    }

    forn(i, 0, 25)
        forn(m, 0, (1 << 26) - 1)
            if (bit(m, i))
                d[m ^ (1 << i)] |= d[m];

    int ans = (1 << 26) - 1;
    #define _b __builtin_popcount
    forn(i, 1, n) {
        if (d[i] != 0) continue;
        if (_b(i) < _b(ans)) ans = i;
    }
    if (mba) ans ^= (1 << 26);

    cout << ans << "\n";

    return 0;
}
