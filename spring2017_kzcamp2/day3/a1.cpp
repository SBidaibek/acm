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
    freopen("in", "r", stdin);
    #else
    freopen("balls.in", "r", stdin);
    freopen("balls.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    ll c = 1, f = 1;
    forn(i, 1, k)
        c = c * (n - i + 1) % B, f = f * i % B;
    cout << (c * bp(f, B - 2)) % B * c % B << "\n";

    return 0;
}
