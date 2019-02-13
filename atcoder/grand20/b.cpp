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

int k;
int a[N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    forn(i, 1, k)
        cin >> a[i];
    ll l = 2, r = 2;
    for1(i, k, 1) {
        if (l % a[i] != 0 && r % a[i] != 0 && l / a[i] == r / a[i]) {
            cout << "-1\n";
            return 0;
        }
        ll nl = l + (a[i] - l % a[i]) % a[i];
        ll nr = r - (r % a[i]) + (a[i] - 1);
        assert(nl <= nr);
        l = nl, r = nr;
    }
    cout << l << " " << r << "\n";

    return 0;
}
