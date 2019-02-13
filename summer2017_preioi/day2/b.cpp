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

const int N = (1 << 25);
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

const int K = 1e5;
int n, k;
char c;
ll p, a[K];
short used[N], timer;
bool d[N];

bool bit(int mask, int x) {
    return mask & (1 << x);
}

void dfs(int x) {
    used[x] = timer;
    d[x] = 0;
    if (__builtin_popcount(x) == n - k) {
        ll ans = 0;
        forn(i, 0, n - 1)
            if (bit(x, i))
                ans = (ans + a[i + 1]) % p;
        d[x] = ((ans == 0) ^ (k % 2) ^ (c == 'Y'));
        return;
    }
    forn(i, 0, n - 1)
        if (bit(x, i)) {
            int to = x ^ (1 << i);
            if (used[to] != timer) dfs(to);
            if (d[to] == 0) {
                d[x] = 1;
                break;
            }
        }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(_, 1, T) {
        ++timer;
        cin >> n >> k >> p >> c;
        forn(i, 1, n)
            cin >> a[i];
        dfs((1 << n) - 1);
        if (!d[(1 << n) - 1]) c = (c == 'X' ? 'Y' : 'X');
        putchar(c);
    }

    return 0;
}
