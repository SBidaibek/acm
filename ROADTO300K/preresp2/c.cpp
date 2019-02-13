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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N], d[N], prv[N], lst[N];

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

void recalc(int x) {
    t[x] = min(t[left(x)], t[right(x)]);
}

void upd(int ql, int qr, int qd, int x = 1, int tl = 1, int tr = n + 1) {
    push(x, tl, tr);
    if (ql == qr) return;
    if (qr <= tl || tr <= ql) return;
    if (ql <= tl && tr <= qr) {
        u[x] += qd;
        push(x, tl, tr);
        return;
    }
    int mid = (tl + tr) >> 1;
    upd(ql, qr, qd, left(x), tl, mid);
    upd(ql, qr, qd, right(x), mid, tr);
    recalc(x);
}

int g(int x, int tl, int tr) {
    push(x, tl, tr);
    if (tl == tr - 1) return tl;
    int mid = (tl + tr) >> 1;
    push(right(x), mid, tr);
    if (t[right(x)] == 0)
        return g(right(x), mid, tr);
    else
        return g(left(x), tl, mid);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vi v;
    forn(i, 1, n) {
        cin >> a[i];
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 1, n)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    forn(i, 0, N - 1) t[i] = INF;

    ll ans = 0;
    int p = 1;
    forn(i, 1, n) {
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
        upd(i, i + 1, -INF);
        upd(max(p, prv[i] + 1), i + 1, +1);
        upd(max(p, prv[prv[i]] + 1), prv[i] + 1, -1);
        push(1, 1, n + 1);
        if (t[1] == 0)
            p = g(1, 1, n + 1) + 1;
        ans += i - p + 1;
    }
    cout << ans << "\n";

    return 0;
}
