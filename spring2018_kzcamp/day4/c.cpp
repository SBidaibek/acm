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

ll dist(const pii &p1, const pii &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

pii p[N], d[N];
pii a[N];

pii vec(const pii &p1, const pii &p2) {
    return {p2.x - p1.x, p2.y - p1.y};
}

ll cp(const pii &p1, const pii &p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

bool cmp(const pii &p1, const pii &p2) {
    ll x = cp(p1, p2);
    if (x == 0) return dist({0, 0}, p1) < dist({0, 0}, p2);
    else return x > 0;
}

ostream & operator << (ostream &out, pii p) {
    out << "(" << p.x << " " << p.y << ")";
    return out;
}

int st[N], sz;

ll get(ll it, int n) {
    forn(i, 1, n)
        a[i] = {p[i].x + it * d[i].x, p[i].y + it * d[i].y};
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - (a + 1);
    if (n <= 2) return n == 1 ? 0 : dist(a[1], a[2]);
    for1(i, n, 1)
        a[i] = {a[i].x - a[1].x, a[i].y - a[1].y};
    sort(a + 2, a + n + 1, cmp);
    st[sz = 1] = 1;
    forn(i, 2, n) {
        for (; sz > 1; --sz)
            if (cp(vec(a[st[sz - 1]], a[st[sz]]), vec(a[st[sz]], a[i])) > 0) break;
        st[++sz] = i;
    }
    forn(i, 1, sz) a[i] = a[st[i]];
    n = sz;
    int ptr = 2;
    #define nxt(i) (i == n? 1 : i + 1)
    ll ans = 0;
    forn(i, 1, n) {
        while (cp(vec(a[nxt(i)], a[nxt(nxt(i))]), vec(a[nxt(ptr)], a[nxt(nxt(ptr))])) > 0)  {
            ans = max(ans, dist(a[i], a[nxt(ptr)]));
            ans = max(ans, dist(a[nxt(i)], a[nxt(ptr)]));
            ptr = nxt(ptr);
        }
    }

    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    forn(i, 1, n)
        cin >> p[i].x >> p[i].y >> d[i].x >> d[i].y;
    int l = 0, r = t;
    while (l < r) {
        int m = (l + r) / 2;
        if (get(m, n) > get(m + 1, n)) l = m + 1;
        else r = m;
    }
    cout << l << "\n" << get(l, n) << "\n";

    return 0;
}
