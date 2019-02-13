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
typedef vector <ll> vi;

const int N = 1e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int sqr(int x) {
    return x * x;
}

int d(pii p1, pii p2) {
    return sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
}

bool issqr(int x) {
    return int(sqrt(x)) == sqrt(x);
}

int f(int x) {
    int ans = 0;
    forn(i, 0, 600 - 1)
        if (i < 600 && issqr(x * x - i * i)) ++ans;
    return ans;
}

int n, d1, d2;
int a[N][N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int mx = 0;
    forn(i, 1, 2e5)
        mx = max(mx, f(i));
    cout << mx << "\n";
        //cerr << i << ": " << f(i) << "\n";
//    cin >> n >> d1;
//    forn(i, 0, 2 * n - 1) {
//        forn(j, 0, 2 * n - 1) {
//            forn(x, 0, 2 * n - 1) {
//                forn(y, 0, 2 * n - 1) {
//                    if (d({i, j}, {x, y}) == d1)
//                        ++a[i][j];
//                }
//            }
//            cout << a[i][j] << " \n"[j == 2 * n - 1];
//        }
//    }

    return 0;
}
