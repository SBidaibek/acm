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

const int N = 1e5 + 3, K = 102;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, q;
pii a[N];

struct Line {
    ld a, b, c, k;
    //Line(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}
    Line(pii p1, pii p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
        k = sqrt(a * a + b * b);
    }
    ld operator ()(pii p) {
        return (p.x * a + p.y * b + c) / k;
    }
};


bool ok(ld d) {
    forn(i, 1, n) {
        forn(j, i + 1, n) {
            Line l1(a[i], a[j]);
            //cerr << i << " " << j << ": " << l1.a << " " << l1.b << " " << l1.c << "\n";
            Line l2 = l1;
            l2.c = l1.c + d * l1.k;
            int cur = 0;
            forn(k, 1, n)
                if (d - fabs(l2(a[k])) > -1e-10) ++cur;
            if (cur >= q) return 1;
            l2.c = l1.c - d * l1.k;
            cur = 0;
            forn(k, 1, n)
                if (d - fabs(l2(a[k])) > -1e-10) ++cur;
            if (cur >= q) return 1;
        }
    }
    return 0;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;

    ld l = 0, r = 1e6;
    forn(i, 1, 50) {
        ld m = (l + r) / 2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(20) << l << "\n";

    return 0;

}
