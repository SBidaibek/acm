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

const int INF = 1e9 + 9;
const int B = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= B) a -= B;
}

const int K = 201, N = 103;
int d[N][N][N][K][2];
int tp[K + 5][K + 5];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t >> n >> m;

    forn(i, 0, 2 * n + 1) {
        tp[i][0] = 1;
        forn(j, 1, i)
            tp[i][j] = (tp[i - 1][j - 1] + tp[i - 1][j]) % B;
    }

    int c = n + 1;
    d[0][c][0][0][1] = 1;
    int ans = 0;
    t /= 2;
    forn(s, 0, t) {
        for1(l, c, 0) {
            forn(r, 0, c) {
                forn(k, 0, m) {
                   forn(dir, 0, 1) {
                        if (!d[s][l][r][k][dir]) continue;
                        if (s == t) {
                            int q = max(0, l - 1) + max(0, n - r);
                            add(ans, 1ll * d[s][l][r][k][dir] * tp[q][m - k] % B);
                        }
                        if (l == 0 && r == c && s < t) {
                            if ((t - s) % c == 0 && k == m)
                                add(ans, d[s][l][r][k][dir]);
                            continue;
                        }
                        if (dir)
                            forn(nr, r + 1, min(c, t - s))
                                add(d[s + nr][l][nr][k + (nr == c ? 0 : 1)][dir ^ 1], d[s][l][r][k][dir]);
                        else
                            for1(nl, l - 1, max(0, c - (t - s)))
                                add(d[s + (c - nl)][nl][r][k + (nl == 0 ? 0 : 1)][dir ^ 1], d[s][l][r][k][dir]);
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
