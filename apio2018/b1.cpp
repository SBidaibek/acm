#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll sqr(ll x) {
    return x * x;
}

ll dist(pii a, pii b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int n;
int ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector <vi> v;
    forn(i, 1, n) {
        int x, y, r;
        cin >> x >> y >> r;
        v.pb({r, -i, x, y});
    }
    sort(v.begin(), v.end(), greater <vi> ());
    forn(i, 0, n - 1) v[i][1] *= -1;
    set <pii> sl, sr;
    forn(i, 0, n - 1)
        sl.insert({v[i][2] - v[i][0], i}), sr.insert({v[i][2] + v[i][0], i});
    forn(i, 0, n - 1) {
        int l = v[i][2] - v[i][0];
        int r = v[i][2] + v[i][0];
        if (ans[v[i][1]]) continue;
        ans[v[i][1]] = v[i][1];
        sl.erase({l, i});
        sr.erase({r, i});
        while (sl.size()) {
            auto it = sl.upper_bound({r, INF});
            if (it == sl.begin()) break;
            --it;
            if (it -> x < l) break;
            int j = it -> y;
            ans[v[j][1]] = v[i][1];
            sl.erase({v[j][2] - v[j][0], j}), sr.erase({v[j][2] + v[j][0], j});
        }
        while (sr.size()) {
            auto it = sr.lower_bound({l, 0});
            if (it == sr.end()) break;
            if (it -> x > r) break;
            int j = it -> y;
            ans[v[j][1]] = v[i][1];
            sl.erase({v[j][2] - v[j][0], j}), sr.erase({v[j][2] + v[j][0], j});
        }
    }
    forn(i, 1, n)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
