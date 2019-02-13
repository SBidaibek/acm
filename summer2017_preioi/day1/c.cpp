#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int C[N], used[N];
int sz;

ll n, t[N], u[N], t2[N], pre[N];

void rec() {
    t[C[sz]] = u[C[sz]] = t2[C[sz]] = 0;
    used[C[sz]] = 0;
    --sz;
}

#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

void build(int x = 1, int tl = 1, int tr = 2 * n + 2) {
    if (tl == tr - 1) {
        pre[x] = 2 * n + 2 - tl;
        return;
    }
    int m = (tl + tr) / 2;
    build(left(x), tl, m);
    build(right(x), m, tr);
    pre[x] = pre[left(x)] + pre[right(x)];
}

void push(int x, int tl, int tr) {
    if (!used[x]) {
        C[++sz] = x;
        used[x] = 1;
    }
    if (!used[left(x)]) {
        C[++sz] = left(x);
        used[left(x)] = 1;
    }
    if (!used[right(x)]) {
        C[++sz] = right(x);
        used[right(x)] = 1;
    }
    if (!u[x]) return;
    t[x] += (tr - tl) * u[x];
    t2[x] += pre[x] * u[x];
    if (tl < tr - 1) {
        u[left(x)] += u[x];
        u[right(x)] += u[x];
    }
    u[x] = 0;
}

void recalc(int x) {
    t[x] = t[left(x)] + t[right(x)];
    t2[x] = t2[left(x)] + t2[right(x)];
}

void inc(int ql, int qr, int x = 1, int tl = 1, int tr = 2 * n + 2) {
    if (ql >= qr) return;
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        ++u[x];
        push(x, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    inc(ql, qr, left(x), tl, m);
    inc(ql, qr, right(x), m, tr);
    recalc(x);
}

ll G(int ql, int qr, int x = 1, int tl = 1, int tr = 2 * n + 2) {
    if (ql >= qr) return 0;
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t2[x];
    int m = (tl + tr) / 2;
    ll ans = G(ql, qr, left(x), tl, m) + G(ql, qr, right(x), m, tr);
    recalc(x);
    return ans;
}

ll g(int ql, int qr, int x = 1, int tl = 1, int tr = 2 * n + 2) {
    if (ql >= qr) return 0;
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t[x];
    int m = (tl + tr) / 2;
    ll ans = g(ql, qr, left(x), tl, m) + g(ql, qr, right(x), m, tr);
    recalc(x);
    return ans;
}

int a[N];
vi v[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        v[a[i]].pb(i);
    }
    build();
    int shift = n + 1;
    ll ans = 0;
    forn(i, 1, n) {
        if (!v[i].size()) continue;
        inc(shift, shift + 1);
        int p = 0, prv = 0;
        v[i].pb(n + 1);
        for (auto j : v[i]) {
            if (j - 1 > prv) {
                int d = j - prv - 1;
                ans += g(1, p - d + shift) * d;
                ans += G(p - d + shift, p + shift)
                        - g(p - d + shift, p + shift) * (2 * n + 2 - (p - 1 + shift));
                inc(p - d + shift, p + shift);
            }
            if (j > n) break;
            p += -(j - prv - 1) + 1;
            inc(p + shift, p + 1 + shift);
            ans += g(1, p + shift);
            prv = j;
        }
        while (sz > 0) rec();
    }
    cout << ans << "\n";

    return 0;
}
