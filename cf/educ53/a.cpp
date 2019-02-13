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
    string s;
    cin >> s;
    ll ans = 0;
    forn(l, 0, s.size() - 1) {
        vi c(256);
        int mx = 0;
        forn(r, l, s.size() - 1) {
            mx = max(mx, ++c[s[r]]);
            if (mx * 2 <= r - l + 1) {
                cout << "YES\n" << s.substr(l, r - l + 1) << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}

