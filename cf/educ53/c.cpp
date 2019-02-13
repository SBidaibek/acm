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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, sx[N], sy[N];
int tx, ty;

bool ok(int mlen) {
    forn(i, 1, n - mlen + 1) {
        int cx = sx[n] - sx[i + mlen - 1] + sx[i - 1];
        int cy = sy[n] - sy[i + mlen - 1] + sy[i - 1];
        int d = abs(cx - tx) + abs(cy - ty);
        if (d <= mlen && mlen % 2 == d % 2) return 1;
    }
    return 0;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    cin >> s;
    forn(i, 1, n) {
        sx[i] = sx[i - 1] + (s[i - 1] == 'R' ? +1 : 0) + (s[i - 1] == 'L' ? -1 : 0);
        sy[i] = sy[i - 1] + (s[i - 1] == 'D' ? -1 : 0) + (s[i - 1] == 'U' ? +1 : 0);
    }
    cin >> tx >> ty;

    int l = 0, r = n / 2;
    while (l < r) {
        int m = (l + r) / 2;
        int mlen = m * 2;
        if (ok(mlen)) r = m;
        else l = m + 1;
    }
    l *= 2;
    int ans = n + 1;
    if (ok(n / 2 * 2)) ans = min(ans, l);

    l = 0, r = n / 2;
    while (l < r) {
        int m = (l + r) / 2;
        int mlen = m * 2 + 1;
        if (ok(mlen)) r = m;
        else l = m + 1;
    }
    l = l * 2 + 1;
    if (ok(n % 2 == 0 ? n - 1 : n)) ans = min(ans, l);

    if (ans > n) ans = -1;
    cout << ans << "\n";

    return 0;
}

