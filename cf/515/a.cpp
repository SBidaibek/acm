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
typedef vector <int> vi;

const int N = 4e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int di[] = {+1, 0, -1, 0, -1, -1, +1, +1};
int dj[] = {0, -1, 0, + 1, -1, +1, -1, +1};
int u[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    pii p[4];
    forn(i, 1, 3)
        cin >> p[i].x >> p[i].y;
    queue <pii> q;
    q.push({p[2]});
    while (q.size()) {
        int x = q.front().x, y = q.front().y;
        u[x][y] = 1;
        //cerr << x << " " << y << "\n";
        q.pop();
        forn(dir, 0, 7) {
            int i = x + di[dir], j = y + dj[dir];
            if (1 <= i && i <= n && 1 <= j && j <= n && !u[i][j]
                && j != p[1].y && i != p[1].x &&
                abs(p[1].x - i) != abs(p[1].y - j)) {
                u[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    cout << (u[p[3].x][p[3].y]  ? "YES\n" : "NO\n") << "\n";

    return 0;
}

