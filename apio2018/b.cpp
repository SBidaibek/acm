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
    forn(i, 0, n - 1) {
        if (ans[v[i][1]]) continue;
        ans[v[i][1]] = v[i][1];
        forn(j, i + 1, n - 1) {
            if (ans[v[j][1]]) continue;
            if (dist({v[i][2], v[i][3]}, {v[j][2], v[j][3]}) <= sqr(v[i][0] + v[j][0]))
                ans[v[j][1]] = v[i][1];
        }
    }
    forn(i, 1, n)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
