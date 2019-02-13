#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi v, ans(n);
    forn(i, 0, n - 1) {
        auto c = s[i];
        if (c == '(') v.pb(i);
        else {
            if (k > 0) {
                k -= 2;
                ans[v.back()] = 1, ans[i] = 1;
                v.pop_back();
            }
        }
    }
    forn(i, 0, n - 1)
        if (ans[i]) cout << s[i];

    return 0;
}
