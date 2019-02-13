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
typedef vector <ll> vi;

const int N = 5e3 + 1;
const int INF = 1e9 + 9;
const int B = 666013;

int n, m;
char a[N][N];
int c[N][N];

int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};

void dfs(int i, int j) {
    forn(dir, 0, 3) {
        int x = i + di[dir], y = j + dj[dir];
        if (c[x][y] || a[x][y] != a[i][j] || x < 1 || n < x || y < 1 || m < y) continue;
        c[x][y] = c[i][j];
        dfs(x, y);
    }
}

int u[N * N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];
    int e = 0;
    forn(i, 1, n)
        forn(j, 1, m)
            if (!c[i][j]) {
                c[i][j] = ++e;
                dfs(i, j);
            }
    int q;
    cin >> q;
    forn(it, 1, q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        forn(i, x1, x2)
            forn(j, y1, y2) {
                if (u[c[i][j]] < it) ++ans;
                u[c[i][j]] = it;
            }
        cout << ans << "\n";
    }

    return 0;
}


