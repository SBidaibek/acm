#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, q, x;
int a[N];

void uo(int i, int x) {
    for (ot[i += n - 1] = x; i; i >>= 1)
        ot[i] = (ot[i * 2] | ot[i * 2 + 1]);
}

int oget(int l, int r) {
    int ans = 0;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) ans |= t[l++];
        if (!(r & 1)) ans |= t[r--];
    }
    return ans;
}

int gsuf(int i) {
    int l = 0, r = i;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (oget(m, i) >= x) l = m;
        else r = m - 1;
    }
    return l;
}

ll ft[N];

void uf(int i, int x) {
    for(; i <= n; i |= i + 1)
        ft[i] += x;
}

ll fget(int x) {
    if (x == 0) return 0;
    ll ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1)
        ans += ft[x];
    return ans;
}

ll fget(int l, int r) {
    return fget(r) - fget(l - 1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> x;
    forn(i, 1, n) {
        cin >> a[i];
        uo(i, a[i]);
        lft[i] = gsuf(i);
        assert(lft[i] >= lft[i - 1]);
        uf(i, lft[i]);
    }
    forn(it, 1, q) {
        int tp, v, u;
        cin >> tp >> v >> u;
        if (tp == 1) {
            uo(i, u);
            int pos = upper_bound(lft + 1, lft + 1 + pos, v) - lft - 1;
            while (pos >= v) {
                int newp = upper_bound(lft + 1, lft + 1 + pos, v) - lft - 1;
                lft[pos] =
            }
        }
        if (tp == 2) {

        }
    }

    return 0;
}
