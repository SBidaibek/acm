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
typedef vector <int> vi;

const int N = 1e3 + 20;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s, t, u, v;
int a[N], b[N], c[N], d[N];

int m[N][N][4], dst[N][N][4], used[N][N][4];
int di[] = {0, -1, 0, +1};
int dj[] = {-1, 0, +1, 0};

const int K = 1001;
vi q[K * K * 10];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t >> u >> v;
    cin >> n;
    forn(i, 1, n) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        forn(j, a[i] + 1, b[i] - 1)
            m[j][c[i]][2] = m[j][d[i]][0] = 1;
        forn(j, c[i] + 1, d[i] - 1)
            m[a[i]][j][3] = m[b[i]][j][1] = 1;
    }

    forn(i, 0, K)
        forn(j, 0, K)
            forn(k, 0, 3)
                dst[i][j][k] = INF;
    int hd = K * K * 5, tl = K * K * 5 - 1;
    forn(i, 0, 3) {
        //q.push_front({s, t, i});
        q[--hd] = {s, t, i};
        dst[s][t][i] = 0;
    }
    int cnt = 0;
    while (hd <= tl) {
        vi p = q[hd++];
        ++cnt;
        assert(cnt <= K * K * 8);
        //cerr << p[0] << " " << p[1] << " " << p[2] << "\n";
        if (used[p[0]][p[1]][p[2]]) continue;
        used[p[0]][p[1]][p[2]] = 1;

        vi to = {p[0] + di[p[2]], p[1] + dj[p[2]], p[2]};
        if (!m[p[0]][p[1]][p[2]] && 0 <= min(to[0], to[1]) && max(to[0], to[1]) <= K
            && dst[to[0]][to[1]][to[2]] > dst[p[0]][p[1]][p[2]]) {
            dst[to[0]][to[1]][to[2]] = dst[p[0]][p[1]][p[2]];
            q[--hd] = to;
            //q.push_front(to);
        }

        forn(i, 0, 3) {
            if (i == p[2]) continue;
            vi to = {p[0] + di[i], p[1] + dj[i], i};
            if (!m[p[0]][p[1]][i] && 0 <= min(to[0], to[1]) && max(to[0], to[1]) <= K
                && dst[to[0]][to[1]][to[2]] > dst[p[0]][p[1]][p[2]] + 1) {
                dst[to[0]][to[1]][to[2]] = dst[p[0]][p[1]][p[2]] + 1;
                q[++tl] = to;
                //q.push_back(to);
            }
        }
    }
    int mn = 1e9;
    forn(i, 0, 3)
        if (dst[u][v][i] != -1)
            mn = min(mn, dst[u][v][i]);
    cout << mn << "\n";

    return 0;
}

