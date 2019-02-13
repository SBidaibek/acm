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

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #else
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    map <int, int> a;
    forn(i, 1, n) {
        int x;
        cin >> x;
        ++a[x];
    }
    forn(i, 1, m) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            for (auto p : a) {
                if ((x -= p.S) <= 0) {
                    cout << p.F << "\n";
                    break;
                }
            }
        }
        else {
            vi v;
            for (auto p : a)
                if (p.F > x)
                    v.pb(p.F);
            for (auto z : v) {
                a[z - x] += a[z];
                a.erase(z);
            }
        }
    }

    return 0;
}
