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

ll n;
ll ax, ay;

int get(int x, int y) {
    if (x < 1 || y < 1 || n < x || n < y) return 0;
    cout << "examine " << x << " " << y << endl;
    string ans;
    //cout << ans << "\n";
    cin >> ans;
    return ans[0] == 't';
}

int main() {
//    #ifdef black
//    //freopen("in", "r", stdin);
//    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll x, y;
    cin >> n >> x >> y;
    //cin >> ax >> ay;
    ll lg = 0;
    while ((1ll << (lg + 1)) <= n) ++lg;

    ll pl = 0, pr = 0;
    while (x > (1ll << pl) && get(x - (1ll << pl), y) == 1) ++pl;
    while (x + (1ll << pr) <= n && get(x + (1ll << pr), y) == 1) ++pr;

    ll l = max(1ll, x - (1ll << pl)), r = x - (pl == 0 ? 0 : (1ll << (pl - 1)));
    if (get(l, y) == 0) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (get(m, y) == 0) l = m + 1;
            else r = m;
        }
    }
    pl = l;

    l = x + (pr == 0 ? 0 : (1ll << (pr - 1))), r = min(n, x + (1ll << pr));
    if (get(r, y) == 0) {
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (get(m, y) == 1) l = m;
            else r = m - 1;
        }
    }
    pr = r;

    ll m = pr - pl + 1;

    l = y - m, r = y;
    while (l < r) {
        int m = (l + r) >> 1;
        if (get(x, m) == 0) l = m + 1;
        else r = m;
    }
    ll pd = l;
    l = y, r = y + m;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        if (get(x, m) == 1) l = m;
        else r = m - 1;
    }
    ll pu = l;

    x = (pl + pr) / 2, y = (pd + pu) / 2;

    ll l1 = get(x - 2 * m, y), r1 = get(x + 2 * m, y);
    if (l1 && !r1) {
        if (get(x - 4 * m, y))
            x -= 2 * m;
        else
            x -= m, y -= m;
    }
    if (!l1 && r1) {
        if (get(x + 4 * m, y))
            x += 2 * m;
        else
            x += m, y += m;
    }
    ll d1 = get(x, y - 2 * m), u1 = get(x, y + 2 * m);
    if (d1 && !u1) {
        if (get(x, y - 4 * m))
            y -= 2 * m;
        else
            assert(0);
    }
    if (!d1 && u1) {
        if (get(x, y + 4 * m))
            y += 2 * m;
        else
            assert(0);
    }

    cout << "solution " << x << " " << y << endl;

    return 0;
}
