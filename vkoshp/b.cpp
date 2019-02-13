#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9  + 9;
const int B = 1e9 + 7;
const int K = 400;

int n, m;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n = 100;
    int ans = 0;
    forn(i, 1, n) {
        forn(j, 1, i - 1) {
            forn(k, j + 1, i - 1) {
                if (k % __gcd(i, j) == 0) {++ans;break;}
                //cerr << i << " " << j << " " << k << "\n";}
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
