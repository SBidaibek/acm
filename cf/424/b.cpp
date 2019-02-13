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

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
int a[N], t[N];
set <int> st[N];

void u(int x) {
    for (; x <= n; x |= x + 1) ++t[x];
}

int g(int x) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) ans += t[x];
    return ans;
}

int d(int x, int y) {
    return x < y ? y - x - (g(y) - g(x)) : n - x + y - (g(n) - g(x)) - g(y);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mn = 1;
    forn(i, 1, n) {
        cin >> a[i];
        st[a[i]].insert(i);
        if (a[mn] > a[i]) mn = i;
    }
    ll ans = mn;
    st[a[mn]].erase(mn);
    forn(i, 2, n) {
        int nxt = a[mn];
        u(mn);
        while (st[nxt].size() == 0) ++nxt;
        if (*--st[nxt].end() < mn) {
            ans += d(mn, *st[nxt].begin());
            mn = *st[nxt].begin();
            st[nxt].erase(st[nxt].begin());
        }
        else {
            int x = *st[nxt].lower_bound(mn);
            ans += d(mn, x);
            mn = x;
            st[nxt].erase(x);
        }
    }
    cout << ans << "\n";

    return 0;
}
