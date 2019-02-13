#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const ll INF = 2e18;
const int B = 1e9 + 7;

ll n, x, y;
pii a[N];

ll solve(ll k) {
    multiset <ll> st;
    ll ans = 0;
    forn(i, 1, n) {
        //cerr << a[i].F << " " << a[i].S << "\n";
        if (st.size() == 0) {
            st.insert(a[i].S);
            ans = (ans + x + (a[i].S - a[i].F) * y) % B;
            continue;
        }
        ll cost = INF;
        auto it = st.lower_bound(a[i].F);
        if (it != st.begin()) {
            --it;
            int prv = *it;
            cost = y * (a[i].S - prv);
        }
        if (cost == INF && st.size() == k) return INF;
        if (st.size() == k || cost <= x + (a[i].S - a[i].F) * y) {
            ans = (ans + cost) % B;
            st.erase(it);
            st.insert(a[i].S);
        }
        else {
            st.insert(a[i].S);
            ans = (ans + x + (a[i].S - a[i].F) * y) % B;
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

    cin >> n;
    cin >> x >> y;
    forn(i, 1, n)
        cin >> a[i].F >> a[i].S;
    sort(a + 1, a + 1 + n);
//    forn(i, 1, n) {
//        cerr << solve(i) << "\n";
//    }

    cout << solve(n) % B << "\n";
    return 0;
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (solve(m) >= solve(m + 1))
            l = m + 1;
        else
            r = m;
    }
    cerr << l << "\n";
    cout << solve(l) % B << "\n";

    return 0;
}

