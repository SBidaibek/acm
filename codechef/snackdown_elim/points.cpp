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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

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

pii a[5];

bool check(vector <pii> t) {
    for (auto p : t)
        if (-1e6 <= p.x && p.x <= 1e6 && -1e6 <= p.y && p.y <= 1e6) {}
        else return 0;
    forn(i, 1, 4) {
        bool shit = 0;
        forn(j, 0, 2) {
            pii b = t[j], c = t[(j + 1) % 3];
            if (cp(v(a[i], b), v(a[i], c)) == 0 && eq(dist(b, c), dist(a[i], b) + dist(a[i], c)))
                shit = 1;
        }
        if (!shit) return 0;
    }
    return 1;
}

ostream & operator << (ostream &out, pii p) {
    out << p.x << " " << p.y;
    return out;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    forn(_, 1, t) {
        forn(i, 1, 4)
            cin >> a[i].x >> a[i].y;
        bool col = 1;
        forn(i, 3, 4)
            col &= cp(v(a[1], a[2]), v(a[1], a[i])) == 0;
        if (col) {
            cout << "YES\n";
            forn(i, 1, 4) {
                bool ok = 0;
                forn(j, 1, i - 1)
                    if (check({a[i], a[j], a[i]})) {
                        cout << a[i] << " " << a[j] << " " << a[i] << "\n";
                        ok = 1;
                        break;
                    }
                if (ok) break;
            }
            continue;
        }
        vi o = {1, 2, 3, 4};
        bool found = 0;
        do {
            pii i = a[o[0]], j = a[o[1]], k = a[o[2]], f = a[o[3]];
            if (cp(v(i, j), v(i, k)) <= 0 ||
                cp(v(i, j), v(i, f)) < 0 ||
                cp(v(i, f), v(i, k)) < 0) continue;
            Line l1(i, j), l2(i, k);
            Line L(f, j);
            if (dp(v(i, j), v(i, k)) == 0 && dp(v(f, j), v(f, k)) == 0) {
                Line tmp(i, f);
                Line L = Line(-tmp.b, tmp.a, 0);
                L.c = -L(f);
                vector <pii> ans = {i, li(l1, L), li(l2, L)};
                if (check(ans)) {
                    cout << "YES ";
                    for (auto p : ans)
                        cout << p.x << " " << p.y << " ";
                    cout << "\n";
                    found = 1;
                    break;
                }
                continue;
            }
            vector <pii> ans = {i, li(l1, L), li(l2, L)};
            if (check(ans)) {
                cout << "YES ";
                for (auto p : ans)
                    cout << p.x << " " << p.y << " ";
                cout << "\n";
                found = 1;
                break;
            }
            L = Line(f, k);
            ans = {i, li(l1, L), li(l2, L)};
            if (check(ans)) {
                cout << "YES ";
                for (auto p : ans)
                    cout << p.x << " " << p.y << " ";
                cout << "\n";
                found = 1;
                break;
            }
        } while (next_permutation(o.begin(), o.end()));
        if (!found) cout << "NO\n";
    }

    return 0;
}
