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

int get(ll a, ll b) {
    cout << a << " " << b << endl;
    int ans;
    cin >> ans;
    if (ans == 0) exit(0);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    int a = 0, b = 0, x = 0, y = 0;
    ll n;
    cin >> n;
    ll l = 1, r = n;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        ll x = get(m, m);
        if (x == 3) r = m;
        else l = m;
    }
    int t1 = get(l, l);
    int t2 = get(r, r);

    ll l1 = 1, r1 = l;


    cout << ans << "\n";

    return 0;
}
