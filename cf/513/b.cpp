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

int s(ll x) {
    int ans = 0;
    for (; x; x /= 10) ans += x % 10;
    return ans;
}

int f(int x) {
    int ans = 0;
    forn(i, 1, x / 2)
        ans = max(ans, s(i) + s(x - i));
    forn(i, 1, x / 2)
        if (s(i) + s(x - i) == ans)
            return x - i;
}

ll q(ll n) {
    if (n <= 9)
        return n - 1;
    vi v;
    for (ll x = n; x; x /= 10) v.pb(x % 10);
    ll a = (v.back() - 1);
    for1(i, v.size() - 2, 0)
        a = a * 10 + 9;
    return a;
}

class Rofl {
    public:
    static int tot;

    Rofl() {
        tot = 0;
    }

    int get() {
        return ++Rofl::tot;
    }
} a, b;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    Rofl a, b;
    cerr << a.get() << "\n";
    cerr << b.get() << "\n";
    cerr << a.get() << "\n";
//
//    ll n;
//    cin >> n;
//    ll a = q(n);
//    cout << s(a) + s(n - a) << "\n";

//    forn(i, 1, 1000) {
//        cerr << i << ": " << f(i) << " " << q(i) << "\n";
//        assert(s(f(i)) + s(i - f(i)) == s(q(i)) + s(i - q(i)));
//    }

    return 0;
}

