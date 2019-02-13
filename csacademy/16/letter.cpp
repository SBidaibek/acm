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

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int sz, cnt[N], to[N][26], d[N];

int f(char c) {
    cout << char(c + 'a') << endl;
    int ans;
    cin >> ans;
    return ans;
}

int dfs(int x) {
    vi v;
    forn(i, 0, 25)
        if (to[x][i])
            v.pb(dfs(to[x][i]));
    sort(v.begin(), v.end());
    for1(i, v.size() - 1, 0)
        d[x] = max(d[x], (int)v.size() - i + v[i]);
    return d[x];
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black

    int n, k;
    cin >> n >> k;
    forn(i, 1, n) {
        string s;
        cin >> s;
        int x = 0;
        for (auto c : s) {
            if (to[x][c -= 'a'] == 0) to[x][c] = ++sz;
            x = to[x][c];
            ++cnt[x];
        }
    }
    dfs(0);
    int x = 0;
    forn(it, 1, k) {
        vector <pii> v;
        forn(i, 0, 25)
            if (to[x][i])
                v.pb({d[to[x][i]], i});
        sort(v.begin(), v.end(), greater <pii> ());
        for (auto y : v)
            if (f(y.S)) {
                x = to[x][y.S];
                break;
            }
    }

    return 0;
}
