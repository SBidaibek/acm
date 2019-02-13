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

pii ccw(pii p) {
    return {p.x - p.y, p.x + p.y};
}

pii cw(pii p) {
    return {p.y + p.x, p.y - p.x};
}

int n, d;
pii c;
pii a[N];
vector <pii> q1[N], q2[N];
int t[N], u[N];

#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

void push(int x, int tl, int tr) {
    if (!u[x]) return;
    t[x] += u[x];
    if (tl < tr - 1) {
        u[left(x)] += u[x];
        u[right(x)] += u[x];
    }
    u[x] = 0;
}

void upd(int ql, int qr, int qd, int x, int tl, int tr) {
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        u[x] += qd;
        push(x, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    upd(ql, qr, qd, left(x), tl, mid);
    upd(ql, qr, qd, right(x), mid, tr);
    t[x] = min(t[left(x)], t[right(x)]);
}

ll get() {
    int x = 1, tl = 1, tr = 2 * d + 2;
    while (tl < tr - 1) {
        push(x, tl, tr);
        int mid = (tl + tr) / 2;
        if (t[x] == t[left(x)] + u[left(x)]) x *= 2, tr = mid;
        else x = x * 2 + 1, tl = mid;
    }
    return tl - 1;
}

pii poss(ll r) {
    forn(i, 1, n) {
        ll lx = a[i].x - r, rx = a[i].x + r;
        lx = max(lx, 0ll), rx = min(rx, d * 2ll);
        if (lx > rx) continue;
        ll ly = a[i].y - r, ry = a[i].y + r;
        ly = max(ly, 0ll), ry = min(ry, d * 2ll);
        if (ly > ry) continue;
        q1[lx].pb({ly, ry});
        if (rx < 2 * d) q2[rx + 1].pb({ly, ry});
    }
    memset(t, 0, sizeof t);
    memset(u, 0, sizeof u);
    forn(i, 0, 2 * d) {
        for (auto q : q1[i])
            upd(q.x + 1, q.y + 2, +1, 1, 1, 2 * d + 2);
        for (auto q : q2[i])
            upd(q.x + 1, q.y + 2, -1, 1, 1, 2 * d + 2);
        q1[i].clear(), q2[i].clear();
        push(1, 1, 2 * d + 2);
        if (t[1] == 0) {
            forn(j, i + 1, 2 * d)
                q1[j].clear(), q2[j].clear();
            return {i, get()};
        }
    }
    return {INF, INF};
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c.x >> c.y >> d;
    c = ccw(c);
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        a[i] = ccw(a[i]);
        a[i].x -= c.x - d, a[i].y -= c.y - d;
    }

    ll l = 0, r = 1e10;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (poss(mid).x != INF) l = mid;
        else r = mid - 1;
    }
    pii ans = poss(l);
    //cerr << ans.x << " " << ans.y << "\n";
    assert(0 <= ans.x && ans.x <= 2 * d && 0 <= ans.y && ans.y <= 2 * d);
    ans.x += c.x - d, ans.y += c.y - d;
    //cerr << ans.x << " " << ans.y << "\n";
    ans = cw(ans);
    cout << fixed << setprecision(1);
    cout << l + 1 << " " << (ans.x / 2.0) << " " << (ans.y / 2.0) << "\n";

    return 0;
}
