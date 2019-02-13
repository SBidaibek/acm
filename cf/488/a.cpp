#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

pii a[5], b[5];

pii turn(pii p) {
    return {p.x + p.y, p.x - p.y};
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
    forn(i, 1, 4) {
        cin >> a[i].x >> a[i].y;
        mnx = min(mnx, a[i].x);
        mny = min(mny, a[i].y);
        mxx = max(mxx, a[i].x);
        mxy = max(mxy, a[i].y);
    }
    int mnX = INF, mxX = -INF, mnY = INF, mxY = -INF;
    forn(i, 1, 4) {
        cin >> b[i].x >> b[i].y;
        b[i] = turn(b[i]);
        mnX = min(mnX, b[i].x);
        mnY = min(mnY, b[i].y);
        mxX = max(mxX, b[i].x);
        mxY = max(mxY, b[i].y);
    }
    forn(i, mnx, mxx)
        forn(j, mny, mxy) {
            pii p = turn({i, j});
            if (mnX <= p.x && p.x <= mxX && mnY <= p.y && p.y <= mxY) {
                cout << "yes\n";
                return 0;
            }
        }
    cout << "no\n";

    return 0;
}
