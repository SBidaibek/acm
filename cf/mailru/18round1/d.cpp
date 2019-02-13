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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

ll sqr(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    forn(i, 1, n)
        cin >> a[i];

    vi p(n + 1), q(n + 1);
    map <int, ll> cnt;
    ++cnt[0];
    forn(i, 1, n) {
        p[i] = (p[i - 1] ^ a[i]);
        q[i] = ((1 << k) - 1) ^ p[i];
        cnt[min(q[i], p[i])]++;
    }
    ll ans = sqr(n + 1);
    for (auto p : cnt)
        ans -= sqr(p.S / 2) + sqr(p.S - p.S / 2);
    cout << ans << "\n";

    return 0;
}

