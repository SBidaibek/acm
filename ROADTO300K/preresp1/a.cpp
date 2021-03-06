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

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = n;
    int cur = k, l = 0, r = 0;
    forn(i, 0, n - 1) {
        cur += (s[i] == 'L' ? -1 : +1);
        if (s[i] == 'L') ++l; else ++r;
        cerr << i << ": " << s[i] << " " << cur << "\n";
        if (k - 1 <= i + 1 && (cur - 1) >= r * 2)
            ans = min(ans, cur / 2);
        if (n - k <= i + 1 && (n - cur) >= l * 2)
            ans = min(ans, (n - cur + 1) / 2);
    }
    cout << max(0, ans) << "\n";

    return 0;
}
