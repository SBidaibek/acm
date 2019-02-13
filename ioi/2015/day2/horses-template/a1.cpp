#include <bits/stdc++.h>
#include "horses.h"

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

int n;
int a[N], b[N];
set <int> st;

int t[N];
ll p[N];

ll pwr(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % B)
        if (b & 1) res = res * a % B;
    return res;
}

void u1(int x, ll u) {
    ll d = u * pwr(a[x], B - 2) % B;
    a[x] = u;
    for (; x < n; x |= x + 1) p[x] = p[x] * d % B;
}

int g1(int x) {
    ll ans = 1;
    for (; x >= 0; x = (x & (x + 1)) - 1) ans = ans * p[x] % B;
    return ans;
}

void u2(int x, int u) {
    t[x += n] = u;
    for (x >>= 1; x; x >>= 1) t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int g2(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans = max(ans, t[l++]);
        if (r % 2 == 0) ans = max(ans, t[r--]);
    }
    return ans;
}

pair <int, set <int> :: iterator> p2() {
    ll cur = 1;
    for (auto it = st.end();;) {
        --it;
        cur = cur * a[*it];
        if (cur > 1e9)
            return {*it, it};
        if (it == st.begin())
            return {0, it};
    }
}

ll g() {
    if (!st.size()) return g2(0, n - 1);
    auto q = p2();
    int x = q.F;
    auto it = q.S;
    ll ans = b[x], cur = 1;
    if (x < *it) ans = g2(x, *it - 1);
    else {
        auto nxt = it;
        ++nxt;
        ans = g2(*it, *nxt - 1);
        ++it;
    }
    for (; it != st.end(); ++it) {
        auto nxt = it;
        ++nxt;
        cur = cur * a[*it];
        ans = max(ans, cur * g2(*it, (nxt == st.end() ? n : *nxt) - 1));
    }
    return (ans % B) * g1(x) % B;
}

int init(int k, int X[], int Y[]) {
    n = k;
    forn(i, 0, n - 1)
        a[i] = 1, p[i] = 1;
    forn(i, 0, n - 1) {
        if (X[i] > 1) st.insert(i);
        u1(i, X[i]);
        b[i] = Y[i];
        u2(i, Y[i]);
    }
    return g();
}

int updateX(int pos, int val) {
    if (a[pos] > 1) st.erase(pos);
    u1(pos, val);
    if (a[pos] > 1) st.insert(pos);
	return g();
}

int updateY(int pos, int val) {
	b[pos] = val;
	u2(pos, val);
	return g();
}
