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

    int n;
    cin >> n;
    vi a(n + 1);
    int mx = 0;
    forn(i, 1, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int l = mx, r = 11111;
    while (l < r) {
        int m = (l + r) / 2;
        int s = 0;
        forn(i, 1, n)
            s += m - a[i];
        bool ok = (s * 2 > m * n);
        if (ok) r = m;
        else l = m + 1;
    }
    cout << l << "\n";

    return 0;
}

