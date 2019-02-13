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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >>t;
    forn(_, 1, t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = 1;
        forn(i, 0, n / 2 - 1)
            if (abs(s[i] - s[n - 1 - i]) > 2 || abs(s[i] - s[n - 1 - i]) == 1) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
