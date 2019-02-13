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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, a[N];
ll p[N], s[N], sum[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n) {
        p[i] = p[i - 1];
        if (a[i] > 0) p[i] += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for1(i, n, 1) {
        s[i] = s[i + 1];
        if (a[i] > 0) s[i] += a[i];
        //cerr << i << ": " << s[i] << "\n";
    }
    ll ans = 0;
    forn(i, 0, n - k) {
        //cerr << i << ": " << p[i] + sum[i + k] - sum[i] +  s[i + k + 1] << "\n";
        ans = max(ans, p[i] + s[i + k + 1]);
        ans = max(ans, p[i] + sum[i + k] - sum[i] + s[i + k + 1]);
    }
    cout << ans << "\n";

    return 0;
}

