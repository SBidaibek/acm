
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

const int N = 2e5 + 2;
const int K = (1 << 26);
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool bit(int mask, int i) {
    return mask & (1 << i);
}

int n, a[N];
int mba;
bool d[K];

const int L = 26;
int ans, cur;

void dfs(short i, int x, short c) {
    if (i == -1) {
        if (!d[x] && c < cur) {
            ans = x, cur = c;
        }
        return;
    }
    if (d[x + (1 << (i + 1)) - 1] == 1 || c >= cur)
        return;
    forn(j, 0, (1 << i) - 1)
        d[x + j] |= d[x + (1 << i) + j];
    if (d[x + (1 << i) - 1] == 0)
        dfs(i - 1, x, c);
    if (c + 1 < cur)
        dfs(i - 1, x | (1 << i), c + 1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        if (a[i] == (1 << L)) {
            //assert(0);
            mba = 1;
            continue;
        }
        a[i] ^= (1 << L) - 1;
        d[a[i]] = 1;
    }
/*
    forn(i, 0, L - 1) {
        for (int m = 0; m < (1 << L);) {
            m += (1 << i);
            forn(j, 1, (1 << i)) {
                d[m - (1 << i)] |= d[m];
                ++m;
            }
        }
    }*/

    ans = (1 << L) - 1;
    cur = L;
    dfs(L - 1, 0, 0);
    if (mba) ans ^= (1 << L);

    cout << ans << "\n";

    return 0;
}
