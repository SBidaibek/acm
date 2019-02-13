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

const int N = 2e7 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

struct node {
    int s, u, l, r;
} t[N];

int sz;

int new_node() {
    t[++sz] = {0, 0, 0, 0};
    return sz;
}

void push(int x, int tl, int tr) {
    t[x].s += t[x].u * (tr - tl);
    if (tl < tr - 1) {
        if (!t[x].l) t[x].l = new_node();
        if (!t[x].r) t[x].r = new_node();
        t[t[x].l].u += t[x].u;
        t[t[x].r].u += t[x].u;
    }
    t[x].u = 0;
}

void recalc(int x) {
    t[x].s = t[t[x].l].s + t[t[x].r].s;
}

void upd(int ql, int qr, int x, int tl, int tr) {
    //cerr << tl << " " << tr << ": " << t[x].s << " " << ql << " " << qr << "\n";
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        ++t[x].u;
        push(x, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    if (ql < m) upd(ql, qr, t[x].l, tl, m);
    if (m < qr) upd(ql, qr, t[x].r, m, tr);
    recalc(x);
}

int get(int qx, int x, int tl, int tr) {
    //cerr << tl << " " << tr << ": " << t[x].s << " " << qx << "\n";
    push(x, tl, tr);
    if (tl == tr - 1)
        return tl;
    int m = (tl + tr) / 2;
    int ans = 0;
    push(t[x].l, tl, m);
    push(t[x].r, m, tr);
    if (t[t[x].l].s >= qx)
        ans = get(qx, t[x].l, tl, m);
    else
        ans = get(qx - t[t[x].l].s, t[x].r, m, tr);
    recalc(x);
    return ans;
}

int C[3][6];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(_, 1, T) {
        cout << "Case #" << _ << ": ";
        int n, q;
        cin >> n >> q;
        forn(i, 0, 2)
            forn(j, 0, 5)
                cin >> C[i][j];
        vi l(n + 1), r(n + 1), k(q + 1);
        vi x(n + 1), y(n + 1), z(q + 1);
        x[1] = C[0][0], x[2] = C[0][1];
        y[1] = C[1][0], y[2] = C[1][1];
        z[1] = C[2][0], z[2] = C[2][1];
        forn(i, 3, n) {
            x[i] = (C[0][2] * x[i - 1] + C[0][3] * x[i - 2] + C[0][4]) % C[0][5];
            y[i] = (C[1][2] * y[i - 1] + C[1][3] * y[i - 2] + C[1][4]) % C[1][5];
        }
        forn(i, 3, q)
            z[i] = (C[2][2] * z[i - 1] + C[2][3] * z[i - 2] + C[2][4]) % C[2][5];
        forn(i, 1, n) {
            l[i] = min(x[i], y[i]) + 1;
            r[i] = max(x[i], y[i]) + 1;
        }
        forn(i, 1, q)
            k[i] = z[i] + 1;

        sz = 0;
        int root = new_node();
        ll sum = 0;
        forn(i, 1, n) {
            sum += r[i] - l[i] + 1;
            //cerr << l[i] << " " << r[i] << "\n";
            upd(l[i], r[i] + 1, root, 1, 1e9 + 1);
        }
        cerr << sz << "\n";
        ll ans = 0;
        //cerr << get(9, root, 1, 1e9 + 1) << "\n";return 0;
        int sav = sz;
        forn(i, 1, q) {
            if (k[i] > sum) continue;
            //cerr << k[i] << "\n";
            //cerr << i << ": " << get(sum - k[i] + 1, root, 1, 1e9 + 1) << " ";
            ans += 1ll * i * get(sum - k[i] + 1, root, 1, 1e9 + 1);
        }
        //cerr << sav - sz << "\n";
        //assert(sav == sz);
        cout << ans << "\n";
    }

    return 0;
}

