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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, s, q;
int a[N], b[N];

int solve() {
    int cur = s, ptr = 1;
    forn(i, 1, n) {
        for (; ptr <= m && cur - b[ptr] >= 0; ++ptr) cur -= b[ptr];
        if (cur + a[i] > s * 2) return 0;
        cur += a[i];
    }
    for (; ptr <= m && cur - b[ptr] >= 0; ++ptr) cur -= b[ptr];
    return ptr > m;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, m)
        cin >> b[i];

    int q;
    cin >> q;
    forn(i, 1, q) {
        char c;
        int v, u;
        cin >> c >> v >> u;
        if (c == 'B')
            swap(a[v], a[u]);
        else
            swap(b[v], b[u]);
        cout << solve() << "\n";
    }

    return 0;
}
