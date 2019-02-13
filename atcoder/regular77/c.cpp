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

int n, m;
int a[N];
ll s[N], p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll ans = 0, mx = 0;
    forn(i, 1, n) {
        cin >> a[i];
        if (i == 1) continue;
        #define g(x) (x == m ? 1 : x + 1)
        int dist = (a[i] + m - a[i - 1]) % m;
        ans += dist;
        if (a[i] == g(a[i - 1])) continue;
        if (a[i] > a[i - 1]) {
            ++s[a[i - 1] + 2];
            --s[a[i] + 1];
            s[a[i] + 1] -= (dist - 1);
            s[a[i] + 2] += (dist - 1);
        }
        else {
            ++s[a[i - 1] + 2];
            p[1] += (m - a[i - 1] - 1);
            ++s[1];
            p[a[i] + 1] -= (m - a[i - 1] - 1);
            --s[a[i] + 1];
            s[a[i] + 1] -= a[i];
            s[a[i] + 2] += a[i];
        }
    }
    forn(i, 1, m) {
        p[i] += p[i - 1];
        s[i] += s[i - 1];
    }
    forn(i, 1, m) {
        s[i] += s[i - 1];
        p[i] += s[i];
        mx = max(mx, p[i]);
    }
    cout << ans - mx << "\n";

    return 0;
}
