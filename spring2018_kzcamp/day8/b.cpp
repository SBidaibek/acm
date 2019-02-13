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

int n, h, s[N], a[N];
ll d[K][K];
int prv[N], nxt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    int mx = 0, mn = INF;
    forn(i, 1, n) {
        cin >> s[i];
        mx = max(mx, s[i]);
        mn = min(mn, s[i]);
    }
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
    vi v;
    forn(i, 0, mx) v.pb(i);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forn(i, 0, v.size() - 1) {
        prv[i] = (i > 0 ? prv[i - 1] : i);
        while (v[i] - h > v[prv[i]]) ++prv[i];
    }
    for1(i, v.size() - 1, 0) {
        nxt[i] = (i == v.size() - 1 ? i : nxt[i + 1]);
        while (v[i] + h < v[nxt[i]]) --nxt[i];
        //cerr << i << " " << v[i] << ": " << prv[i] << " " << nxt[i] << "\n";
    }
    ll ans = 1e18;
    forn(i, 1, n) {
        deque <int> q;
        forn(k, 0, nxt[0]) {
            while (q.size() && q.back() > d[i - 1][k]) q.pop_back();
            q.push_back(d[i - 1][k]);
        }
        forn(j, 0, v.size() - 1) {
            d[i][j] = 1e18;
            if (j > 0) {
                forn(z, 0, prv[j] - prv[j - 1] - 1)
                    if (q.size() && q.front() == d[i - 1][prv[j - 1] + z]) q.pop_front();
                forn(z, 1, nxt[j] - nxt[j - 1]) {
                    while (q.size() && q.back() > d[i - 1][nxt[j - 1] + z]) q.pop_back();
                    q.push_back(d[i - 1][nxt[j - 1] + z]);
                }
            }
            d[i][j] = q.front() + abs(s[i] - v[j]);
            if (i == n) ans = min(ans, d[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}

