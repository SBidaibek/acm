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

    int n, b;
    cin >> b >> n;
    vi a(n + 1);
    forn(i, 1, n)
        cin >> a[i];
    ll p = 1;
    ll ans = 0;
    for1(i, n, 1) {
        ans = (ans + p * a[i]) % 2;
        p = p * b % 2;
    }
    cout << (ans == 0 ? "even" : "odd") << "\n";

    return 0;
}
