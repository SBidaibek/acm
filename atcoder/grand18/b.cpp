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

int n, m;
int a[N][N], c[N], d[N];

bool check(int x) {
    forn(i, 1, m) c[i] = 0, d[i] = 0;
    while (1) {
        bool new_it = 0;
        forn(i, 1, n) {
            int j = 1;
            while (j <= m && d[a[i][j]]) ++j;
            if (++c[a[i][j]] > x) {
                d[a[i][j]] = 1;
                forn(k, 1, m) c[k] = 0;
                new_it = 1;
                break;
            }
            if (j > m) return 0;
        }
        if (!new_it) break;
    }
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (!check(m)) l = m + 1;
        else r = m;
    }
    cout << l << "\n";

    return 0;
}
