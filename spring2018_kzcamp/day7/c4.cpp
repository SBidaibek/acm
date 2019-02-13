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
const int K = 300;
const int L = 8;

int n;
pii a[N];
int ih[N];
int prv[N], pb[N], lb[N], mb[N];
int u[N], val[N], zb[N];

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
    set <int> r, q;
    forn(i, 1, n) {
        ih[i] = (i % K == 1 ? i : ih[i - 1]);
        mb[i] = -1;
        val[i] = -1;
    }
    ll ans = 0;
    forn(i, 1, n) {
        int id = p2i[a[i]];
        u[id] = 1;
        val[id] = a[i].y;
        prv[id] = id;
        pb[id] = id;
        lb[id] = 1;
        forn(j, ih[id], id - 1)
            if (u[j]) zb[pb[j]] = max(zb[pb[j]], mb[ih[j]]);
        mb[ih[id]] = -1;
        forn(j, id + 1, n) {
            if (ih[j] == j) break;
            if (u[j]) {
                prv[j] = max(prv[j], id);
                if (prv[j] == j) prv[j] = id;
                pb[j] = id, lb[j] = lb[prv[j]] + 1;
            }
        }
        forn(j, ih[id] + K, n) {
            mb[j] = max(mb[j], id);
            j += K - 1;
        }

        forn(j, id + 1, n)
            prv[j] = max(prv[j], id);

        q.insert(id);
        auto it = q.lower_bound(id);
        if (it == q.begin()) continue;
        --it;
        int mx = -1;
        for (int j = *it; j;) {
            assert(val[j] > mx);
            mx = val[pb[j]];
            ans += lb[j];
            j = pb[j];
            if (mb[ih[j]] > -1)
                zb[j] = mb[ih[j]];
            j = zb[j];
        }
    }
    cout << ans << "\n";

    return 0;
}
