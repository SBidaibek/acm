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

int n;
ll a[N], t[3][N];

void recalc(int x) {
    forn(i, 0, 2)
        t[i][x] = t[i][x * 2] + t[i][x * 2 + 1];
}

void upd(int i, int d) {
    a[i] = d;
    t[0][i + n - 1] = a[i];
    t[1][i + n - 1] = a[i] * i;
    t[2][i + n - 1] = a[i] * i * i;
    for (i = (i + n - 1) / 2; i; i >>= 1)
        recalc(i);
}

ll get(int l, int r, int i) {
    ll ans = 0;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans += t[i][l++];
        if (r % 2 == 0) ans += t[i][r--];
    }
    return ans;
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
        t[0][i + n - 1] = a[i];
        t[1][i + n - 1] = a[i] * i;
        t[2][i + n - 1] = a[i] * i * i;
    }
    for1(i, n - 1, 1)
        recalc(i);

    int q;
    cin >> q;
    forn(it, 1, q) {
        int i, x, y;
        cin >> i >> x;
        if (i >= 0) {
            cin >> y;
            if (i == 0)
                cout << get(x, y, 0) << "\n";
            if (i == 1)
                cout << get(x, y, 1) - (x - 1) * get(x, y, 0) << "\n";
            if (i == 2)
                cout << get(x, y, 2) - 2 * (x - 1) * get(x, y, 1) + get(x, y, 0) * (x - 1) * (x - 1) << "\n";
        }
        else
            upd(-i, x);
    }

    return 0;
}


