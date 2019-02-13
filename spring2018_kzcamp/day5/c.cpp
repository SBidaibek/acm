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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, s, t[N];
ll a[N], b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    forn(i, 1, n) cin >> t[i];
    a[1] = t[1];
    forn(i, 2, n) a[i] = max(t[i], a[i - 1] + 1);
    //forn(i, 1, n) cerr << a[i] << " ";cerr << "\n";
    ll ans = 5e18;//a[n] + s + (n - 1) + s;
    forn(it, 1, n) {
        b[1] = max(a[1] + s, a[it]);
        forn(i, 2, n) b[i] = max(a[i] + s, b[i - 1] + 1);
        ll lst = a[1], tp = 0;
        int p1 = 2, p2 = 1;
        while (p1 <= n || p2 <= n) {
            if (p1 <= n && a[p1] <= b[p2]) {
                int cur = 0;
                if (tp == 0)
                    cur = max(lst + 1, a[p1]);
                else
                    cur = max(lst + s, a[p1]);
                lst = cur;
                tp = 0;
                ++p1;
            }
            else {
                int cur = 0;
                if (tp == 1)
                    cur = max(lst + 1, b[p2]);
                else
                    cur = max(lst + s, b[p2]);
                lst = cur;
                tp = 1;
                ++p2;
            }
            //cerr << lst << " " << tp << ": " << p1 << " " << p2 << "\n";
        }
        assert(tp == 1);
        ans = min(ans, lst + s);
    }
    cout << ans << "\n";

    return 0;
}
