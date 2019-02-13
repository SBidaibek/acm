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

const int N = 2e6 + 1;
const int INF = 1e9  + 9;
const int B = 1e9 + 7;

int bp(ll a, ll b) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1) r = r * a % m;
    return r;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) {
        int x;
        cin >> x;
        d[x] = 1;
    }
    int phi = 0, sz = 0;
    vi div;
    forn(i, 1, m - 1) {
        if (m % i == 0) {
            div.pb(i);
        }
        if (__gcd(i, m) == 1) {
            ++phi;
            if (a[i] == 0) p[++sz] = i;
        }
    }
    p[0] = 1;
    forn(i, 1, sz)
        a[i] = p[i] * bp(p[i - 1], phi - 1);
    for (auto d )

    return 0;
}
