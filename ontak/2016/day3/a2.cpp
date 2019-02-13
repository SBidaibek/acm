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
    ll s = 0;
    forn(i, 1, n) {
        int tp, g;
        cin >> tp >> g;
        if (tp == 0) {
            forn(j, 0, i) {
                d[j] += g;
                if (d[j] < 0) d[j] = -INF;
            }
        }
        else {
            if (g <= 0) {
                ++p;
                forn(j, 0, i) {
                    d[j] += -g;
                    if (d[j] < 0) d[j] = -INF;
                }
                continue;
            }
            for1(j, i, 1)
                if (d[j - 1] >= g)
                    d[j] = max(d[j], d[j - 1] - g);
        }/*
        cerr << i << ": ";
        cerr << d[0] << "\n";
        forn(j, 1, n) cerr << d[j - 1] - d[j] <<" ";
        cerr << "\n";*/
        forn(j, 2, n)
            if (d[j] >= 0)
                assert(d[j - 2] - d[j - 1] <= d[j - 1] - d[j]);
    }
    int ans = -1;
    forn(i, 0, n)
        if (d[i] >= 0)
            ans = i;
    if (ans >= 0) ans += p;
    cout << ans << "\n";

    return 0;
}
