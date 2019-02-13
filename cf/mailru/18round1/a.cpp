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

const int N = 4e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int x, y, z, t1, t2, t3;
    cin >> y >> x >> z >> t1 >> t2 >> t3;
    int a = abs(x - y) * t1;
    int b = t3 * 2 + abs(z - y) * t2 + abs(x - y) * t2 + t3;
    if (b <= a) cout << "YES\n";
    else cout << "NO\n";

    //cerr << a << " " << b << "\n";

    return 0;
}

