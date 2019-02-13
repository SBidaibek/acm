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

ld ccw(pii p, ld ca, ld sa) {
    return p.x * ca - p.y * sa;
}

ld dist(pii p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

int n;
pii p[N];
int c[N];
pair <ld, int> a[N];

ll g() {
    sort(a + 1, a + 1 + n);
    ll ans = 0, p = 0, mn = 0;
    forn(i, 1, n) {
        p += a[i].y;
        if (fabs(a[i].x - a[i + 1].x) <= 1e-10) continue;
        ans = max(ans, p - mn);
        mn = min(mn, p);
    }
    //cerr << ans << "\n";
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> p[i].x >> p[i].y >> c[i];
    forn(i, 1, n)
        a[i] = {p[i].x, c[i]};
    ll ans = g();
    ld l = 0, r = acos(-1);
    forn(i, 0, 10) {
        ld x = acos(-1) / 10 * i;
        ld ca = cos(x), sa = sin(x);
        forn(i, 1, n) {
            a[i] = {ccw(p[i], ca, sa), c[i]};
            cerr << p[i].x << " " << p[i].y << " -> " << a[i].x << "\n";
        }
        ll cur = g();
        cerr << x << ": " << ca << " " << sa << " " << cur << "\n";
        ans = max(ans, cur);
    }
    cout << ans << "\n";

    return 0;
}
