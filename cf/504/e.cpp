#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
int cnt;

bool get(int r1, int c1, int r2, int c2) {
    assert(++cnt <= 4 * (n - 1));
    assert(r2 - r1 + c2 - c1 >= n - 1);
    string ans;
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    cin >> ans;
    return ans[0] == 'Y';
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    string s1, s2;

    int x = 1, y = 1;
    forn(i, 1, n - 1) {
        if (get(x, y + 1, n, n)) {
            s1.pb('R');
            ++y;
        }
        else {
            s1.pb('D');
            ++x;
        }
    }
    int sx = x, sy = y;

    x = n, y = n;
    forn(i, 1,  n - 1) {
        if (get(1, 1, x - 1, y)) {
            s2.pb('D');
            --x;
        }
        else {
            s2.pb('R');
            --y;
        }
    }
    assert(x == sx && y == sy);
    reverse(s2.begin(), s2.end());

    s1 = s1 + s2;
    cout << "! ";
    for (auto x : s1)
        cout << x;

    return 0;
}
