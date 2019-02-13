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

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
ll t[N], mx[N], u[N];
bool f[N];

#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

void recalc(int x) {
    t[x] = t[left(x)] + t[right(x)];
    mx[x] = max(mx[left(x)], mx[right(x)]);
}

void push(int x, int tl, int tr) {
    if (!f[x]) return;
    t[x] = u[x] * (tr - tl);
    mx[x] = u[x];
    if (tl < tr - 1) {
        f[left(x)] = 1;
        u[left(x)] = u[x];
        f[right(x)] = 1;
        u[right(x)] = u[x];
    }
    f[x] = 0;
}

void upd(int ql, int qr, int d, int x, int tl, int tr) {
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        f[x] = 1;
        u[x] = d;
        push(x, tl, tr);
        return;
    }
    int m = (tl + tr) >> 1;
    upd(ql, qr, d, left(x), tl, m);
    upd(ql, qr, d, right(x), m, tr);
    recalc(x);
}

int px(int qd, int x, int tl, int tr) {
    push(x, tl, tr);
    if (tl == tr - 1) return tl;
    int m = (tl + tr) >> 1, ans;
    if (mx[left(x)] > qd) {
        ans = px(qd, left(x), tl, m);
        px(qd, right(x), m, tr);
    }
    else {
        px(qd, left(x), tl, m);
        ans = px(qd, right(x), m, tr);
    }
    recalc(x);
    return ans;
}

ll get(int ql, int qr, int x, int tl, int tr) {
    if (ql >= qr) return 0;
    push(x, tl, tr);
    if (qr <= tl || tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t[x];
    int m = (tl + tr) >> 1;
    ll ans = get(ql, qr, left(x), tl, m) +
            get(ql, qr, right(x), m, tr);
    recalc(x);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    upd(1, n + 1, 2e9, 1, 1, n + 1);
    int p = 0, k = 0;
    ll s = 0;
    forn(i, 1, n) {
        cerr << i << ": ";
        cerr << s << "\n";
        forn(j, 1, n) cerr << get(j, j + 1, 1, 1, n + 1) <<" ";
        cerr << "\n";
        int tp, g;
        cin >> tp >> g;
        if (tp == 0) {
            s += g;
            if (s < 0) {
                cout << "-1\n";
                return 0;
            }
            if (g < 0 && k) {
                int l = 0;
                while (l < k) {
                    int m = (l + k + 1) >> 1;
                    if (get(1, m + 1, 1, 1, n + 1) > s) k = m - 1;

                    else l = m;
                }
            }
        }
        else {
            if (g <= 0) {
                ++p;
                s += -g;
                continue;
            }
            ll save = get(1, k + 1, 1, 1, n + 1);
            if (k) {
                int x = px(g, 1, 1, n + 1);
                if (x <= k) upd(x, k + 1, g, 1, 1, n + 1);
            }
            if (s >= save + g) {
                upd(k + 1, k + 2, save + g - get(1, k + 1, 1, 1, n + 1), 1, 1, n + 1);
                ++k;
            }
        }
    }
    cout << k + p << "\n";

    return 0;
}
