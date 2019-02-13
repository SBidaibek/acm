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

ll bp(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) res = res * a % B;
    return res;
}

int main() {
    #ifdef black
    freopen("in", "w", stdout);
    #else
    freopen("balls.in", "r", stdin);
    freopen("balls.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n = 1e5, m = 1e5;
    cout << n << " " << m << "\n";
    forn(i, 1, n)
        cout << rand() + 1 << " ";
    cout << "\n";
    forn(i, 1, m) {
        int t = rand() % 2 + 1;
        int x = (t == 1 ? 1 : i);//rand() + 1);
        cout << t << " " << x << "\n";
    }
    //forn(i, 1, 2 * n + 1)
    //    cout << rand() % (2 * n + 1) + 1 << " " << rand() % (2 * n + 1) + 1 << "\n";

    return 0;
}
