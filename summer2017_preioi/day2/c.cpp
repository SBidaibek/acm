#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pii;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ld LI(pii p1, pii p2) {
    return (p2.S - p1.S) / (p1.F - p2.F);
}

int n;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    map <pii, int> mp, cnt;
    cin >> n;
    ld C = 1;
    forn(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a[i] = {C / x, C / y};
        ++cnt[a[i]];
        mp[a[i]] = i - 1;
    }
    sort(a + 1, a + 1 + n, greater <pii> ());

    vi v;
    forn(i, 1, n) {
        while (v.size() > 1) {
            if (a[i].F == a[v.back()].F || LI(a[v[v.size() - 2]], a[i]) <= LI(a[v[v.size() - 2]], a[v.back()]))
            v.pop_back();
            else break;
        }
        v.pb(i);
    }
    vi ans;
    forn(i, 0, v.size() - 1) {
        if (i < v.size() - 1 && LI(a[v[i]], a[v[i + 1]]) <= 0) continue;
        /*if (i > 0) {
            if (i == 0) cerr << v[i] << " " << LI(a[v[i]], a[v[i - 1]]) << "\n";
            ld x = LI(a[v[i - 1]], a[v[i]]);
            if (a[v[i]].F * x + a[v[i]].S <= 0) break;
        }*/
        int x = v[i];
        if (cnt[a[x]] == 1)
            ans.pb(mp[a[x]]);
    }
    sort(ans.begin(), ans.end());
    if (!ans.size()) cout << "-1\n";
    for (auto x : ans) cout << x << " ";

    return 0;
}
