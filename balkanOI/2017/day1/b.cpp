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
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    forn(it, 1, q) {
        ll t, n, x;
        cin >> t >> n >> x;
        if (t == 1) {
            --x;
            ll u = 0, d = 0;
            ll r = x / (1ll << n), c = x % (1ll << n);
            int wr = 0, wc = 0;
            forn(i, 0, n - 1) {
                int qr = (r % (1ll << (n - i))) >= (1ll << (n - i - 1));
                int qc = (c % (1ll << (n - i))) >= (1ll << (n - i - 1));
                qr ^= wr, qc ^= wc;
                if (qr) {
                    u += (1ll << (2 * i));
                    swap(u, d);
                    wr ^= 1;
                }
                else
                    u += (1ll << (2 * i));
                if (qc) {
                    u += (1ll << (2 * i + 1));
                    swap(u, d);
                    wc ^= 1;
                }
                else
                    u += (1ll << (2 * i + 1));
            }
            cout << d + 1 << "\n";
        }
        else {
            --x;
            ll r = 0, c = 0;
            ll lft = 0, rht = (1ll << (2 * n)) - 1;
            int w = 0;
            forn(i, 0, n - 1) {
                ll m = (lft + rht) / 2;
                if ((x > m) ^ w) {
                    if (!w) lft = m + 1; else rht = m;
                    c += 2 * ((1ll << i) - c) - 1;
                    w ^= 1;
                }
                else
                    if (!w) rht = m; else lft = m + 1;
                m = (lft + rht) / 2;
                if ((x > m) ^ w) {
                    if (!w) lft = m + 1; else rht = m;
                    r += 2 * ((1ll << i) - r) - 1;
                    w ^= 1;
                }
                else
                    if (!w) rht = m; else lft = m + 1;
            }
            cout << r * (1ll << n) + c + 1 << "\n";
        }
    }

    return 0;
}
