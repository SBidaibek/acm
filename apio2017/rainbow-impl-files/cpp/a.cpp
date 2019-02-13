#include <bits/stdc++.h>
#include "rainbow.h"

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

int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};

int n, m;
char a[N][N];

vector <pii> v[3];

void init(int R, int C, int sr, int sc, int M, char *S) {
    n = R, m = C;
    map <char, int> c2i;
    c2i['N'] = 0;
    c2i['E'] = 1;
    c2i['S'] = 2;
    c2i['W'] = 3;
    a[sr][sc] = 1;
    forn(i, 0, M - 1) {
        sr += di[c2i[S[i]]], sc += dj[c2i[S[i]]];
        a[sr][sc] = 1;
    }
    if (n == 2) {
        int cur = 0;
        forn(i, 1, m) {
            if (!a[1][i]) {
                if (!cur) cur = i;
            }
            else {
                if (cur) v[0].pb({cur, i - 1});
                cur = 0;
            }
        }
        if (cur) v[0].pb({cur, m});
        cur = 0;
        forn(i, 1, m) {
            if (!a[2][i]) {
                if (!cur) cur = i;
            }
            else {
                if (cur) v[1].pb({cur, i - 1});
                cur = 0;
            }
        }
        if (cur) v[1].pb({cur, m});
        cur = 0;
        forn(i, 1, m) {
            if (!a[1][i] || !a[2][i]) {
                if (!cur) cur = i;
            }
            else {
                if (cur) v[2].pb({cur, i - 1});
                cur = 0;
            }
        }
        if (cur) v[2].pb({cur, m});
    }
}

int u[52][52];

void dfs(int x, int y, int r1, int c1, int r2, int c2) {
    u[x][y] = 1;
    forn(i, 0, 3) {
        int r = x + di[i], c = y + dj[i];
        if (r1 <= r && r <= r2 && c1 <= c && c <= c2 && !a[r][c] && !u[r][c])
            dfs(r, c, r1, c1, r2, c2);
    }
}

int slow(int r1, int c1, int r2, int c2) {
    memset(u, 0, sizeof u);
    int ans = 0;
    forn(i, r1, r2) {
        forn(j, c1, c2) {
            if (a[i][j] || u[i][j]) continue;
            ++ans;
            dfs(i, j, r1, c1, r2, c2);
        }
    }
    return ans;

}

int f(int z, int l, int r) {
    if (!v[z].size()) return 0;
    int f = upper_bound(v[z].begin(), v[z].end(), pii(l, l)) - v[z].begin();
    if (f != 0 && v[z][f - 1].S >= l) --f;
    int t = upper_bound(v[z].begin(), v[z].end(), pii(r, 1e9 + 1)) - v[z].begin() - 1;
    return t - f + 1;
}

int colour(int r1, int c1, int r2, int c2) {
    if (n > 2) return slow(r1, c1, r2, c2);
    if (r1 < r2)
        return f(2, c1, c2);
    if (r1 == 1)
        return f(0, c1, c2);
    if (r2 == 2)
        return f(1, c1, c2);
}

