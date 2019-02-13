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

const int N = 3e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

int n, a[N], p[N];
int t[N * 31], to[N * 31][2], sz = 1;

void add(int x, int lvl, int v) {
    ++t[x];
    if (lvl == -1) return;
    int b = bit(v, lvl);
    if (to[x][b] == 0) to[x][b] = ++sz;
    add(to[x][b], lvl - 1, v);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n) {
        cin >> p[i];
        add(1, 29, p[i]);
    }
    forn(i, 1, n) {
        int x = 1;
        ll ans = 0;
        for1(lvl, 29, 0) {
            assert(t[x]);
            --t[x];
            int b = bit(a[i], lvl);
            if (to[x][b] == 0 || t[to[x][b]] == 0) b ^= 1;
            ans |= (b << lvl);
            x = to[x][b];
        }
        --t[x];
        cout << (a[i] ^ ans) << " ";
    }
    cout << "\n";

    return 0;
}
