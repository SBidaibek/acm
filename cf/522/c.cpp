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

void rel(int x, vi &d) {
    d[x] = (d[x] + d[x - 1]) % B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n + 1);
    vi d(n + 1);
    d[0] = 1;
    forn(i, 1, n) {
        cin >> a[i];
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j != 0) continue;
            rel(j, d);
            if (j * j != a[i])
                rel(a[i] / j, d);
        }
        cerr << d[0] << " " << d[1] << " " << d[2] << "\n";
    }
    ll ans = 0;
    forn(i, 1, n)
        ans = (ans + d[i]) % B;
    cout << ans << "\n";

    return 0;
}

