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

bool can(int x, vector <pii> &v) {
    int s = 0, c = 0;
    for1(i, v.size() - 1, 0) {
        if (v[i].S > x) continue;
        ++c, s += v[i].F;
        if (s > c * 2) return 0;
    }
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <pii> a(n + 1);
    map <int, int> c;
    forn(i, 1, n) {
        cin >> a[i].F >> a[i].S;
        ++c[a[i].F],  ++c[a[i].S];
    }

    vector <pii> v;
    for (auto p : c)
        v.pb({p.S, p.F});
    sort(v.begin(), v.end());

    if (!can(1e9, v)) {
        cout << "-1\n";
        return 0;
    }
    int l = 1, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (!can(m, v)) l = m + 1;
        else r = m;
    }
    cout << l << "\n";

    return 0;
}
