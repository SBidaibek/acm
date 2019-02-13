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

const int N = 6e3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

int n, h, s[N], a[N];
ll d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    int mx = 0;
    forn(i, 1, n) {
        cin >> s[i];
        mx = max(mx, s[i]);
    }
    ll ans = 0;
    forn(i, 1, n) {
        int l = 0, r = mx;
        if (i > 1)
            l = max(l, a[i - 1] - h), r = min(r, a[i - 1] + h);
        if (i < n)
            l = max(l, s[i + 1] - h), r = min(r, s[i - 1] + h);
        if (l < r) {
            if (s[i] > r) ans += s[i] - r, a[i] = r;
            else
            if (s[i] < l) ans += l - s[i], a[i] = l;
            else
            a[i] = s[i];
        }
        else {
            if (s[i + 1] + h < a[i - 1] - h)
                ans += abs(s[i] - (a[i - 1] - h)), a[i] = a[i - 1] - h;
            else
                ans += abs(s[i] - (a[i - 1] + h)), a[i] = a[i - 1] + h;
        }
    }
    cout << ans << "\n";

    return 0;
}

