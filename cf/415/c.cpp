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

int a[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 1, 100) {
        forn(j, 1, 100) {
            vi u(201);
            forn(k, 1, i - 1)
                u[a[k][j]] = 1;
            forn(k, 1, j - 1)
                u[a[i][k]] = 1;
            forn(k, 1, 200)
                if (!u[k]) {
                    a[i][j] = k;
                    break;
                }
            printf("%02d ", a[i][j]);//cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    forn(i, 1, 100) {
        //forn(j, 0, i - 1)
            //cout << a[i - j][j + 1] << " ";
        //cout << "\n";
    }

    return 0;
}
