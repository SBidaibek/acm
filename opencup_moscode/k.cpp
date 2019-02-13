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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, k, v[N], a[N];
ll pwr[N];
int cur, ie[N];
int to[N][10];

void dfs(int q, ll x, int pos, int t) {
    if (!q) return;
    //cerr << cur << ": " << q << " " << x << " " << pos << " " << t << "\n";
    if (pos == 11) {
        cout << cur << " " << ie[q] << "\n";
        exit(0);
    }
    int d = x % 10 + t;
    if (d >= v[pos])
        dfs(to[q][d - v[pos]], x / 10, pos + 1, 0);
    if (d + 10 - v[pos] <= 9)
        dfs(to[q][d + 10 - v[pos]], x / 10, pos + 1, 1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pwr[0] = 1;
    forn(i, 1, 10)
        pwr[i] = pwr[i - 1] * 10;

    cin >> n >> k;
    forn(i, 0, 10) {
        v[i] = k % 10;
        k /= 10;
    }
    int sz = 1;
    forn(i, 1, n) {
        cin >> a[i];
        cur = i;
        dfs(1, a[i], 0, 0);
        int x = 1;
        ll y = a[i];
        forn(j, 0, 10) {
            if (to[x][a[i] % 10] == 0) to[x][a[i] % 10] = ++sz;
            x = to[x][a[i] % 10];
            a[i] /= 10;
        }
        a[i] = y;
        ie[x] = i;
    }
    forn(i, 1, sz) {
        forn(j, 0, 9) to[i][j] = 0;
        ie[i] = 0;
    }
    sz = 1;
    for1(i, n, 1) {
        cur = i;
        dfs(1, a[i], 0, 0);
        int x = 1;
        forn(j, 0, 10) {
            if (to[x][a[i] % 10] == 0) to[x][a[i] % 10] = ++sz;
            x = to[x][a[i] % 10];
            a[i] /= 10;
        }
        ie[x] = i;
    }
    cout << "-1 -1\n";

    return 0;
}
