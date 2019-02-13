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
typedef vector <ll> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 998244353;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n + 2), r(n + 1);
    forn(i, 1, n / 2)
        cin >> a[i * 2];
    r[n + 1] = 1e18;
    bool ok = 1;
    for1(i, n, 2) {
        int d = 1;
        for (; d * d < a[i]; ++d) {
            bool shit = 0;
            if (a[i] % d != 0 || a[i] / d % 2 != d % 2) shit = 1;
            if (i < n && (a[i] / d + d) / 2 >= r[i + 1]) shit = 1;
            if (!shit) break;
        }
        if (d * d >= a[i]) {
            ok = 0;
            break;
        }
        ll sub = d, sum = a[i] / d;
        r[i] = (sum + sub) / 2;
        r[i - 1] = r[i] - sub;
        if (i < n && r[i] >= r[i + 1]) {
            ok = 0;
            break;
        }
        --i;
    }
    if (!ok) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    forn(i, 1, n)
        cout << r[i] * r[i] - r[i - 1] * r[i - 1] << " ";
    cout << "\n";

    return 0;
}
