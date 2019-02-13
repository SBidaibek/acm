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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int st[N];
vi g[N];

bool match(vector <pii> &v) {
    int mxx = 0, mxy = 0;
    for (auto p : v) {
        g[p.x].pb(p.y);
        mxy = max(mxy, p.y);
        mxx = max(mxx, p.x);
    }
    forn(i, 1, mxy) st[i] = 0;
    forn(x, 1, mxx) {
        if (g[x].size() % 2 == 0) continue;
        bool shit = 1;
        for (auto y : g[x]) {
            if (st[y] != 0) {
                shit = 0;
                int p = st[y];
                for (auto py : g[p])
                    st[py] = 0;
                break;
            }
        }
        if (shit)
            for (auto y : g[x])
                st[y] = x;
    }
    forn(x, 1, mxx)
        g[x].clear();
    forn(i, 1, mxy)
        if (st[i]) return 0;
    return 1;
}

int n, m;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n * 2 + 1) {
        cin >> a[i].x >> a[i].y;
        assert(a[i].y > 0);
        assert(a[i].x > 0);
    }
    forn(i, 1, m) {
        vector <pii> v;
        int x;
        cin >> x;
        forn(j, 1, n * 2 + 1)
            if (j != x)
                v.pb(a[j]);
        if (match(v)) {
            cout << "1\n";
            continue;
        }
        for (auto &p : v)
            swap(p.x, p.y);
        if (match(v)) {
            cout << "1\n";
            continue;
        }
        cout << "0\n";
    }

    return 0;
}
