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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int d[N][N];
int u[N * N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int timer = 0;
    int n = 100;
    forn(i, 1, n) {
        forn(j, 1, n) {
            ++timer;
            forn(k, 1, i / 2)
                u[d[i - 2 * k][j + k]] = timer;
            forn(k, 1, j / 2)
                u[d[i + k][j - 2 * k]] = timer;
            forn(k, 0, i * j)
                if (u[k] != timer) {
                    d[i][j] = k;
                    break;
                }
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
