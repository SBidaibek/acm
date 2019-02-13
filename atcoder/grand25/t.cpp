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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k;
pii a[N];
ll cl[N], cr[N], lm[N], rm[N];

ll check(int d) {
    vi p;
    forn(i, 1, n) {
        p.pb(a[i].x - (d - a[i].y));
        p.pb(a[i].x);
        p.pb(a[i].x + (d - a[i].y) + 1);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    forn(i, 1, p.size())
        cl[i] = cr[i] = lm[i] = rm[i] = 0;
    forn(i, 1, n) {
        if (d < a[i].y) continue;
        int l = a[i].x - (d - a[i].y);
        int m = a[i].x;
        int r = a[i].x + (d - a[i].y) + 1;
        l = lower_bound(p.begin(), p.end(), l) - p.begin() + 1;
        m = lower_bound(p.begin(), p.end(), m) - p.begin() + 1;
        r = lower_bound(p.begin(), p.end(), r) - p.begin() + 1;
        if (d > a[i].y) {
            ++cl[l];
            --cl[m];
            lm[l] += a[i].y + a[i].x;
            lm[m] -= a[i].y + a[i].x;
        }
        ++cr[m];
        --cl[r];
        rm[m] += a[i].y - a[i].x;
        rm[r] -= a[i].y - a[i].x;

    }
    ll ans = -1;
    forn(i, 1, p.size()) {
        cl[i] += cl[i - 1], cr[i] += cr[i - 1];
        lm[i] += lm[i - 1], rm[i] += rm[i - 1];
        if (cl[i] + cr[i] >= k) {
            ll cur = 0;
            cur += cr[i] * p[i - 1] + rm[i];
            cur += lm[i] - cl[i] * p[i - 1];
            if (ans == -1 || ans > cur) ans = cur;
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> k;
	forn(i, 1, n)
	    cin >> a[i].x >> a[i].y;

	int l = 0, r = 2e8;
	while (l < r) {
	    int m = (l + r) / 2;
	    if (check(m) == -1) l = m + 1;
	    else r = m;
	}
	cout << check(l) << "\n";

    return 0;
}
