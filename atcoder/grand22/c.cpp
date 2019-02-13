#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N], b[N];
vi sel;

bool ok(int k) {
    forn(it, 1, n) {
        vector <bool> u(a[it] + 1, 0);
        u[a[it]] = 1;
        for (auto i : sel)
            forn(j, 0, a[it])
                if (u[j]) u[j % i] = 1;
        for1(i, k, 1)
            forn(j, 0, a[it])
                if (u[j]) u[j % i] = 1;
        if (!u[b[it]]) return 0;
    }
    return 1;
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

    if (!ok(50)) {
        cout << "-1\n";
        return 0;
    }
    ll ans = 0;
    for1(i, 50, 1) {
        if (!ok(i - 1)) {
            sel.pb(i);
            ans += (1ll << i);
        }
    }
    cout << ans << "\n";

    return 0;
}
