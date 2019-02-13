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

int n;
pii a[N];
int prv[N], lvl[N], p[N];
int f[N], t[N];

int fs(int x) {
    return p[x] == x ? x : p[x] = fs(p[x]);
}

ostream & operator << (ostream &out, pii p) {
    out << p.x << " " << p.y;
    return out;
}

pii b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;
    forn(i, 1, n) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    sort(a + 1, a + 1 + n, [](pii q, pii p) {return q.y < p.y;});
    map <int, int> r, q;
    forn(i, 1, n) cerr << i << ": " << a[i].x << " " << a[i].y << "\n";
    forn(i, 1, n) {
        p[i] = i;
        while (r.size()) {
            auto it = r.upper_bound(a[i].x);
            if (it == r.end()) break;
            prv[it -> S] = i;
            assert(p[it -> S] == it -> S);
            if (a[i] == pii(8, 12)) cerr << a[it -> S] << "\n";
            p[it -> S] = i;
            r.erase(it);
        }
        r[a[i].x] = i;
        q[a[i].x] = i;
        auto it = q.lower_bound(a[i].x);
        if (it == q.begin()) {
            f[i] = t[i] = -1;
            continue;
        }
        --it;
        f[i] = it -> S, t[i] = fs(it -> S);
        forn(z, 1, n) {
            if (b[z] != a[i]) continue;
            int fst = -1, lst = -1;
            int mx = -1;
            int kek = 0;
            for1(j, z - 1, 1)
                if (mx < b[j].y && b[j].y <= b[z].y) {
                    if (mx == -1) fst = j;
                    mx = b[j].y;
                    lst = j;
                    ++kek;
                }
            cerr << a[i] << ": " << a[t[i]] << " " << a[f[i]] << " | " << b[lst] << " " << b[fst] << " [" << kek << "\n";
        }
    }
    for1(i, n, 1)
        if (prv[i] != i) lvl[i] = lvl[prv[i]] + 1;
    ll ans = 0;
    forn(i, 1, n)
        if (f[i] != -1) ans += lvl[f[i]] - lvl[t[i]] + 1;
    cout << ans << "\n";

    return 0;
}
