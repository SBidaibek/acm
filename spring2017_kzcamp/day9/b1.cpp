#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, k, m;
int b[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    vector <PII> v;
    forn(i, 1, m) {
        int l, r, tp;
        cin >> l >> r >> tp;
        if (tp == 0)
            forn(j, l, r)
                b[j] = 1;
        else
            v.pb({l, r});
    }
    vi a(n + 1);
    sort(v.begin(), v.end());
    int cl = -1, cr = -1;
    vi o;
    for (auto  p : v) {
        /*int c = 0, x = 0;
        forn(i, p.F, p.S)
            if (!b[i]) ++c, x = i;
        if (c == 1) {
            a[x] = 1;
            --k;
            continue;
        }*/
        if (p.F <= cr) {
            cl = max(cl, p.F);
            cr = min(cr, p.S);
        }
        else {
            if (cr != -1) {
                c = 0, x = 0;
                forn(i, cl, cr) {
                    if (!b[i]) ++c, x = i;
                    if (a[i]) c = 2;
                }
                if (c == 1) o.pb(x);
            }
            cl = p.F, cr = p.S;
        }
    }
    if (cr != -1) {
        int c = 0, x = 0;
        forn(i, cl, cr) {
            if (!b[i]) ++c, x = i;
            if (a[i]) c = 2;
        }
        if (c == 1) o.pb(x);
    }
    int c = 0;
    forn(i, 1, n)
        if (!b[i] && !a[i]) ++c;
    if (c == k)
        forn(i, 1, n)
            if (!b[i]) a[i] = 1;
    if (o.size() == k)
        for (auto i : o)
            a[i] = 1;
    bool shit = 1;
    forn(i, 1, n)
        if (a[i]) cout << i << "\n", shit = 0;
    if (shit) cout << "-1\n";

    return 0;
}
