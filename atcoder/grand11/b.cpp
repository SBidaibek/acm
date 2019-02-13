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

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
ll a[N], p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    forn(i, 1, n)
        p[i] = p[i - 1] + a[i];
    int ans = 1;
    for1(i, n - 1, 1) {
        if (p[i] * 2 < a[i + 1]) break;
        ++ans;
    }
    cout << ans << "\n";
    return 0;

    forn(i, 1, n) {
        bool shit = 0;
        for (int ptr = i; ptr < n;) {
            if (p[ptr] * 2 < a[ptr + 1]) {
                shit = 1;
                break;
            }
            int l = ptr + 1, r = n;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (p[ptr] * 2 >= p[m] - p[ptr]) l = m;
                else r = m - 1;
            }
            ptr = l + 1;
        }
        if (!shit) ++ans;
    }
    cout << ans << "\n";

    return 0;
}
