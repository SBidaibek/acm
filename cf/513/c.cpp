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

const int N = 4e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int a[N], b[N];
int ml[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m;
    forn(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    forn(i, 1, m) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    cin >> x;

    forn(l, 1, m)
        forn(r, l, m)
            ml[b[r] - b[l - 1]] = max(ml[b[r] - b[l - 1]], r - l + 1);
    forn(i, 1, N - 1)
        ml[i] = max(ml[i], ml[i - 1]);

    int ans = 0;
    forn(len, 1, n) {
        int mn = INF;
        forn(i, len, n)
            mn = min(mn, a[i] - a[i - len]);
        ans = max(ans, len * ml[min(N - 1, x / mn)]);
    }
    cout << ans << "\n";

    return 0;
}

