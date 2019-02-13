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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
vector <int> g[N];
int a[N][N];
pii d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
        a[f][t] = 1, a[t][f] = 1;
    }

    forn(len, 1, n) {
        forn(l, 1, n) {
            int r = (l - 1 + len - 1) % n + 1;
            if ((d[l][r - 1].F || d[l + 1][r].F) && a[l][r]) d[l][r] = {l, r};
            forn(i, l + 1, r - 1) {
                if (d[])
            }
        }
    }

    return 0;
}
