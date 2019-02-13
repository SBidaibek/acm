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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
char a[N][N];

int di[] = {0, -1, 0, +1};
int dj[] = {-1, 0, +1, 0};

bool in(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

int bd[N][N];

void prec1() {
    queue <pii> q;
    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            if (a[i][j] == '#')
                q.push({i, j});
            else
                bd[i][j] = -1;
    while (q.size()) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();
        forn(dir, 0, 3) {
            int ni = i + di[dir], nj = j + dj[dir];
            if (!in(ni, nj) || bd[ni][nj] != -1) continue;
            bd[ni][nj] = bd[i][j] + 1;
            q.push({ni, nj});
        }
    }
}

int d[N][N], to[N][N][4];
bool u[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 0, n + 1)
        forn(j, 0, m + 1) a[i][j] = '#';
    int f = 0;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] != '#') ++f;
        }

    prec1();
    forn(dir, 0, 3) {
        for (int i = (dir != 1 ? n : 1); in(i, 1); (dir != 1 ? --i : ++i)) {
            for (int j = (dir != 0 ? m : 1); in(1, j); (dir != 0 ? --j : ++j)) {
                if (a[i][j] == '#') continue;
                int ni = i + di[dir], nj = j + dj[dir];
                to[i][j][dir] = (a[ni][nj] == '#' ? 0 : to[ni][nj][dir] + 1);
            }
        }
    }
    forn(i, 0, n + 1)
        forn(j, 0, m + 1)
            d[i][j] = (a[i][j] == 'S' ? 0 : INF);

    forn(it, 1, f) {
        int mi = -1, mj = -1;
        forn(i, 1, n)
            forn(j, 1, m)
                if (!u[i][j] && a[i][j] != '#' && (mi == -1 || d[i][j] < d[mi][mj]))
                    mi = i, mj = j;
        if (mi == -1 || d[mi][mj] == INF) continue;
        int i = mi, j = mj;
        u[i][j] = 1;
        forn(dir, 0, 3) {
            int ni = i + di[dir], nj = j + dj[dir];
            if (!in(ni, nj) || a[ni][nj] == '#') continue;
            d[ni][nj] = min(d[ni][nj], d[i][j] + 1);
            if (to[i][j][dir]) {
                ni = i + to[i][j][dir] * di[dir], nj = j + to[i][j][dir] * dj[dir];
                d[ni][nj] = min(d[ni][nj], d[i][j] + bd[i][j]);
            }
        }
    }
    forn(i, 1, n)
        forn(j, 1, m)
            if (a[i][j] == 'C')
                cout << d[i][j] << "\n";

    return 0;
}
