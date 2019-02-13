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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vi a;
    ll ans = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        a.pb(0);
        ans *= i;
        while (n % i == 0) n /= i, ++a.back();
    }
    if (n > 1) a.pb(1), ans *= n;
    cout << ans << " ";
    int mx = 0;
    forn(i, 0, a.size() - 1)
        mx = max(mx, a[i]);
    bool eq = 1;
    forn(i, 0, a.size() - 1)
        eq &= (a[i] == mx);
    if (mx <= 1) {
        cout << "0\n";
        return 0;
    }
    int ln = 0;
    while ((1 << ln) < mx) ++ln;
    if (!eq || (1 << ln) != mx) ++ln;
    cout << ln << "\n";

    return 0;
}

