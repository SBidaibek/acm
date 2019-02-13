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

ll n2(ll x) {
    forn(i, 0, 40)
        if ((1ll << i) >= x) return i;
}

int n;
ll a[N], c[N], r[N], o[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        ll x = (1ll << n2(a[i]));
        if (x == a[i])
            ++c[n2(a[i])];
        else
            ++r[n2(a[i])];
    }
    if (c[0] == 0) {
        cout << "-1\n";
        return 0;
    }
    forn(i, 0, 40) o[i] = r[i];
    vi ans;
    forn(i, 1, c[0]) {
        forn(j, 0, 40) r[j] = o[j];
        r[0] = c[0] - i;
        ll x = i;
        forn(j, 1, 40) {
            if (x <= c[j]) {
                r[j] += (c[j] - x);
            }
            else {
                ll k = x - c[j];
                x = c[j];
                forn(j2, 0, j) {
                    int t = min(k, r[j2]);
                    r[j2] -= t;
                    k -= t;
                }
            }
        }
        bool shit = 0;
        forn(j, 0, 40)
            if (r[j] != 0) shit = 1;
        if (!shit) ans.pb(i);
    }
    if (!ans.size()) ans.pb(-1);
    for (auto x : ans) cout << x << " ";

    return 0;
}
