#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;
typedef pair <ld, ld> pnt;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ld dist(pnt a, pnt b) {
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}

pnt v(pnt a, pnt b) {
    return {b.x - a.x, b.y - a.y};
}

ld cp(pnt a, pnt b) {
    return a.x * b.y - a.y * b.x;
}

ld dp(pnt a, pnt b) {
    return a.x * b.x + a.y * a.y;
}

ld p2s(pnt l, pnt r, pnt p) {
    if (dp(v(l, r), v(l, p)) >= 0 && dp(v(r, l), v(r, p)))
        return fabs(cp(v(p, r), v(p, l)) / dist(l, r));
    else
        return min(dist(l, p), dist(r, p));
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("err", "w", stderr);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cerr << p2s({0, 0}, {10, 0}, {11, 1}) << "\n";

    int R, l, w;
    cin >> R >> l >> w;
    int T;
    cin >> T;
    cout << fixed << setprecision(20);
    while (T--) {
        ld alpha, beta;
        cin >> alpha >> beta;
        pnt a1 = {0, w};
        pnt a2 = {cos(alpha) * l, w + sin(alpha) * l};
        pnt b1 = {0, 0};
        pnt b2 = {cos(beta) * l, sin(beta) * l};
        cerr << a1.x << " " << a1.y << "\n";
        cerr << a2.x << " " << a2.y << "\n";
        //cerr << pnt({l, w}).x << " " << pnt({l, w}).y << "\n";

        ld ans = min(p2s(b1, b2, {l, w}), p2s(a1, a2, {l, w}));
        cerr << p2s(a1, a2, {l, w}) << "\n";
        ans = min(ans, p2s(a1, a2, b1));
        cerr << ans << "\n";
        ans = min(ans, p2s(a1, a2, b2));
        cerr << ans << "\n";
        ans = min(ans, p2s(b1, b2, a1));
        cerr << ans << "\n";
        ans = min(ans, p2s(b1, b2, a2));
        cerr << ans << "\n";

        ans = min(ans / 2, ld(R));
        cout << ans << "\n";
    }

    return 0;
}

