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

int n;
ll a[N], b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i] >> b[i];
    ll s = 0;
    for1(i, n, 1) {
        ll d = (b[i] - (a[i] + s) % b[i] + b[i]) % b[i];
        //cerr << a[i] << " " << s << ": " << d << "\n";
        s += d;
    }
    cout << s << "\n";

    return 0;
}
