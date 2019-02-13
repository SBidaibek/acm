#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES " << n - 1 << "\n";
            continue;
        }
        --n, --k;
        ll p = 4;
        bool ok = 0;
        while (n > 0) {
            ll del = (p - 1) / 2;
            if (del >= k) {
                ok = 1;
                break;
            }
            if (n - 1 >= 30) {
                ok = 1;
                break;
            }
            ll pwr = 1, s = 1;
            forn(it, 1, n - 1) {
                pwr *= 4;
                s += pwr;
                if (del * s >= k) {
                    ok = 1;
                    break;
                }
            }
            del *= s;
            //cerr << n << ": " << p << " " << del << " k = " << k << "\n";
            if (del >= k) {
                ok = 1;
                break;
            }
            k -= del;
            ll rest = p - (p - 1) / 2;
            if (k < rest) {
                ok = 0;
                break;
            }
            k -= rest;
            p = rest * 4;
            --n;
            if (k == 0) {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "YES " << n << "\n";
        else
            cout << "NO\n";
    }

    return 0;
}
