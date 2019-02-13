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
typedef vector <int> vi;

const int N = 6e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    ll p = n * m;
    if (p % 2 == 1) --p;

    if (n % 6 == 0 || m % 6 == 0) {
        cout << p << "\n";
        return 0;
    }
    if (n % 4 == 0 || m % 4 == 0) {
        cout << p << "\n";
        return 0;
    }
    int c0 = 0, c2 = 0, c3 = 0;
    forn(i, 1, 2) {
        if (n % 2 == 0) ++c2;
        else
        if (n % 3 == 0) ++c3;
        else
        ++c0;
        swap(n, m);
    }
    if (c3 == 2) {
        cout << p << "\n";
        return 0;
    }
    if (c3 && c0) {

    }

    return 0;
}

