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

const int N = 3e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

char ans[N];
int p[N];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 0, 2e6)
        p[i] = i, ans[i] = 'a';
    int mx = 0;
    forn(i, 1, n) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        forn(j, 1, k) {
            int x;
            cin >> x;
            --x;
            while (f(x) < x + s.size()) {
                ans[f(x)] = s[f(x) - x];
                p[f(x)] = f(x) + 1;
            }
            mx = max(mx, x + (int)s.size());
        }
    }
    forn(i, 0, mx - 1) putchar(ans[i]);

    return 0;
}
