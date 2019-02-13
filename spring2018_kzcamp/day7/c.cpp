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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    forn(i, 1, n) {
        int mx = -1;
        for1(j, i - 1, 1)
            if (mx < a[j].y && a[j].y <= a[i].y)
                mx = a[j].y, ++ans;
        cerr << a[i].x << " " << a[i].y << " | " << ans<< "\n";
    }
    cout << ans << "\n";

    return 0;
}
