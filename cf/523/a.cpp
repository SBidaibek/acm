#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
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

    ll n, m;
    cin >> n >> m;
    vi a(n);
    forn(i, 1, n) {
        cin >> a[i - 1];
        m = min(m, a[i - 1]);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int bal = 0;
    forn(i, 0, n - 1) {
        int prv = (i == 0 ? 0 : a[i - 1]);
        int j = i;
        while (j < n - 1 && a[j + 1] == a[i]) ++j;
        int v = a[i] - prv;
        int d = j - i + 1;
        int rest = max(v, d);
        if (v >= d) {
            bal += v - d;
            ans += a[i] * d - rest;
        }
        else {
            int q = min(d - v, bal);
            bal -= q;
            rest -= q;
            ans += a[i] * d - rest;
        }
        i = j;
    }
    cout << ans << "\n";

    return 0;
}
