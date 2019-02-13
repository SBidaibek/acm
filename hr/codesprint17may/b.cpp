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

int n, a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    int k, m, b;
    cin >> s >> k >> b >> m;
    int x = 0, pb = 1;
    forn(i, 1, k) pb = pb * b % m;
    forn(i, 0, k - 1)
        x = (x * b + (s[i] - '0')) % m;
    int ans = x;
    forn(i, k, s.size() - 1) {
        x = (x * b % m + (s[i] - '0') - (s[i - k] - '0') * pb % m + m) % m;
        ans += x;
    }
    cout << ans << "\n";

    return 0;
}
