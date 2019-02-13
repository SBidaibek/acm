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
typedef vector <ll> vi;

const int N = 2e6 + 10;
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
    int ans = 0, cur = 0;
    vi a(n + 1);
    forn(i, 1, n) {
        cin >> a[i];
        if (a[i] != a[i - 1] + 1) cur = 0;
        if (a[i] == i) cur = i;
        ans = max(ans, ++cur);
        if (1000 - a[i] == n - i)
            ans = max(ans, cur + n - i + 1);
    }
    cout << max(0, ans - 2) << "\n";

    return 0;
}

