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
        ll n, k, v;
        cin >> n >> k >> v;
        v = (v - 1) * k % n;
        forn(i, 0, n - 1) {
            string s;
            cin >> s;
            if (v + k <= n) {
                if (v <= i && i < v + k)
                    cout << s << " ";
            }
            else {
                if (v <= i || i < (v + k) % n)
                    cout << s << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
