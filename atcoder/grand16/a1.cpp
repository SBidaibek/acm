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

inline ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int n;
ll a[N], t[N];
ll lst;

ll g(int l, int r) {
    ll ans = 0;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans = gcd(ans, t[l++]);
        if (r % 2 == 0) ans = gcd(ans, t[r--]);
    }
    return ans;
}

int f(int i, ll x) {
    if (!x || g(i, n) > x) return n + 1;
    int l = i, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (g(i, m) > x) l = m + 1;
        else r = m;
    }
    return l;
}

ll G(ll x) {
    ll ans = 0;
    if (x == 1) {
        int p = 1;
        forn(i, 1, n) {
            p = max(p, i);
            ll c = g(i, p);
            for (; p < n && c != x; ++p)
                c = gcd(c, a[p + 1]);
            if (c != x) break;
            ans += n - p + 1;
        }
    }
    else {
        int p1 = 1, p2 = 1;
        forn(i, 1, n) {
            p1 = max(p1, i);
            ll c1 = g(i, p1);
            for (; p1 <= n && c1 > x; ++p1)
                c1 = gcd(c1, a[p1 + 1]);
            if (p1 > n) break;
            p2 = max(p2, i);
            ll c2 = g(i, p2);
            for (; p2 <= n && c2 >= x; ++p2)
                c2 = gcd(c2, a[p2 + 1]);
            cerr << i << ": " << p1 << " " << p2 << " "  << x << "\n";
            ans += p2 - p1;
        }
    }
    return lst = ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n;
    scanf("%d", &n);
    forn(i, 1, n) {
        //cin >> a[i];
        scanf("%lld", &a[i]);
        t[i + n - 1] = a[i];
    }
    for1(i, n - 1, 1)
        t[i] = gcd(t[i * 2], t[i * 2 + 1]);

    ll q, d, c;
    //cin >> q;
    //cin >> d;
    scanf("%d%lld", &q, &d);
    cout << G(d) << "\n";

    forn(i, 2, q) {
        //cin >> c;
        scanf("%lld", &c);
        cout << G(lst ^ c) << "\n";
    }

    return 0;

}
