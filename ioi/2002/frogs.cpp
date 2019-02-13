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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, r, c;
int id[N][N];
pii a[N];
int d[N];

ostream & operator << (ostream &out, pii p) {
    return out << "(" << p.x << " " << p.y << ")"   ;
}

vi v[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + n);
    forn(i, 1, n)
        id[a[i].x][a[i].y] = i;
    forn(i, 1, n)
        forn(j, 1, i - 1)
            v[i][a[i].x - a[j].x].pb(j);



    forn(i, 1, n) {
        forn(j, 1, i - 1) {
            int x = a[j].x - (a[i].x - a[j].x);
            int y = a[j].y - (a[i].y - a[j].y);
            d[j] = 1 + (1 <= x && x <= r && 1 <= y && y <= c ?
                d[id[x][y]] : 0);
            cerr << a[i] << ": " << a[j] << " " << d[j] << "\n";
            ans = max(ans, d[j]);
        }

    }
    cout << ans << "\n";

    return 0;
}
