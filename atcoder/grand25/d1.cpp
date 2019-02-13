#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s;
int x[N], a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    ll sum = 0;
    forn(i, 1, n) {
        cin >> x[i] >> a[i];
        sum += a[i];
    }

    ll ans = 0;
    while (sum > 0) {
        cerr << s << " " << sum << "\n";
        int tl = lower_bound(x + 1, x + 1 + n, s) - x - 1;
        int tr = tl + 1;
        if (x[tr] == s) ++tr;
        ll fn = 0, fp = 0;
        for1(i, n, tr) {
            int p = 1;
            for (ll ps = 0; p <= tl; ++p) {
                if (a[i] + fp + ps - a[p] <= 0) break;
                ps += a[p];
            }
            fp += a[i] * (p > tl ? +1 : -1);
        }
        forn(i, 1, tl) {
            int p = n;
            for (ll ss = 0; p >= tr; --p) {
                if (-a[i] + fn - ss + a[p] > 0) break;
                ss += a[p];
            }
            fn += -a[i] * (p < tr ? +1 : -1);
        }
        cerr << s << " " << sum << " " << fn << " " << fp << "\n";
        if (fn + fp <= 0) {
            ans += (s - x[tl]);
            s = x[tl];
            sum -= a[tl];
        }
        else {
            ans += (x[tr] - s);
            s = x[tr];
            sum -= a[tr];
        }
    }
    cout << ans << "\n";

    return 0;
}
