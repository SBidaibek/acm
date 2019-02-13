#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s;
int x[N], a[N];
ll ps[N], ss[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    ll sum = 0;
    forn(i, 1, n) {
        cin >> x[i] >> a[i];
        sum += a[i];
    }
    int tl = lower_bound(x + 1, x + 1 + n, s) - x - 1;
    int tr = tl + 1;
    if (x[tr] == s) ++tr;
    set <pii> L, R;
    L.insert({0, 0});
    R.insert({0, 0});
    forn(i, 1, tl) {
        L.insert({-a[i] + ps[i - 1], i});
        ps[i] = ps[i - 1] + a[i];
    }
    for1(i, n, tr) {
        R.insert({a[i] - ss[i + 1], i});
        ss[i] = ss[i + 1] + a[i];
    }

    ll ans = 0;
    while (sum > 0) {
        //cerr << s << " " << sum << " " << tl << " " << tr << "\n";
        ll fn = 0, fp = 0;
        for1(i, n, tr) {
            int p = 1;
            if (a[i] + fp + L.begin() -> F <= 0)
                fp -= a[i];
            else
                fp += a[i];
            //fp += a[i] * (p > tl ? +1 : -1);
        }
        forn(i, 1, tl) {
            int p = n;
            if (-a[i] + fn + R.rbegin() -> F > 0)
                fn -= -a[i];
            else
                fn += -a[i];
            //fn += -a[i] * (p < tr ? +1 : -1);
        }
        //cerr << s << " " << sum << " " << fn << " " << fp << "\n";
        if (fn + fp <= 0) {
            ans += (s - x[tl]);
            s = x[tl];
            sum -= a[tl];
            L.erase({-a[tl] + ps[tl - 1], tl});
            --tl;
        }
        else {
            ans += (x[tr] - s);
            s = x[tr];
            sum -= a[tr];
            R.erase({a[tr] - ss[tr + 1], tr});
            ++tr;
        }
    }
    cout << ans << "\n";

    return 0;
}
