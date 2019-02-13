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
    forn(i, 1, n)
        cin >> a[i];
    for1(i, n, 1)
        a[i] -= a[i - 1];
    vi ans;
    forn(k, 1, n) {
        bool ok = 1;
        forn(i, k + 1, n)
            ok &= (a[i] == a[i - k]);
        if (ok) ans.pb(k);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}

