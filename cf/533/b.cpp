#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

int a;

int myget(int x, int y) {
    cout << x << " " << y << endl;
    return x % a >= y % a ? 1 : 0;
}

int get(int x, int y) {
    cout << "? "  << x << " " << y << endl;
    char c;
    cin >> c;
    return c == 'x';
}

int solve() {
    int x = 1;
    while (get(x, x * 2) == 0) x *= 2;
    int l = 0, r = x;
    while (l < r) {
        //cerr << l << " " << r << "\n";
        int m = (l + r + 1) / 2;
        if (get(2 * x, m)) l = m;
        else r = m - 1;
        //cerr << l << " " << r << "\n";
    }
    int m = 2 * x  - l;
    return m;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    for (;;) {
        string s;
        cin >> s;
        if (s == "end") break;
        int ans = solve();
        cout << "! " << ans << endl;
    }

    return 0;
}
