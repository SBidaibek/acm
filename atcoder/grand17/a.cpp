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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll d[2];
    d[1] = 0;
    d[0] = 1;
    int n, p;
    cin >> n >> p;
    forn(i, 1, n) {
        int x;
        cin >> x;
        x %= 2;
        if (x == 0)
            d[0] *= 2, d[1] *= 2;
        else {
            ll y = d[0], z = d[1];
            d[0] += z, d[1] += y;
        }
    }
    cout << d[p] << "\n";

    return 0;
}
