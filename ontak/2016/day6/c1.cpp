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

ld d1[N], d2[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;

    ld ans = 1e6;
    forn(i, 1, n) {
        forn(j, i + 1, n) {
            Line l1(a[i], a[j]);
            int p1 = 0, p2 = 0;
            forn(k, 1, n) {
                ld tmp = l1(a[k]);
                if (tmp > -1e-10) d1[++p1] = fabs(tmp);
                if (tmp < 1e-10) d2[++p2] = fabs(tmp);
            }
            if (p1 >= q) {
                nth_element(d1 + 1, d1 + q, d1 + 1 + p1);
                ans = min(ans, d1[q]);
            }
            if (p2 >= q) {
                nth_element(d2 + 1, d2 + q, d2 + 1 + p2);
                ans = min(ans, d2[q]);
            }
        }
    }
    cout << fixed << setprecision(20) << ans / 2 << "\n";

    return 0;

}
