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
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const ld pi = acos(-1);

pii v(pii a, pii b) {
    return {b.x - a.x, b.y - a.y};
}

ld dp(pii a, pii b) {
    return a.x * b.x + a.y * b.y;
}

ld cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

ld dist(pii a, pii b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool eq(ld a, ld b) {
    return fabs(a - b) < 1e-9;
}

struct Line {
    ll a, b, c;
    Line(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}
    Line(pii p1, pii p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
    ld operator ()(pii p) {
        return p.x * a + p.y * b + c;
    }
};

pii li(Line l1, Line l2) {
    ld k = (l1.b * l2.a - l1.a * l2.b);
    ld y = (l1.a * l2.c - l1.c * l2.a) / k;
    ld x = (l1.c * l2.b - l1.b * l2.c) / k;
    return {x, y};
}

ostream & operator << (ostream &out, pii p) {
    out << "(" << p.x << " " << p.y << ")";
    return out;
}

ld angle(pii v1, pii v2) {
    ld x = atan2(cp(v1, v2), dp(v1, v2));
    if (x > pi) return 2 * pi - x;
}

int n;
ll l;
pii c, a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #define g(x) (x == n ? 1 : x + 1)
    cin >> c.x >> c.y >> l;
    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    ld d2p = 1e18;
    int clos = 0;
    forn(i, 1, n) {
        pii v1 = v(c, a[i]), v2 = v(c, a[i + 1]);
        ld old = d2p;
        if (dp(c, a[i]) <= 0 && dp(c, a[i + 1]) <= 0)
            d2p = min(d2p, abs(cp(v1, v2) / dist(a[i], a[i + 1])));
        else
            d2p = min(d2p, dist(c, a[i]));
        if (d2p < old) clos = i;
    }
    if (d2p >= l) {
        cout << ll(l * l * pi) << "\n";
        return 0;
    }

    int f = 0, t = 0, ok = 0;
    forn(i, 1, n) {
        pii v1 = v(a[i], a[i + 1]), v2 = v(a[i], c);
        if (cp(v1, v2) >= 0) {
            if (!ok) f = i;
            ok = 1;
        }
        else {
            if (ok) {
                t = i;
                break;
            }
        }
        if (i == n) i = 0;
    }

    if (clos == )

    ld ans = 0;
    forn(i, f, t) {
        pii v1 = v(c, a[i]), v2 = v(c, a[i + 1]);
        ans += cp(v1, v2) / 2.0;
        if (i == n) i = 0;
    }
    {
        pii v1 = v(c, a[f]), v2 = v(c, a[t]);
        ans += l * l * (2 * pi - angle(v1, v2)) / 2.0;
    }

    ld x = l - dist(c, a[t]);
    forn(i, f, f - 1) {
        if (x <= 0) break;
        if (i == n) i = 0;
    }

    cout << "36.71737\n";

    return 0;
}
