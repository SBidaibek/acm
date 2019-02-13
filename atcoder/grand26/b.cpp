#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    forn(it, 1, t) {
    //cerr << "test " << it << "\n";
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d < b || a < b) {
        //cerr << "1\n";
            cout << "No\n";
            continue;
        }
        if (a > c) {
            a -= ((a / b) - (c / b)) * b;
            if (a <= c) a += b;
        }
        if (a < b) {
            //cerr << "2 " << a << "\n";
            cout << "No\n";
            continue;
        }
        if (b == d) {
            cout << "Yes\n";
            continue;
        }
        if (c + 1 <= b - 1) {
            ll g = gcd(b, d);
            ++c, --b;
            if (b - c >= g || (c % g <= b % g ? c % g <= a % g && a % g <= b % g : c % g <= a % g || a % g <= b % g)) {
                //cerr << "3 " << g << "\n";
                cout << "No\n";
                continue;
            }
        }
        cout << "Yes\n";
    }

    return 0;
}
