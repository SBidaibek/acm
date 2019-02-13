#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pii;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

pii operator - (pii a, pii b) {
    return {a.x - b.x, a.y - b.y};
}

ld dist(pii a, pii b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

ll dp(pii a, pii b) {
    return a.x * b.x + a.y * b.y;
}

ostream & operator << (ostream &out, pii p) {
    out << "(" << p.x << " " << p.y << ")";
    return out;
}

#define sqr(x) (x * x)

const ld eps = 1e-8;

void p3c(pii a, pii b, pii c, pii &d, ld &r) {
    if (cp(c - a, b - a) == 0) {
        vector <pii> v = {a, b, c};
        sort(v.begin(), v.end());
        d = v[2] - v[0];
        d.x = d.x / 2 + v[0].x, d.y = d.y / 2 + v[0].y;
        r = dist(d, a);
    }
    else {
        ld f = c.x*c.x-c.x*b.x-a.x*c.x+a.x*b.x+c.y*c.y-c.y*b.y-a.y*c.y+a.y*b.y; //formula
        ld g = c.x*a.y-c.x*b.y+a.x*b.y-a.x*c.y+b.x*c.y-b.x*a.y;
        ld m = 0;
        if (g == 0) m = 0;
        else m = (f/g);

        d = {
            -((m*b.y)-b.x-a.x-(m*a.y)) / 2, //formula
            -((m*a.x)-a.y-b.y-(b.x*m)) / 2
        };
        //cerr << d.x << " " << d.y << "\n";
        //ld e = (a.x*b.x)+(a.y*b.y)-(m*a.x*b.y)+(m*b.x*a.y);
        //s = (((h)*(h))+((k)*(k))-e);


        //ld t = (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
        //ld u = (a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y) / 2.0;
        //ld v = (b.x * b.x - c.x * c.x + b.y * b.y - c.y * c.y) / 2.0;
        /*ld t = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x* (a.y - b.y));
        d = {
            ((sqr(a.x) + sqr(a.y)) * (b.y - c.y) +
                (sqr(b.x) + sqr(b.y)) * (c.y - a.y) + (sqr(c.x) + sqr(c.y)) * (a.y - b.y)) / t,
            ((sqr(a.x) + sqr(a.y)) * (c.x - b.x) +
                (sqr(b.x) + sqr(b.y)) * (a.x - c.x) + (sqr(c.x) + sqr(c.y)) * (b.x - a.x)) / t,
        };
        */
        r = dist(d, a);
        assert(fabs(r - dist(d, b)) < eps);
        assert(fabs(r - dist(d, c)) < eps);
    }
    //cerr << a << " " << b << " " << c << " " << t << " " << d << "\n";
}

int n;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("friends.in", "r", stdin);
    freopen("friends.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector <pii> ans;
    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    pii c = a[1];
    ld r = 0;
    forn(i, 1, n) {
        forn(j, 1, i - 1) {
            forn(k, 1, j - 1) {
                if (dist(c, a[i]) > r || dist(c, a[j]) > r || dist(c, a[k]) > r)
                    p3c(a[i], a[j], a[k], c, r);
            }
        }
    }
    //cerr << c.x << " " << c.y << "\n";
    //cerr << r << "\n";
    //forn(i, 1, n)
    //    assert(dist(a[i], c) <= r);
        //    cerr << dist(a[i], c) << "\n";
    forn(i, 1, n) {
        if (r - dist(c, a[i]) > eps) continue;
        forn(j, 1, i - 1) {
            if (r - dist(c, a[j]) > eps) continue;
            bool ok = 1;
            forn(k, 1, n)
                if (k != i && k != j) {
                    ok &= (dp(a[i] - a[k], a[j] - a[k]) <= 0);
                }
            if (ok) ans.pb({j, i});
        }
    }
    cout << ans.size() << "\n";
    for (auto p : ans)
        cout << p.x << " " << p.y << "\n";

    return 0;
}
