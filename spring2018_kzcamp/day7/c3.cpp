#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 200;
const int L = 8;

int n;
pii a[N];
int ih[N];
int prv[N][L], pb[N], lb[N], mb[N];
int u[N], val[N];

ostream & operator << (ostream &out, pii p) {
    out << p.x << " " << p.y;
    return out;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    map <pii, int> p2i;
    sort(a + 1, a + 1 + n);
    forn(i, 1, n) p2i[a[i]] = i;
    sort(a + 1, a + 1 + n, [](pii q, pii p) {return q.y < p.y;});
    map <int, int> r, q;
    forn(i, 1, n)
        ih[i] = (i % K == 1 ? i : ih[i - 1]);

    ll ans = 0;
    forn(i, 1, n) {
        int id = p2i[a[i]];
        u[id] = 1;
        val[id] = a[i].y;
        forn(l, 0, L - 1) prv[id][l] = id;
        pb[id] = id, lb[id] = 1;
        forn(j, id + 1, n) {
            if (ih[j] == j) break;
            if (u[j]) {
                prv[j][0] = max(prv[j][0], id);
                if (prv[j][0] == j) prv[j][0] = id;
                forn(l, 1, L - 1)
                    prv[j][l] = prv[prv[j][l - 1]][l - 1];
                pb[j] = id, lb[j] = lb[prv[j][0]] + 1;
            }
        }
        forn(j, id + 1, n) {
            if (ih[j] != j) continue;
            mb[j] = max(mb[j], id);
            j += K - 1;
        }
        ///forn(j, id + 1, n)
        ///    if (u[j]) prv[j] = max(prv[j], id);

        q[a[i].x] = id;
        auto it = q.lower_bound(a[i].x);
        if (it == q.begin()) continue;
        --it;
        int mx = -1;
//        forn(i, 1, n) cerr << prv[i][0] << " ";cerr << "\n";
//        forn(i, 1, n) cerr << pb[i] << " ";cerr << "\n";
//        forn(i, 1, n) cerr << lb[i] << " ";cerr << "\n";
//        cerr << "-\n";
        for (int j = it -> S; j;) {
            assert(u[j]);
            for1(l, L - 1, 0)
                if (val[prv[j][l]] < mx) j = prv[j][l];
            if (val[j] < mx) j = prv[j][0];
            if (val[j] > mx) {
                ans += lb[j];
                j = pb[j];
                mx = max(mx, val[j]);
            }
            j = mb[ih[j]];
        }
    }
    cout << ans << "\n";

    return 0;
}
