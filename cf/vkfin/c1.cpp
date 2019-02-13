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

const int N = 1e5 + 3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int c2i(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
}

int n, a[N];
int f[N][11][10][4];

void dec(int x, int b, int m, int v) {
    for (; x <= n; x |= x + 1) --f[x][b][m][v];
}

void inc(int x, int b, int m, int v) {
    for (; x <= n; x |= x + 1) ++f[x][b][m][v];
}

int g(int x, int b, int m, int v) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1)
        ans += f[x][b][m][v];
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    n = s.size();
    forn(i, 1, n)
        a[i] = c2i(s[i - 1]);
    forn(b, 1, 10)
        forn(i, 1, n)
            inc(i, b, i % b, a[i]);

    int q;
    cin >> q;
    forn(it, 1, q) {
        int t, l, r;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> l >> c;
            c = c2i(c);
            forn(b, 1, 10) {
                dec(l, b, l % b, a[l]);
                inc(l, b, l % b, c);
            }
            a[l] = c;
        }
        else {
            string t;
            cin >> l >> r >> t;
            int ans = 0, b = t.size();
            forn(i, 0, t.size() - 1) {
                int c = c2i(t[i]);
                ans += g(r, b, (l + i) % b, c) - g(l - 1, b, (l + i) % b, c);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
