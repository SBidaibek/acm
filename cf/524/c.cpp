#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;

ll W(ll n, ll m) {
    return (n * m + 1) / 2;
}

ll B(ll n, ll m) {
    return n * m / 2;
}

ll G(ll x1, ll y1, ll x2, ll y2) {
    if ((x1 + y1) % 2 == 0)
        return W(x2 - x1 + 1, y2 - y1 + 1);
    else
        return B(x2 - x1 + 1, y2 - y1 + 1);
}

ll A(ll lx, ll ly, ll rx, ll ry) {
    return (rx - lx + 1) * (ry - ly + 1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        ll w = W(n, m);

        ll x1, y1, x2, y2;
        ll x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        w -= G(x1, y1, x2, y2);
        w += A(x1, y1, x2, y2);
        w -= G(x3, y3, x4, y4);

        ll lx = max(x1, x3), rx = min(x2, x4);
        ll ly = max(y1, y3), ry = min(y2, y4);
        if (lx <= rx && ly <= ry) {
            w -= A(lx, ly, rx, ry);
            w += G(lx, ly, rx, ry);
        }

        cout << w << " " << n * m - w << "\n";
    }

    return 0;
}
