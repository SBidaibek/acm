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

    ll ans = 0;
    while (sum > 0) {
        //cerr << s << " " << sum << " " << tl << " " << tr << "\n";
        ll fn = a[1], fp = a[n];
        int l = 1, r = n;
        for (; l <= tl && tr <= r;) {
            if (fn >= fp) {
                fn += fp;
                fp = a[--r];
            }
            else {
                fp += fn;
                fn = a[++l];
            }
        }
        if (l <= tl) {
            ans += (s - x[tl]);
            s = x[tl];
            sum -= a[tl];
            --tl;
        }
        else {
            ans += (x[tr] - s);
            s = x[tr];
            sum -= a[tr];
            ++tr;
        }
    }
    cout << ans << "\n";

    return 0;
}
