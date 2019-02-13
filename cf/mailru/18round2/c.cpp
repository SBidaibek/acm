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
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll la, ra, ta;
    ll lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;

    if (la > lb)
        swap(la, lb), swap(ra, rb), swap(ta, tb);
    ll dif = lb - la;
    ll g = __gcd(ta, tb);
    dif %= g;
    ra -= la, rb -= lb;
    //cerr << min(ra, rb + dif) - max(0, dif) + 1 << "\n";
    ll ans = max(
        min(ra, rb + dif) - max(0ll, dif) + 1,
        min(ra + g - dif, rb) - max(g - dif, 0ll) + 1
    );
    ans = max(ans, 0ll);
    cout << ans << "\n";

    return 0;
}

