#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

char a[N][N];
int b[N][N];

void mark(int i, int j) {
    forn(x, 0, 2)
        forn(y, 0, 2)
            if (!(x == 1 && y == 1) && a[i + x][j + y] != '#') return;
    forn(x, 0, 2)
        forn(y, 0, 2)
            if (!(x == 1 && y == 1))
                b[i + x][j + y] = 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m) cin >> a[i][j];
    forn(i, 1, n - 2)
        forn(j, 1, m - 2)
            mark(i, j);
    forn(i, 1, n)
        forn(j, 1, m)
            if (a[i][j] == '#' && !b[i][j])
                {cout << "NO\n"; return 0;}
    cout << "YES\n";

    return 0;
}

