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

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int L = 21;

int n, a[N], cnt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    ll ans = 0;
    forn(l, 1, n) {
        int b = 0;
        forn(r, l, n) {
            cnt[a[r]] += 1;
            if (cnt[a[r]] % 2 == 0) ++b;
            else if (cnt[a[r]] > 1) --b;
            if (!b) ++ans;
        }
        forn(r, l, n)
            cnt[a[r]] = 0;
    }
    cout << ans << "\n";

    return 0;
}
