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

const int K = 201, N = 31;
int d[K][N * 2][N * 2][K];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t >> n >> m;

    int c = n + 1;
    d[0][0][0][0] = 1;
    int ans = 0;
    forn(s, 0, t) {
        for1(l, c, 0) {
            forn(r, c, c + n + 1) {
                forn(k, 0, m) {
                    if (!d[s][l][r][k]) continue;
                    if (s == t && k == m)
                        add(ans, d[s][l][r][k]);
                    if (k % 2 == 0) {
                        forn(nr, r + 1, min(c + n + 1, (t - s) / 2)
                            add(d[s + (nr - c) * 2][l][nr][k + 1], d[s][l][r][k]);
                    }
                    else {
                        for1(nl, l - 1, max(0, c - (t - s) / 2)
                            add(d[s + (c - nl) * 2][l][nr][k + 1], d[s][l][r][k]);
                    }
                }
            }
        }
    }

    return 0;
}
