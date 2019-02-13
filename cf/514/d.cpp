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
typedef pair <ld, ld> pnt;
typedef vector <int> vi;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ld sqr (ld x) {
    return x * x;
}

ld dist(pnt a, pnt b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

struct circle {
    pnt c;
    ld r;
    circle(pnt p1, pnt p2) {
        c = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
        r = dist(p1, c);
    }
    circle(pnt p1, pnt p2, pnt p3) {
//        ld ma = (p2.y - p1.y) / (p2.x - p1.x);
//        ld mb = (p3.y - p2.y) / (p3.x - p2.x);
//        ld x = (ma * mb * (p1.y - p3.y) + mb * (p1.x + p2.x) - ma * (p2.x + p3.x)) / (2 * (mb - ma));
//        ld y = 0;
//        if (ma != 0)
//            y = (-1.0 / ma) * (x - (p1.x + p2.x) / 2) + (p1.y + p2.y) / 2;
//        else
//            y = (-1.0 / mb) * (x - (p2.x + p3.x) / 2) + (p2.y + p3.y) / 2;
        ld a = p1.x * (p2.y - p3.y) - p1.y * (p2.x - p3.x) + p2.x * p3.y - p3.x * p2.y;
        ld b = ((sqr(p1.x) + sqr(p1.y)) * (p3.y - p2.y) + (sqr(p2.x) + sqr(p2.y)) * (p1.y - p3.y) + (sqr(p3.x) + sqr(p3.y)) * (p2.y - p1.y));
        ld C = ((sqr(p1.x) + sqr(p1.y)) * (p2.x - p3.x) + (sqr(p2.x) + sqr(p2.y)) * (p3.x - p1.x) + (sqr(p3.x) + sqr(p3.y)) * (p1.x - p2.x));
        ld x = -b / (2 * a);
        ld y = -C / (2 * a);
        c = {x, y};
        r = dist(p1, c);
    }
    bool inside(const pnt &p) {
        return r >= dist(c, p);
    }
};

ostream & operator << (ostream &out, circle c) {
    return out << "(" << c.c.x << " " << c.c.y << ") " << c.r;
}

circle f3(vector <pnt> a, const pnt &p1, const pnt &p2) {
    circle ans(p1, p2);
    forn(i, 0, a.size() - 1)
        if (!ans.inside(a[i]))
            ans = circle(p1, p2, a[i]);
    return ans;
}

circle f2(vector <pnt> a, const pnt &p1) {
    random_shuffle(a.begin(), a.end());
    circle ans(a[0], p1);
    vector <pnt> b;
    b.pb(a[0]);
    forn(i, 1, a.size() - 1) {
        if (!ans.inside(a[i]))
            ans = f3(b, p1, a[i]);
        b.pb(a[i]);
    }
    return ans;
}

circle f1(vector <pnt> a) {
    assert(a.size() >= 2);
    random_shuffle(a.begin(), a.end());
    circle ans(a[0], a[1]);
    vector <pnt> b;
    b.pb(a[0]), b.pb(a[1]);
    forn(i, 2, a.size() - 1) {
        if (!ans.inside(a[i]))
            ans = f2(b, a[i]);
        b.pb(a[i]);
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vector <pnt> a(n);
    int cnt = 0;
    ld mn = INF, mx = -INF;
    forn(i, 0, n - 1) {
        cin >> a[i].x >> a[i].y;
        if (a[i].y == 0) ++cnt;
        mx = max(mx, a[i].y);
        mn = min(mn, a[i].y);
        if (a[i].y == 0) ++cnt;
    }
    if (n == 1) {
        cout << fabs(a[0].y) / 2 << "\n";
        return 0;
    }

    if (cnt > 1 || (mx > 0 && mn < 0)) {
        cout << "-1\n";
        return 0;
    }

    ld l = -1e7, r = 1e7;
    forn(it, 1, 100) {
        ld m = (l + r) / 2;
        ld m1 = (l + m) / 2;
        ld m2 = (m + r) / 2;
        a.pb({m1, 0});
        ld v1 = f1(a).r;
        a.pop_back();
        a.pb({m2, 0});
        ld v2 = f1(a).r;
        a.pop_back();
        if (v1 < v2) r = m2;
        else l = m1;
    //    cerr << l << " " << r << "\n";
    }
    cerr << l << "\n";
    a.pb({l, 0});
    circle c = f1(a);;
    cout << c.r << "\n";

    return 0;
}

