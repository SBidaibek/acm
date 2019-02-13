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

const int N = 6e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int a, b, l, r;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> l >> r;
    int s = (l - 1), f = (r - 1);/*
    if (s / (a + b) == f / (a + b)) {
        if (f < a) {
            cout << r - l + 1 << "\n";
            return 0;
        }
        if (s >= a) {
            cout << "1\n";
            return 0;
        }
        cout << a - s << "\n";
        return 0;
    }
    if (f - s + 1 <= a + b) {
        cout << 1 + f - a + 1 << "\n";
        return 0;
    }*/
    if (s / (a + b) + 1 >= f / (a + b)) {
        int ans = (a + b) * 2;
        forn(i, 0, 25) {
            forn(j, 0, 25) {
                vi v;
                forn(k, 0, a - 1) v.pb(k);
                forn(k, 1, b) v.pb(i);
                vi u(26);
                forn(k, v.size() - a, v.size() - 1)
                    u[v[k]] = 1;
                int cnt = 0;
                forn(k, 0, 25) {
                    if (u[k]) continue;
                    v.pb(k);
                    if (++cnt == a) break;
                }
                forn(k, 1, b) v.pb(j);
                vi t(26);
                int res = 0;
                int m = (a + b) * 2;
                forn(k, s % m, f % m) {
                    if (!t[v[k]]) ++res;
                    t[v[k]] = 1;
                }
                ans = min(ans, res);
            }
        }
    }

        /*if (s % (a + b) < a) {
            if (a <= b) {

            }
            else {

            }
            return 0;
        }
        else {
            cout << a + 1 << "\n";
            return 0;
        }
    }*/
/*
    if (f - s + 1 < 2 * (a + b)) {

        return 0;
    }*/

    cout << a + 1 << "\n";
    /*
    if (b >= a) {
        cout << 1 + a << "\n";
        return 0;
    }
    if (b < a) {
        cout << 1 + (a - b) + a << "\n";
    }*/

    return 0;
}
