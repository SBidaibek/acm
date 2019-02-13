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

int n, c, k;
int a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> k;
    forn(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    forn(i, 1, n) {
        ++ans;
        int j = i;
        while (j <= i + c - 1 && j <= n && a[j] <= a[i] + k) ++j;
        i = j - 1;
    }
    cout << ans << "\n";

    return 0;
}
