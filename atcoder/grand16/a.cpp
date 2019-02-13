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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int ans = str.size() - 1;
    forn(i, 'a', 'z') {
        string s = str;
        int cnt = 0;
        for (auto c : s)
            if (c == char(i)) ++cnt;
        if (cnt == 0) continue;
        int cur = 0;
        for (;; ++cur) {
            cnt = 0;
            for (auto c : s)
                if (c == i) ++cnt;
            if (cnt == s.size()) break;
            string t = s;
            t.pop_back();
            forn(j, 0, t.size() - 1)
                if (s[j] == i || s[j + 1] == i) t[j] = i;
            s = t;
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";

    return 0;
}
