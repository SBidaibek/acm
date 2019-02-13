#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 500 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, k;
char a[N][N];
int t[N][N][4];
int u[N][N][4];
int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};

int id(int i, int j) {
    return (i - 1) * m + j;
}

void dfs(int i, int j, int dir) {
    if (u[i][j][dir] == 1) {
        t[i][j][dir] = 0;
        u[i][j][dir] = 2;
        return;
    }
    if (u[i][j][dir] == 2) return;
    u[i][j][dir] = 1;
    int r = i + di[dir], c = j + dj[dir], dr = dir;
    if (r < 1 || n < r || c < 1 || m < c || a[r][c] == 'x') {
        t[i][j][dir] = id(i, j);
        u[i][j][dir] = 2;
        return;
    }
    if (a[r][c] == 'C') dr = (dir + 1) % 4;
    if (a[r][c] == 'A') dr = (dir + 3) % 4;
    dfs(r, c, dr);
    t[i][j][dir] = t[r][c][dr];
    u[i][j][dir] = 2;
}

int d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> m >> n;
    if (k == 1) {
        cout << "0\n";
        return 0;
    }
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];
    queue <PII> q;
    memset(d, -1, sizeof d);
    forn(i, 1, n) {
        forn(j, 1, m) {
            if (a[i][j] == 'x') continue;
            forn(dir, 0, 3)
                dfs(i, j, dir);
        }
    }
    vi v;
    forn(i, 1, n)
        forn(j, 1, m)
            if (isdigit(a[i][j])) v.pb(id(i, j));
    d[v[0]][v[1]] = 0;
    q.push({v[0], v[1]});

    while (q.size()) {
        PII p = q.front();
        q.pop();
        int r1 = (p.F - 1) / m + 1, c1 = (p.F - 1) % m + 1;
        int r2 = (p.S - 1) / m + 1, c2 = (p.S - 1) % m + 1;
        forn(dir, 0, 3) {
            PII to = {t[r1][c1][dir], p.S};
            if (d[to.F][to.S] == -1) {
                d[to.F][to.S] = d[p.F][p.S] + 1;
                q.push(to);
            }
            to = {p.F, t[r2][c2][dir]};
            if (d[to.F][to.S] == -1) {
                d[to.F][to.S] = d[p.F][p.S] + 1;
                q.push(to);
            }
        }
    }

    int ans = -1;
    forn(i, 1, n * m)
        if (d[i][i] != -1)
            ans = (ans == -1 ? d[i][i] : min(ans, d[i][i]));
    cout << ans << "\n";

    return 0;
}
