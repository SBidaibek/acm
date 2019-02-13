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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
char a[4][N];
int d[N][4];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(it, 1, tests) {
        cout << "Case #" << it << ": ";
        int n, k;
        cin >> n >> k;
        if (n == 2 || k <= 2) {
            cout << "0\n";
            cout << "1\n";
            cout << 1 << " " << n << " " << 1 << "\n";
            continue;
        }
        ll cost = k - 1, ans = -k;
        vector <vi> e;
        e.pb({1, n, k});
        forn(i, 1, n - 1) {
            ans += cost;
            if (cost == 1) {
                e.pb({i, n, cost});
                break;
            }
            e.pb({i, i + 1, cost});
            cost--;
        }
        cout << ans << "\n";
        cout << e.size() << "\n";
        for (auto v : e) {
            for (auto x : v) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
