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

const int N = 2e6 + 1;
const int INF = 1e9  + 9;
const int B = 1e9 + 7;

ld dist(pii a, pii b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

pii v(pii a, pii b) {
    return {b.x - a.x, b.y - a.y};
}

int n;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    a[0] = a[n];
    ld ans = 1e18;
    forn(i, 1, n) {
        ans = min(ans, dist(a[i], a[i + 1]));
        ans = min(ans, fabs(cp(v(a[i], a[i - 1]), v(a[i], a[i + 1])) / dist(a[i - 1], a[i + 1])) / 2);
    }
    cout << fixed << setprecision(10);
    cout << ans << "\n";

    return 0;
}
