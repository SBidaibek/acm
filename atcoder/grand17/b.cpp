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

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    n -= 1;
    b = abs(b - a);
    if (d == 0) {
        cout << (b ? "NO\n" : "YES\n");
        return 0;
    }/*
    if (c == 0) {
        cout << (b % d == 0 && b / d <= n ? "YES\n" : "NO\n");
        return 0;
    }*/
    forn(i, 0, n) {
        ll x = abs(b - d * i);
        ll v = x % c;        if (v == 0 && x / c <= n - i && (n - i - (x / c)) % 2 == 0) {
            cout << "YES\n";
            return 0;
        }/*
        x = abs(b - c * i);
        if (x % d == 0 && x / d <= n - i && (n - i - (x / d)) % 2 == 0) {
            cout << "YES\n";
            return 0;
        }*/
        /*
        bool ok = (c * i <= b && b <= d * i);
        if (ok && (n - i) % 2 == 0) {
            cout << "YES\n";
            return 0;
        }*/
    }
    cout << "NO\n";

    return 0;
}
