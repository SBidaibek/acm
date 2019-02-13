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

const int N = 3e5 + 1;
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
    vi a(n + n + 1);
    map <int, int> cnt;
    forn(i, 1, n * 2) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a.begin() + 1, a.end());
    ll ans = (a[n] - a[1]) * (a[n * 2] - a[n + 1]);
    forn(i, n + 1, n + n - 1)
        ans = min(ans, (a[i] - a[i - n + 1]) * (a[n + n] - a[1]));
    for (auto x : cnt)
        if (x.S >= n) ans = 0;
    cout << ans << "\n";

    return 0;
}
