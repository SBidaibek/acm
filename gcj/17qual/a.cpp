#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 500 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(_, 1, tests) {
        cout << "Case #" << _ << ": ";
        string s;
        int k, ans = 0;
        cin >> s >> k;
        for1(i, s.size() - 1, k - 1)
            if (s[i] == '-') {
                ++ans;
                forn(j, i - k + 1, i)
                    s[j] = (s[j] == '+' ? '-' : '+');
            }
        bool shit = 0;
        for1(i, k - 2, 0)
            if (s[i] == '-') shit = 1;
        if (!shit)
            cout << ans << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
