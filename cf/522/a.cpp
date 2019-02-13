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
const int B = 1e9 + 7;

typedef pair <ld, ld> pnt;

ld dist(pnt a, pnt b) {
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld ans = abs(x1 - x2) + abs(y1 - y2);
    if (a != 0 && b != 0) {
        pnt a1 = {x1, (a * x1 + c) / ld(-b)};
        pnt a2 = {(b * y1 + c) / ld(-a), y1};
        pnt b1 = {x2, (a * x2 + c) / ld(-b)};
        pnt b2 = {(b * y2 + c) / ld(-a), y2};
        ans = min(ans, fabs(y1 - a1.y) + dist(a1, b1) + fabs(y2 - b1.y));
        ans = min(ans, fabs(y1 - a1.y) + dist(a1, b2) + fabs(x2 - b2.x));
        ans = min(ans, fabs(x1 - a2.x) + dist(a2, b1) + fabs(y2 - b1.y));
        ans = min(ans, fabs(x1 - a2.x) + dist(a2, b2) + fabs(x2 - b2.x));
    }
    cout << fixed << setprecision(10);
    cout << ans << "\n";

    return 0;
}

