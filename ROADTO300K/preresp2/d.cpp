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

int n, len;
int a[N];
int d[N][N][2];
int c[N][N][2];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> len;
    int mx = 0;
    forn(i, 1, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    mx *= 2;
    forn(l, 1, n - len + 1) {
        forn(i, 0, mx)
            forn(j, 0, mx)
                forn(k, 0, 1)
                    d[i][j][k] = c[i][j][k] = 0;
        d[0][0][1] = 0;
        c[0][0][1] = 1;
        forn(i, l, l + len - 1) {
            int z = (i - l) % 2;
            forn(j, 0, mx)
                forn(k, 0, mx) {
                    d[j][k][z] = d[j][k][z ^ 1];
                    c[j][k][z] = c[j][k][z ^ 1];

                    if (d[j][k][z] == d[j ^ a[i]][k][z ^ 1] + a[i])
                        c[j][k][z] = (c[j][k][z] + c[j ^ a[i]][k][z ^ 1]) % B;
                    if (d[j][k][z] < d[j ^ a[i]][k][z ^ 1] + a[i] && c[j ^ a[i]][k][z ^ 1])
                        d[j][k][z] = d[j ^ a[i]][k][z ^ 1] + a[i],
                        c[j][k][z] = c[j ^ a[i]][k][z ^ 1];

                    if (d[j][k][z] == d[j][k ^ a[i]][z ^ 1] + a[i])
                        c[j][k][z] = (c[j][k][z] + c[j][k ^ a[i]][z ^ 1]) % B;
                    if (d[j][k][z] < d[j][k ^ a[i]][z ^ 1] + a[i] && c[j][k ^ a[i]][z ^ 1])
                        d[j][k][z] = d[j][k ^ a[i]][z ^ 1] + a[i],
                        c[j][k][z] = c[j][k ^ a[i]][z ^ 1];
                }
        }
        int z = (len - 1) % 2;
//        forn(j, 0, mx)
//            forn(k, 0, mx)
//                cerr << j << " " << k << ": " << d[j][k][z] << " " << c[j][k][z] << "\n";
        int a = -1, b = 1;
        for1(i, mx, 0) {
            if (c[i][i][z] == 0) continue;
            //cerr << l << " - " << i << "\n";
            if (a == d[i][i][z])
                b = (b + c[i][i][z]) % B;
            if (a < d[i][i][z])
                a = d[i][i][z],
                b = c[i][i][z];
        }
        cout << a << " " << b << "\n";
    }

    return 0;
}

