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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pii f;
    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'F')
                f = {i, j};
        }

    int sl = 0, su = 0;
    if (a[1][2] == '.') {
        cout << "L" << endl;
        int x, y;
        cin >> x >> y;
        if (x == 1 && y == 1) sl = 0;
        else sl = 1;
        if (sl) cout << "R" << endl;
        cin >> x >> y;
    }
    if (n > 1) {
        int x = 1, y = 1;
        while (a[x][y + 1] == '.') {
            cout << (sl ? "L" : "R") << endl;
            cin >> x >> y;
        }
        cout << "U" << endl;
        cin >> x >> y;
        if (x == 1) su = 0;
        else su = 1;
        if (su) cout << "D" << endl;
        cin >> x >> y;

        if (a[1][2] != '.') {
            cout << "L" << endl;
            int x, y;
            cin >> x >> y;
            if (y == 1) sl = 0;
            else sl = 1;
            if (sl) cout << "R" << endl;
            cin >> x >> y;
        }
    }

    dfs(1);


    return 0;
}
