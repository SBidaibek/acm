#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, Q;

ll t[N], sc[N], sn[N], uc[N], fn[N];

#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

void push(int x, int tl, int tr) {
    if (!uc[x] && !fn[x]) return;
    if (fn[x])
        sn[x] = 0, t[x] = 0;
    if (uc[x])
        sc[x] = uc[x] * (tr - tl), t[x] = uc[x] * sn[x] * (tr - tl);
    if (tl < tr - 1) {
        if (fn[x])
            fn[left(x)] = 1, fn[right(x)] = 1;
        if (uc[x])
            uc[left(x)] = uc[x], uc[right(x)] = uc[x];
    }
    uc[x] = 0, fn[x] = 0;
}

void recalc(int x) {
    t[x] = t[left(x)] + t[right(x)];
}

void updc(int ql, int qr, int d, int x = 1, int tl = 1, int tr = n + 1) {
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        uc[x] = d;
        push(x, tl, tr);
        return;
    }
    int mid = (tl + tr) >> 1;
    updc(ql, qr, d, left(x), tl, mid);
    updc(ql, qr, d, right(x), mid, tr);
    recalc(x);
}

void updn(int qv, int x = 1, int tl = 1, int tr = n + 1) {
    push(x, tl, tr);
    if (!qv) return;
    if (tl == tr - 1) {
        sn[x] -= qv;
        t[x] = sn[x] * sc[x];
        return;
    }
    int mid = (tl + tr) >> 1;
    if (sn[left(x)] <= qv) {
        updn(qv - sn[x], right(x), mid, tr);
        fn[left(x)] = 1;
        push(left(x), tl, mid);
    }
    else
        updn(qv, left(x), tl, mid);
    recalc(x);
}

void ass(int qx, int qv, int x = 1, int tl = 1, int tr = n + 1) {
    push(x, tl, tr);
    if (tl == tr - 1) {
        assert(tl == qx);
        sn[x] = qv, t[x] = qv * sc[x];
        return;
    }
    int mid = (tl + tr) >> 1;
    if (qx < mid)
        ass(qx, qv, left(x), tl, mid);
    else
        ass(qx, qv, right(x), mid, tr);
    recalc(x);
}

ll get(int ql, int qr, int x = 1, int tl = 1, int tr = n + 1) {
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t[x];
    int mid = (tl + tr) >> 1;
    ll ans = get(ql, qr, left(x), tl, mid) +
            get(ql, qr, right(x), mid, tr);
    recalc(x);
    return ans;
}

int a[N], g[N], p[N];
ll ans[N];
vector <pii> q[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> Q;
    forn(i, 1, n - 1)
        cin >> a[i];
    forn(i, 1, n)
        cin >> g[i] >> p[i];
    forn(it, 1, Q) {
        int f, t;
        cin >> f >> t;
        q[f].pb({t, it});
    }

    return 0;
    vi st;
    st.pb(n + 1);
    for1(i, n, 1) {
        while (p[i] < p[st.back()]) st.pop_back();
        updc(i, st.back(), p[i]);
        if (a[i] >= g[i])
            ass(i, a[i] - g[i]);
        else
            updn(g[i] - a[i]);
        for (auto e : q[i]) {
            if (e.F == i) continue;
            ans[e.S] = get(i, e.F);
        }
    }

    forn(i, 1, Q)
        cout << ans[i] << "\n";

    return 0;
}
