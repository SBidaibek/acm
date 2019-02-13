#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef pair <ld, ld> pnt;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, a[N], q[N], u[N];
bool d[N], b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int s = 0;
    forn(i, 1, n) {
        cin >> a[i];
    //    s += a[i];
    }
    sort(a + 1, a + 1 + n);
    s = a[n];
    cin >> m;
    forn(i, 1, m)
        cin >> q[i];

    d[0] = 1;
    forn(i, 1, n)
        forn(j, a[i], s)
            d[j] |= d[j - a[i]];
    b[0] = 1;
    forn(i, 1, n) {
        forn(j, 0, a[1] - 1) {
            if (u[j] == i) continue;
            int f = b[j];
            u[j] = i;
            int _j = j % a[1];
            int y= a[i] % a[1];
            for (int x = (j + a[i]) % a[1]; x != _j; x = (x + y >= a[1] ? x + y - a[1] : x + y))
                f |= b[x], u[x] = i;
            if (f) {
                b[j] |= f;
                for (int x = (j + a[i]) % a[1]; x != _j; x = (x + y >= a[1] ? x + y - a[1] : x + y))
                    b[x] |= f;
            }
        }
    }
    forn(i, 1, m)
        if (q[i] <= a[n])
            cout << (d[q[i]] ? "YES\n" : "NO\n");
        else
            cout << (b[q[i] % a[1]] ? "YES\n" : "NO\n");

    return 0;
}
