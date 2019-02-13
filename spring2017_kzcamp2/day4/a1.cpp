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
typedef pair <ld, ld> pnt;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

pii operator - (pii a, pii b) {
    return {a.x - b.x, a.y - b.y};
}

ll dp(pii a, pii b) {
    return a.x * b.x + a.y * b.y;
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

ll dist(pnt a, pnt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll dist(pii a, pii b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ostream & operator << (ostream &out, pii p) {
    out << "(" << p.x << " " << p.y << ")";
    return out;
}

const pii O = {0, 0};

bool cmp(pii a, pii b) {
    if (cp(a, b) == 0)
        return dist(a, O) < dist(b, O);
    return cp(a, b) > 0;
}

int n;
pii a[N];

void gelder() {
    sort(a + 1, a + 1 + n);
    pii s = a[1];
    forn(i, 1, n)
        a[i] = a[i] - s;
    sort(a + 2, a + 1 + n, cmp);
    vector <pii> v(1, a[1]);
    forn(i, 1, n) {
        for (; v.size() > 1; v.pop_back()) {
            if (cp(v[v.size() - 1] - v[v.size() - 2], a[i] - v.back()) <= 0) continue;
            break;
        }
        v.pb(a[i]);
    }
    n = v.size();
    forn(i, 1, n)
        a[i] = v[i - 1];
    forn(i, 1, n)
        a[i].x += s.x, a[i].y += s.y;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("friends.in", "r", stdin);
    freopen("friends.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    map <pii, int> mp;
    cin >> n;
    forn(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        mp[a[i]] = i;
    }
    gelder();
    vector <pii> ans;
    int j = 1;
    ll mx = 0;
    forn(i, 1, n) {
        while (j < n && dist(a[i], a[j]) <= dist(a[i], a[j + 1])) ++j;
        ll d = dist(a[i], a[j]);
        if (d < mx) continue;
        if (d == mx)
            ans.pb({i, j});
        else
            ans = {{i, j}}, mx = d;
    }
    pii &pr = ans[0];
    pnt c = a[pr.second] - a[pr.first];
    c.x = c.x / 2 + a[pr.first].x, c.y = c.y / 2 + a[pr.first].y;
    ld r = dist(c, pnt(a[pr.first]));
    forn(i, 1, n) {
        if (dist(c, pnt(a[i])) > r) ans.clear();
    }
    cout << ans.size() << "\n";
    for (auto p : ans)
        cout << mp[a[p.x]] << " " << mp[a[p.y]] << "\n";

    return 0;
}
