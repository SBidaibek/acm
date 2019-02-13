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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, l, r, m;
int fst[N], lst[N], nfst[N], nlst[N];
int d[N][N], ans[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r >> m;
    forn(i, 1, n)
        fst[i] = n + 1, lst[i] = 0;
    forn(i, 1, m) {
        int a, b;
        cin >> a >> b;
        fst[b] = min(fst[b], a);
        lst[b] = max(lst[b], a);
        ans[a] = b;
    }
    fst[1] = 1;
    vi v;
    forn(i, 1, n) {
        if (fst[i] == n + 1) continue;
        v.pb(i);
        forn(j, fst[i], lst[i]) ans[j] = i;
    }
    forn(i, 1, v.size() - 1)
        forn(j, v[i - 1] + 1, v[i])
            nlst[j] = lst[v[i - 1]];
    forn(j, v.back(), n)
        nfst[j] = n + 1;
    for1(i, v.size() - 2, 0)
        forn(j, v[i], v[i + 1] - 1)
            nfst[j] = fst[v[i + 1]];

    forn(j, 1, n + 1)
        d[n + 1][j] = 1;
    for1(i, n, 1) {
        forn(j, 1, n) {
            if (ans[i] != 0) {
                if (ans[i] != j || i > fst[j]) continue;
            }
            for1(k, min(r, nfst[j] - i), max(l, lst[j] - i + 1))
                if (d[i + k][j + 1]) {
                    d[i][j] = k;
                    break;
                }
        }
    }
    assert(d[1][1]);
    int x = 1, p = 1;
    for (; p <= n; p += d[p][x], ++x)
        forn(i, p, p + d[p][x] - 1)
            ans[i] = x;
    cout << ans[n] << "\n";
    forn(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}
