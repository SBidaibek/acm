#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 1e4 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, l, q;
int a[N], sav[N];
int ans[101][N];
int k[101], z[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    forn(i, 1, n)
        cin >> a[i];
    cin >> q;
    forn(i, 1, q)
        cin >> k[i];

    vi o(q);
    forn(i, 0, q - 1) o[i] = i + 1;
    sort(o.begin(), o.end(), [](int x, int y) {
        return k[x] < k[y];
    });
    forn(i, 1, q)
        z[k[i]] = i;
    for1(i, n, 0)
        z[i] = (z[i] == 0 ? z[i + 1] : z[i]);
    forn(d, 1, n - l) {
        int c = 0;
        forn(i, 1, n - d) {
            c += (a[i] != a[i + d]);
            if (i > l) c -= (a[i - l] !=  a[i - l + d]);
            if (i >= l) ++ans[z[c]][i - l + 1], ++ans[z[c]][i + d - l + 1];
        }
    }
    forn(j, 1, o.size() - 1)
        forn(i, 1, n - l + 1)
            ans[o[j]][i] += ans[o[j - 1]][i];
    forn(i, 1, q)
        forn(j, 1, q)
            if (k[i] == k[j])
                forn(e, 1, n)
                    ans[i][e] = max(ans[i][e], ans[j][e]), ans[j][e] = max(ans[i][e], ans[j][e]);
    forn(j, 1, q) {
        forn(i, 1, n - l + 1) {
            cout << ans[j][i] << " \n"[i == n - l + 1];
        }
    }

    return 0;
}
