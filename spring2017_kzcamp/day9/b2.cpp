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
    vector <PII> q;
    forn(i, 1, m) {
        int l, r, tp;
        cin >> l >> r >> tp;
        if (tp == 0)
            ++b[l], --b[r + 1];
        else
            q.pb({l, r});
    }
    vi val;
    forn(i, 1, n)
        if ((b[i] += b[i - 1]) == 0)
            val.pb(i);
    for (auto &p : q) {
        p.F = lower_bound(val.begin(), val.end(), p.F) - val.begin() + 1;
        p.S = upper_bound(val.begin(), val.end(), p.S) - val.begin();
    }
    if (k == val.size()) {
        forn(i, 1, n)
            if (!b[i])
                cout << i << "\n";
        return 0;
    }

    n = val.size();
    vi a(n + 1);
    sort(q.begin(), q.end());
    int cl = -1, cr = -1;
    vi o;
    for (auto p : q) {
        if (p.F <= cr) {
            cl = max(cl, p.F);
            cr = min(cr, p.S);
            if (p.F == p.S) {
                a[p.F] = 1, --k;
                cr = -1;
            }
        }
        else {
            if (cr != -1 && cl == cr && !a[cl])
                o.pb(cl);
            cl = p.F, cr = p.S;
            if (p.F == p.S) {
                a[p.F] = 1, --k;
                cr = -1;
            }
        }
    }
    if (cr != -1 && cl == cr && !a[cl])
        o.pb(cl);
    if (o.size() == k)
        for (auto i : o)
            a[i] = 1;
    bool shit = 1;
    forn(i, 1, n)
        if (a[i]) cout << val[i - 1] << "\n", shit = 0;
    if (shit) cout << "-1\n";

    return 0;
}
