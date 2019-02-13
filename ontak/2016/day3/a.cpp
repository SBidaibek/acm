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
ll d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        d[i] = -INF;
    int p = 0;
    forn(i, 1, n) {
        int t, g;
        cin >> t >> g;
        if (t == 0) {
            forn(j, p, i) {
                d[j] += g;
                if (d[j] < 0) d[j] = -INF;
            }
        }
        else
            for1(j, i, p + 1)
                if (d[j - 1] >= max(g, 0))
                    d[j] = max(d[j], d[j - 1] - g);
        while (p < n && d[p + 1] >= d[p]) ++p;
    }
    int ans = -1;
    forn(i, p, n)
        if (d[i] >= 0)
            ans = i;
    cout << ans << "\n";

    return 0;
}
