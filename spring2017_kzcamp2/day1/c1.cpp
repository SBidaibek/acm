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

const int N = 5e4 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

string s[N];
ll f[N];

ll solve(int i, int l, int r) {
    if (l == r) return 1;
    ll ans = 1, c = 1;
    while (l <= r && s[l].size() <= i) ++l, ++c;
    int p = l;
    forn(j, l + 1, r) {
        if (s[j][i] == s[j - 1][i]) continue;
        ans = ans * solve(i + 1, p, j - 1) % B;
        ++c, p = j;
    }
    ans = ans * solve(i + 1, p, r) % B;
    return ans * f[c] % B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    forn(i, 1, N - 1)
        f[i] = f[i - 1] * i % B;

    int n;
    cin >> n;
    forn(i, 1, n)
        cin >> s[i];
    sort(s + 1, s + 1 + n);
    cout << solve(0, 1, n) << "\n";

    return 0;
}
