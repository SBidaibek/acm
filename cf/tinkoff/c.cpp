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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
pii d, u;
pii a[N], v[N];

void no() {
    cout << "-1\n";
    exit(0);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ld l = 0, r = 1e18;
    cin >> d.x >> d.y >> u.x >> u.y;
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y >> v[i].x >> v[i].y;
        if (a[i].x < d.x) {
            if (d.y < a[i].y && a[i].y < u.y) {
                if (v[i].y > 0) {
                    if ((d.x - a[i].x) * v[i].y == (u.y - a[i].y) * v[i].x) no();
                }
                if (v[i].y < 0) {
                    if ((d.x - a[i].x) * v[i].y == (a[i].y - d.y) * v[i].x) no();
                }
            }
            if (v[i].x <= 0) no();
            l = max(l, (d.x - a[i].x) / ld(v[i].x));
            r = min(r, (u.x - a[i].x) / ld(v[i].x));
        }
        else
        if (a[i].x > u.x) {
            if (d.y < a[i].y && a[i].y < u.y) {
                if (v[i].y > 0) {
                    if ((a[i].x - u.x) * v[i].y == (u.y - a[i].y) * v[i].x) no();
                }
                if (v[i].y < 0) {
                    if ((a[i].x - u.x) * v[i].y == (a[i].y - d.y) * v[i].x) no();
                }
            }
            if (v[i].x >= 0) no();
            l = max(l, (a[i].x - u.x) / ld(v[i].x));
            r = min(r, (a[i].x - d.x) / ld(v[i].x));
        }
        else {
            if (v[i].x != 0) {
                if (v[i].x > 0) {
                    if (u.x == a[i].x) no();
                    r = min(r, (u.x - a[i].x) / ld(v[i].x));
                }
                else {
                    if (a[i].x == d.x) no();
                    r = min(r, (a[i].x - d.x) / ld(v[i].x));
                }
            }
            else {
                if (v[i].x == u.x || v[i].x == d.x) no();
            }
        }

        if (a[i].y < d.y) {
            if (d.x < a[i].x && a[i].x < u.x) {
                if (v[i].x > 0) {
                    if ((u.x - a[i].x) * v[i].y == (d.y - a[i].y) * v[i].x) no();
                }
                if (v[i].x < 0) {
                    if ((a[i].x - d.x) * v[i].y == (d.y - a[i].y) * v[i].x) no();
                }
            }
            if (v[i].y <= 0) no();
            l = max(l, (d.y - a[i].y) / ld(v[i].y));
            r = min(r, (u.y - a[i].y) / ld(v[i].y));
        }
        else
        if (a[i].y > u.y) {
            if (d.x < a[i].x && a[i].x < u.x) {
                if (v[i].x > 0) {
                    if ((u.x - a[i].x) * v[i].y == (a[i].y - u.y) * v[i].x) no();
                }
                if (v[i].x < 0) {
                    if ((a[i].x - d.x) * v[i].y == (a[i].y - u.y) * v[i].x) no();
                }
            }
            if (v[i].y >= 0) no();
            l = max(l, (a[i].y - u.y) / ld(v[i].y));
            r = min(r, (a[i].y - d.y) / ld(v[i].y));
        }
        else {
            if (v[i].y != 0) {
                if (v[i].y > 0) {
                    if (u.y == a[i].y) no();
                    r = min(r, (u.y - a[i].y) / ld(v[i].y));
                }
                else {
                    if (d.y == a[i].y) no();
                    r = min(r, (a[i].y - d.y) / ld(v[i].y));
                }
            }
            else {
                if (v[i].y == u.y || v[i].y == d.y) no();
            }
        }
    }

    cerr << l << " " << r << "\n";
    if (r < l) no();
    cout << fixed << setprecision(10) << l << "\n";

    return 0;
}
