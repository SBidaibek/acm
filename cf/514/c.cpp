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

vi solve(int n) {
    vi ans;
    if (n <= 3) {
        forn(i, 1, n - 1) ans.pb(1);
        ans.pb(n);
        return ans;
    }
    forn(i, 1, (n + 1) / 2)
        ans.pb(1);
    vi add = solve(n - (n + 1) / 2);
    for (auto x : add)
        ans.pb(x * 2);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi ans = solve(n);
    for (auto x : ans) cout << x << " ";

    return 0;
}

