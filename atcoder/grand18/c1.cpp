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
typedef vector <int> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int x, y, z;
int a[N][4], u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> z;
    int n = x + y + z;
    forn(i, 1, n)
        forn(j, 1, 3)
            cin >> a[i][j];
    ll ans = 0;
    vector <pii> v, t, v1, v2;
    forn(i, 1, n) {
        v1.emplace_back(a[i][2] - a[i][1], i);
        v2.emplace_back(a[i][3] - a[i][1], i);
    }
    sort(v1.begin(), v1.end(), greater <pii> ());
    sort(v2.begin(), v2.end(), greater <pii> ());
    forn(i, 0, y - 1) {
        v.pb(v1[i]);
        cerr << v1[i].S << "\n";
        u[v1[i].S] = 1;
    }
    int c = 0;
    forn(i, 0, n - 1) {
        if (u[v2[i].S]) continue;
        if (++c > z) break;
        v.pb(v2[i]);
        cerr << v2[i].S << "\n";
        u[v2[i].S] = 1;
    }
    forn(i, 1, n)
        if (!u[i]) {
            cerr << "x: " << i << "\n";
            ans += a[i][1];
        }
    for (auto p : v) {
        int i = p.S;
        t.emplace_back(a[i][3] - a[i][2], i);
    }
    sort(t.begin(), t.end());
    forn(i, 0, y - 1) {cerr << "y: " << t[i].S << "\n";
        ans += a[t[i].S][2];}
    forn(i, y, y + z - 1){cerr << "z: " << t[i].S << "\n";
        ans += a[t[i].S][3];}

    cout << ans << "\n";

    return 0;
}
