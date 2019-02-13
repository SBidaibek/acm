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
int a[N], b[N];
int l1[N], l2[N];

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n)
        cin >> b[i];

    forn(i, 1, n) {
        if (l1[i]) continue;
        for (int x = i; x != i || l1[i] == 0; x = a[x]) ++l1[i];
        for (int x = a[i]; x != i; x = a[x]) l1[x] = l1[i];
    }
    forn(i, 1, n) {
        if (l2[i]) continue;
        for (int x = i; x != i || l2[i] == 0; x = b[x]) ++l2[i];
        for (int x = b[i]; x != i; x = b[x]) l2[x] = l2[i];
    }

    ll ans = 1;
    forn(i, 1, n)
        ans = lcm(ans, lcm(l1[i], l2[i]));
    cout << ans % B << "\n";

    return 0;

}
