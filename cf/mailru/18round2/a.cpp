#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int p[N];

int fp(int x) {
    return p[x] == x ? x : p[x] = fp(p[x]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, q, l;
    cin >> n >> q >> l;
    vi a(n + 1);
    forn(i, 1, n)
        cin >> a[i];
    int ans = 0;
    forn(i, 1, n)
        if (a[i] > l)
            p[i] = i, ++ans;
    forn(i, 1, n - 1)
        if (p[i] && p[i + 1])
            p[fp(i)] = fp(p[i + 1]), --ans;

    forn(i, 1, q) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << "\n";
            continue;
        }
        int x, d;
        cin >> x >> d;
        a[x] += d;
        if (a[x] > l && a[x] - d <= l) {
            p[x] = x;
            ++ans;
            if (p[x + 1])
                p[fp(x)] = fp(x + 1), --ans;
            if (p[x - 1])
                p[fp(x - 1)] = fp(x), --ans;
        }
    }

    return 0;
}

