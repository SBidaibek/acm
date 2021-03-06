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

int l[N], r[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n)
        cin >> l[i] >> r[i];
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    int ans = n;
    forn(i, 1, n)
        ans += max(l[i], r[i]);
    cout << ans << "\n";

    return 0;
}

