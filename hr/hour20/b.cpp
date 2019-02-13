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

ll f[N], r[N];

ll bp(ll a, ll b) {
    ll res = 1;
    for (; b; a = a * a % B, b >>= 1)
        if (b & 1) res =res * a % B;
    return res;
}

ll cnk(ll n, ll k) {
    return f[n] * r[k] % B * r[n - k] % B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    r[0] = 1;
    forn(i, 1, N - 1) {
        f[i] = f[i - 1] * i % B;
        r[i] = bp(f[i], B - 2);
    }

    int q;
    cin >> q;
    forn(t, 1, q) {
        string s;
        cin >> s;
        vi cnt(4);
        for (auto x : s)
            ++cnt[x - 'a'];
        if (cnt[0] > cnt[1]) swap(cnt[0], cnt[1]);
        if (cnt[2] > cnt[3]) swap(cnt[2], cnt[3]);
        ll ans1 = 0, ans2 = 0;
        forn(i, 0, cnt[0])
            ans1 = (ans1 + cnk(cnt[0], i) * cnk(cnt[1], i)) % B;
        forn(i, 0, cnt[2])
            ans2 = (ans2 + cnk(cnt[2], i) * cnk(cnt[3], i)) % B;
        cout << (ans1 * ans2  - 1 + B) % B << "\n";
    }

    return 0;
}
