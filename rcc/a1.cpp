#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << lcm(a, c) << " " << gcd(b, d) << "\n";
    }
}
