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
typedef vector <int> vi;

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 6e3;

ll n, h, s[N], a[N];
ll l[N], r[N], b[N];

int getmed(int p) {
    vi v;
    forn(i, p, n)
        v.pb(b[i]);
    nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    return v[v.size() / 2];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    forn(i, 1, n)
        cin >> s[i];
    if (h == 0) {
        sort(s + 1, s + 1 + n);
        ll sp = 0, ss = 0;
        forn(i, 1, n) ss += s[i];
        ll ans = 1e18;
        forn(i, 1, n) {
            ss -= s[i];
            sp += s[i];
            ans = min(ans, 1ll * i * s[i] - sp + ss - 1ll * (n - i) * s[i]);
        }
        cout << ans << "\n";
        return 0;
    }
    l[0] = -INF, r[0] = INF;
    forn(i, 1, n - 1) {
        l[i] = s[i] - s[i + 1] - h;
        r[i] = s[i] - s[i + 1] + h;
    }
    forn(i, 0, n - 1)
          cerr << i << "| " << l[i] << " "<< r[i] << "\n";
    b[n] = 0;
    for1(i, n - 1, 0) {
        cerr << i << ": ";forn(j, i, n) cerr << b[j] << " ";cerr << "\n";
        forn(j, i, n - 1) {
            ll d = -(getmed(j + 1) - a[i]);
            ll x = d;
            x = max(x, l[j] - (b[j + 1] - b[j]));
            x = min(x, r[j] - (b[j + 1] - b[j]));
            b[j] -= x;
            //forn(k, j + 1, n)
            //    b[k] += x;
            cerr << i << ": ";forn(k, i, n) cerr << b[k] << " ";cerr << "\n";
        }
    }
    forn(i, 1, n)
        s[i] += b[i];
    //forn(i, 1, n)
    //                 cerr << s[i] << " ";cerr << "\n";
    forn(i, 2, n)
        assert(abs(s[i] - s[i - 1]) <= h);
    ll ans = 0;
    forn(i, 1, n)
        ans += abs(b[i]);
    cout << ans << "\n";

    return 0;
}

