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
typedef vector <ll> vi;

const int N = 2e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i != 0) continue;
        ans -= ans / i;
        while (x % i == 0) x /= i;
    }
    if (x > 1) ans -= ans / x;
    return ans;
}

int Gcd(int i, int j) {
    int ans = 0;
    while (i > 1 || j > 1) {
        if (i > j) {
            ans += i / j, i %= j;
            if (!i && j > 1) return 1e9;
        }
        else {
            ans += j / i, j %= i;
            if (!j && i > 1) return 1e9;
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("output", "w", stdout);
    #else
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--) {
        int k;
        cin >> k;
        k += 2;
        cout << phi(k) << "\n";
        int m = 1, z = Gcd(1, k - 1);
        for1(i, k / 2, 1) {
            int x = Gcd(i, k - i);
            if (x < z)
                {m = i, z = x;}
        }
        vi v;
        for (int i = m, j = k - m; i > 1 || j > 1;) {
            if (i > j) {
                v.pb(0);
                i -= j;
            }
            else {
                v.pb(1);
                j -= i;
            }
        }
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
