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

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int cnt = 0;
pii g(int x, int y) {
    if (++cnt > 1e3) return {-1, -1};
    return {x + (rand() % 3 - 1), y + (rand() % 3 - 1)};
}

int u[N][N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(_t, 1, ts) {
        forn(i, 1, 1000)
            forn(j, 1, 1000) u[i][j] = 0;
        int a;
        cin >> a;
        int s = int(sqrt(a)) + 2;
        bool ok = 0;
        forn(i, 1, s / 3) {
            forn(j, 1, s / 3) {
                int x = 3 * i - 1, y = 3 * j - 1;
                for (int k = 0; k < 9;) {
                    cout << x << " " << y << endl;
                    int ax, ay;
                    //tie(ax, ay) = g(x, y);
                    //cerr << ax << " " << ay << " !\n";
                    cin >> ax >> ay;
                    if (ax == 0 && ay == 0) {
                        ok = 1;
                        break;
                    }
                    k += (!u[ax][ay]);
                    u[ax][ay] = 1;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        //cerr << cnt << "\n";
    }

    return 0;
}
