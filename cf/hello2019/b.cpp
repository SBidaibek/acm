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

    int n;
    cin >> n;
    vi a(n);
    forn(i, 0, n - 1)
        cin >> a[i];
    forn(mask, 0, (1 << n) - 1) {
        int sum = 0;
        forn(i, 0, n - 1)
            sum += ((mask & (1 << i)) ? 1 : -1) * a[i];
        if (sum % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
