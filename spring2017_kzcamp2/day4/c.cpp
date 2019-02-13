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
typedef vector <int> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

//vector <vi> G;
int gsz;
vi G[N];

void add(int x1, int y1, int x2, int y2) {
    //G.pb();
    //G.pb();
    G[++gsz] = {x1, y1, y2, +1};
    G[++gsz] = {x2 + 1, y1, y2, -1};
}

int n, m, sz;
int a[N], ans[N];
vi q[N];
int f[N];

int g(int x) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) ans += f[x];
    return ans;
}

void u(int x, int d) {
    for (; x <= sz; x |= x + 1) f[x] += d;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    scanf("%d", &tests);
    while (tests--) {
        //G.clear();
        gsz = 0;
        scanf("%d %d", &n, &m);
        forn(i, 1, n)
            scanf("%d", &a[i]);
        vi v;
        forn(i, 1, m) {
            q[i].resize(3);
            scanf("%d%d", &q[i][1], &q[i][0]);
            q[i][2] = i;
            v.pb(q[i][1]);
            ans[i] = 0;
        }
        forn(l, 1, n) {
            int z = 0, o = 0;
            if (l & 1)
                add(0, 1, 0, a[l]);
            else
                add(1, 0, a[l], 0);
            forn(r, l + 1, n) {
                if (l & 1) {
                    if (r & 1)
                        add(z, o + 2, z, o + a[l] + a[r]);
                    else
                        add(z + 1, o + 1, z + a[r], o + a[l]);
                }
                else {
                    if (r & 1)
                        add(z + 1, o + 1, z + a[l], o + a[r]);
                    else
                        add(z + 2, o, z + a[l] + a[r], o);
                }
                if (r & 1) o += a[r];
                else z += a[r];
            }
        }
        forn(i, 1, gsz)
            forn(j, 1, 2)
                v.pb(G[i][j]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        forn(i, 1, m)
            forn(j, 1, 1)
                q[i][j] = lower_bound(v.begin(), v.end(), q[i][j]) - v.begin() + 1;
        forn(i, 1, gsz)
            forn(j, 1, 2)
                G[i][j] = lower_bound(v.begin(), v.end(), G[i][j]) - v.begin() + 1;
        //sort(G.begin(), G.end());
        sort(G + 1, G + 1 + gsz);
        sort(q + 1, q + 1 + m);
        int ptr = 1;
        sz = v.size();
        forn(i, 1, sz) f[i] = 0;
        //for (auto &w : G) {
        forn(i, 1, gsz) {
            auto &w = G[i];
            for (; ptr <= m && q[ptr][0] < w[0]; ++ptr)
                ans[q[ptr][2]] = g(q[ptr][1]) > 0;
            u(w[1], w[3]);
            u(w[2] + 1, -w[3]);
        }
        forn(i, 1, m)
            cout << ans[i];
        cout << "\n";
    }

    return 0;
}
