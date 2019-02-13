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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, p[N], s[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) {
        int f, t;
        cin >> f >> t;
        ++p[f], --p[t + 1];
    }
    forn(i, 1, m)
        p[i] += p[i - 1];
    int mx = 0;
    forn(i, 1, m)
        mx = max(mx, p[i]);
    int ans = 0, cur = 0, lon = 0;
    for1(i, m, 1)
        s[i] = s[i + 1] + (p[i] != mx);
    bool f = 0;
    forn(i, 1, m) {
        if (p[i] == mx) {
            f = 1;
            ++cur;
            lon = max(lon, cur);
        }
        else {
            if (!f) ++cur;
        }
        ans = max(ans, cur + s[i + 1]);
    }
    cout << ans + lon << "\n";

    return 0;
}
