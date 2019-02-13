#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    forn(it, 1, t) {
        string s;
        cin >> s;
        p[0] = 0;
        forn(i, 1, s.size() - 1) {
            int j = p[i - 1];
            while (j && s[i] != s[j]) j = p[j - 1];
            p[i] = j + (s[i] == s[j]);
        }
        int ans = 0, j = p[s.size() - 1];
        for (; j; j = p[j]) {
            cerr << j << "\n";
            if (j * 2 <= s.size()) {
                if (ans == 0 && j * 2 < s.size()) ++ans;
                ans += 2;
            }
        }
        ans += (s[0] == s.back());
        cout << ans << "\n";
    }


    return 0;
}
