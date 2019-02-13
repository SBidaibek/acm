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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll f(string s) {
    ll x = 0;
    for (int i = 0, k = 1; i < s.size(); ++i) {
        if (s[i] == 'C') k *= 2;
        else x += k;
    }
    return x;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;
    forn(_t, 1, ts) {
        cout << "Case #" << _t << ": ";
        int d;
        cin >> d;
        string s;
        cin >> s;
        int ans = 0;
        int k = 0;
        for (auto c : s) if (c == 'S') ++k;
        if (k > d) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (; f(s) > d; ++ans) {
            while (s.back() == 'C') s.pop_back();
            for1(i, s.size() - 1, 1) {
                if (s[i] == 'S' && s[i - 1] == 'C') {
                    swap(s[i], s[i - 1]);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
