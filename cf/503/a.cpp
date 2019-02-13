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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
pii pc[N];
ll a[N];
vector <pii> v[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        cin >> pc[i].S >> pc[i].F;
    sort(pc + 1, pc + 1 + n);
    forn(i, 1, n) {
        v[pc[i].S].pb({pc[i].F, i});
        ++a[pc[i].S];
    }
    forn(i, 1, m)
        sort(v[i].begin(), v[i].end());

    ll ans = 1e18 + INF;
    forn(val, max(1ll, a[1]), n) {
        vector <bool> del(n + 1);
        ll cur = 0;
        ll h = a[1];
        bool shit = 0;
        forn(i, 2, m) {
            /*if (v[i].size() < a[i] - val + 1) {
                shit = 1;
                break;
            }*/
            forn(j, 1, a[i] - val + 1)
                cur += v[i][j - 1].F, del[v[i][j - 1].S] = 1, ++h;
        }
        if (shit) continue;
        forn(i, 1, n) {
            if (h >= val) break;
            if (del[i] || pc[i].S == 1) continue;
            ++h;
            cur += pc[i].F;
        }
        if (h >= val)
            ans = min(ans, cur);
    }

    cout << ans << "\n";

    return 0;
}
