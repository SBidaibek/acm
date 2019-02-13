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

int ans[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    forn(it, 1, q) {
        ll x;
        cin >> x;
        int i = 0;
        while ((1ll << i) - 1 < x) ++i;
        if ((1ll << i) - 1 == x)
            cout << ans[i] << "\n";
        else
            cout << (1ll << i) - 1 << "\n";
    }

    return 0;
}
