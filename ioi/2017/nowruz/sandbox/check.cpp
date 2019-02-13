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
char a[N][N];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, +1};

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

int main() {

    ld tot = 0;
    forn(it, 1, 10) {
        char inf[20], ouf[20];

        sprintf(inf, "%02d.in", it);
        freopen(inf, "r", stdin);

        cin >> n >> m >> k;

        sprintf(ouf, "%02d.out", it);
        freopen(ouf, "r", stdin);

        forn(i, 1, n)
            forn(j, 1, m)
                cin >> a[i][j];
        ld ans = min(10.0, 10 * leaves() / ld(k));

        ll sum = 0;
        int cnt = 0, lst = 0;
        forn(i, 1, n) {
            lst = 0;
            forn(j, 1, m)
                if (a[i][j] == '#') {
                    sum += j - lst - 1, ++cnt;
                    lst = j;
                }
        }
        ld mean_dist = sum / ld(cnt);

        cerr << "test " << it << ": " << ans << " " << mean_dist << " mean dist\n";
        tot += ans;
    }

    cerr << tot << " points\n";

    return 0;
}
