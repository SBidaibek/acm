#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 500 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi o(n + 1);
    forn(i, 1, n)
        cin >> o[i];
    sort(o.begin() + 1, o.end());
    vi a, c;
    forn(i, 1, n)
        if (o[i] == o[i - 1])
            ++c[c.size() - 1];
        else
            a.pb(o[i]), c.pb(1);

    int ans = 0;
    forn(i, 0, a.size() - 1) {
        if (((c[i] * (c[i] + 1)) / 2) % 2 == 1)
            ans ^= (a[i] + a[i]);
        forn(j, i + 1, a.size() - 1) {
            if (c[i] % 2 == 1 && c[j] % 2 == 1)
                ans ^= (a[i] + a[j]);
        }
    }
    cout << ans << "\n";

    return 0;
}
