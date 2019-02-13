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

const int opt = 4000;
const int coef = 500;

int n, m;
char a[N][N];
int b[N][N];

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void out() {
    forn(i, 1, n) {
        forn(j, 1, m) cout << a[i][j];
        cout << "\n";
    }
    exit(0);
}

void super_dfs(int r, int c, int len = 3) {
    //cerr << len << "\n";
    if (r == n || r == 1 || c == 1 || c == m) {
        a[r][c] = '.';
        if (len >= coef) out();
        a[r][c] = '#';
        return;
    }
    a[r][c] = '.';
    a[r][22 - c] = '.';
    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (!b[x][y]) b[x][y] = r * m + c;
    }

    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (x == n || x == 1 || y == 1 || y == m) {
            super_dfs(x, y, len + 1);
        }
        if (b[x][y] == r * m + c && a[x][y] == '#')
            super_dfs(x, y, len + 2);
    }

    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (b[x][y] == r * m + c) b[x][y] = 0;
    }
    a[r][c] = '#';
    a[r][22 - c] = '#';
}

void dfs(int r, int c, int len = 1) {
    if (a[r][c] == 'X') return;
    //cerr << len << "\n";
    a[r][c] = '.';
    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (!b[x][y]) b[x][y] = r * m + c;
    }
    if (len >= coef) out();

    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (b[x][y] == r * m + c && a[x][y] == '#')
            dfs(x, y, len + 1);
    }

    forn(i, 0, 3) {
        int x = di[i] + r, y = dj[i] + c;
        if (b[x][y] == r * m + c) b[x][y] = 0;
    }
    a[r][c] = '#';
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    n = 100, m = 100;
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];
    forn(i, 1, n)
        b[i][1] = b[i][m] = -1;
    forn(i, 1, m)
        b[1][i] = b[n][i] = -1;
//
//    forn(i, 1, n)
//        dfs(i, 1), dfs(i, m);
//    forn(i, 1, m)
//        dfs(1, i), dfs(n, i);

    vi t(30);
   if (!t[0]) {
      t[0] = 1;
      t[1] = 3;
      t[2] = 7;
      for (int i=3; i<30; i++) t[i] = t[i-2] + (1l<<i);
   }
   forn(i, 0, 29)
    cerr << i << " " << t[i] << "\n";

    return 0;
}
