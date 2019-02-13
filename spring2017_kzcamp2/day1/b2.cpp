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
typedef vector <int> vi;

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m, Q;
int a[N];
int tp[N], r[N], c[N], p[N];
pii mt[N];

int id(int i, int j) {
    return (i - 1) * m + j;
}

const int K = 350;
vi layers;
int l2c[N];
int spr[N][K];
set <int, int> sav[N][K], st[N];
int par[N], rnk[N];

int di[] = {+1, 0, -1, 0};
int dj[] = {0, +1, 0, -1};

void rebuild(int l, int r) {
    forn(i, 0, layers.size() - 1)
        sav[i].clear();
    layers.clear();
    forn(i, l, r)
        if (tp[i] == 2)
            layers.pb(p[i]);
    sort(layers.begin(), layers.end());
    layers.resize(unique(layers.begin(), layers.end() - layers.begin());
    forn(i, 0, layers.size() - 1)
        l2c[layers[i]] = i;
    int ptr = 0;
    forn(i, 1, n * m) par[i] = 0, rnk[i] = 0;
    mt[n * m + 1].F = 2e9;
    forn(i, 1, n * m + 1) {
        if (mt[i].F != mt[i - 1].F || i > n * m) {
            for (; ptr < layers.size() && layers[ptr] < mt[i].F; ++ptr) {
                forn(j, 1, n) {
                    spr[j][ptr] = par[j];
                    if (par[j] == j)
                        sav[j][ptr] = st[ptr];
                }
            }
            if (ptr == layers.size() || i > n * m) break;
        }
        int id = mt[i].S;
        par[id] = id, rnk[id] = 1, st[id].insert(id);
        int x = (id - 1) / m + 1, y = (id - 1) % m + 1;
        forn(dir, 0, 3) {
            if ()
        }
    }
}

void com(vi &press) {
    sort(press.begin(), press.end());
    press.resize(unique(press.begin(), press.end()) - press.begin());
    for (auto &v : mt)
        v.F = lower_bound(press.begin(), press.end(), v.F) - press.begin();
    forn(i, 1, Q)
        if (tp[i] == 2)
            p[i] = lower_bound(press.begin(), press.end(), p[i]) - press.begin();
}

ll solve() {
    vi press;
    forn(i, 1, n)
        forn(j, 1, m) {
            int l;
            cin >> l;
            mt[id(i, j)] = {l, id(i, j)};
            press.pb(l);
            L[id(i, j)] = l;
        }
    sort(mt + 1, mt + 1 + n * m);
    forn(i, 1, n * m)
        cin >> a[id(i, j)];
    forn(i, 1, Q) {
        cin >> tp[i] >> r[i] >> c[i] >> p[i];
        if (tp[i] == 2) press.pb(p[i]);
    }
    com(press);

    int k = sqrt(Q);//300
    int ptr = k;
    rebuild(1, ptr);
    forn(i, 1, Q) {
        if (tp[i] == 1) {

        }
        if (tp[i] == 2) {
            if (L[id(r[i], c[i])] > p[i]) continue;
        }
        if (i == ptr) {
            forn(j, i - k + 1, i)
                a[r[j]][c[j]] = p[j];
            rebuild(i - k + 1, i);
        }
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> Q;
    cout << solve() << "\n";

    return 0;
}
