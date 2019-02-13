#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int pat[N], cnt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int cur = 52;
    string s;
    cin >> s;
    for (auto c : s) {
        if (pat[c] == 0) --cur;
        ++pat[c];
    }
    cin >> s;
    int ans = 0;
    forn(i, 0, k - 1) {
        cur -= (cnt[s[i]] == pat[s[i]]);
        ++cnt[s[i]];
        cur += (cnt[s[i]] == pat[s[i]]);
        if (i >= n - 1) {
            if (cur == 52) ++ans;
            cur -= (cnt[s[i - n + 1]] == pat[s[i - n + 1]]);
            --cnt[s[i - n + 1]];
            cur += (cnt[s[i - n + 1]] == pat[s[i - n + 1]]);
        }
    }
    cout << ans << "\n";

    return 0;
}
