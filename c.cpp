#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long  ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 59, 59) {
        ll q = (1ull << i) - 1;
        vector <ll> v;
        for (ll j = 0; j * j + 9 <= q; ++j) {
            if (q % (j * j + 9) == 0) {
                v.pb(j);
                cerr <<  j << "\n";}
        }
        cout << i << ": ";
        for (auto x : v) cerr << x << " ";
        cerr << "\n";
    }
    return 0;

    forn(i, 1, 50) {
        int k = i * i + 9;
        int ans = 0;
        forn(j, 1, 63) {
            if (((1ull << j) - 1) % k == 0) {
                ans = j;
                break;
            }
        }
        cout << i << ": " << ans << "\n";
    }

    return 0;
}
