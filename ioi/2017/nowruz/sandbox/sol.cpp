#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <int> vi;
typedef double ld;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;

int n, m, k;
char a[N][N], z[N][N];
int d[N][N];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, +1};

int getz(int i, int j) {
    int cnt = 0;
    forn(dir, 0, 3) {
        int x = i + di[dir], y = j + dj[dir];
        cnt += (z[x][y] == '.');
    }
    return cnt;
}

int get(int i, int j) {
    int cnt = 0;
    forn(dir, 0, 3) {
        int x = i + di[dir], y = j + dj[dir];
        cnt += (a[x][y] == '.');
    }
    return cnt;
}

int leaves() {
    int ans = 0;
    forn(i, 1, n)
        forn(j, 1, m)
            if (a[i][j] == '.' && get(i, j) == 1) ++ans;
    return ans;
}

///test 1: seed = 2 val = 10
///test 2: seed = 8 val = 8.57997
///test 3: seed = 5 val = 8.41629
///test 4: seed = 5 val = 8.8968
///test 5: seed = 7 val = 7.88029
///test 6: seed = 1 val = 8.26375
///test 7: seed = 2 val = 8.26814
///test 8: seed = 8 val = 8.36789
///test 9: seed = 7 val = 8.80457
///test 10: seed = 4 val = 9.22229
///86.7 points
int best_seeds[] = {0, 2, 8, 5, 5, 7, 1, 2, 8, 7, 4};

ll kek() {
    forn(i, 1, n)
        forn(j, 1, m)
            z[i][j] = 'X';
    forn(i, 1, n)
        z[i][1] = '.';
    forn(i, 1, n)
        if (i % 3 == 2)
            forn(j, 1, m)
                z[i][j] = '.';
        else
        if (i % 3 == 1)
            forn(j, 3, m)
                {if (j % 2 == 1 || (i == n && j % 4 == 0))
                    z[i][j] = '.';}
        else
        //if (i % 3 == 0)
            forn(j, 3, m)
                if (j % 2 == 0)
                    z[i][j] = '.';
    int ans = 0;
    forn(i, 1, n)
        forn(j, 1, m)
            if (z[i][j] == '.' && getz(i, j) == 1) ++ans;
        forn(i, 1, n)
            forn(j, 1, m)
                cout << z[i][j] << (j == m ? "\n" : "");cerr << ans << " " << k << "\n";
    return ans;
}

int main() {
    ld tot = 0;
    forn(it, 4, 4) {
//    int at = 0;
//    ld mx = 0;
//    forn(seed, 1, 10) {
//        srand(seed);
        if (it == 2 || it == 4) {}
        else continue;
        char inf[20], ouf[20];
        sprintf(inf, "%02d.in", it);
        sprintf(ouf, "%02d.out", it);
        freopen(inf, "r", stdin);
        freopen(ouf, "w", stdout);

        cin >> n >> m >> k;

        forn(i, 0, n + 1)
            forn(j, 0, m + 1)
                a[i][j] = 0;
        forn(i, 1, n)
            forn(j, 1, m)
                cin >> a[i][j];

        {
        ld ans = min(10.0, 10 * kek() / ld(k));
        cerr << "test " << it << ": " << ans << " points\n";
        tot += ans;
        continue;
        }

        int cx = 0, cy = 0;
        while (a[cx][cy] != '.') {
            cx = rand() % n + 1;
            cy = rand() % m + 1;
        }

        queue <pii> q;
        q.push({cx, cy});
        forn(i, 1, n) forn(j, 1, m)
            d[i][j] = -1;
        d[cx][cy] = 0;
        forn(i, 1, n)
            forn(j, 1, m)
                if (a[i][j] == '.') a[i][j] = 'X';
        while (q.size()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if (a[x][y] == '#' || (pii(x, y) != pii(cx, cy) && get(x, y) != 1)) continue;
            a[x][y] = '.';
            forn(dir, 0, 3) {
                int nx = x + di[dir], ny = y + dj[dir];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m &&
                    a[nx][ny] != '#' && d[nx][ny] == -1)
                    d[nx][ny] = d[x][y] + 1, q.push({nx, ny});
            }
        }

        forn(i, 1, n)
            forn(j, 1, m)
                cout << a[i][j] << (j == m ? "\n" : "");

        ld ans = min(10.0, 10 * leaves() / ld(k));
        //if (ans > mx) at = seed;
        //mx = max(mx, ans);
        cerr << "test " << it << ": " << ans << " points\n";
        tot += ans;
    }
//    cout << "test " << it << ": seed = " << at << " val = " << mx << "\n";
//    tot += mx;
//    }
    cerr << tot << " points\n";

    return 0;
}
