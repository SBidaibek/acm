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

bool bit(int a, int b) {
    return a & (1 << b);
}

vi slow (vector <PII> q) {
    int ans = (1 << n) - 1;
    int c = 0;
    forn(mask, 1, (1 << n) - 1) {
        if (__builtin_popcount(mask) != k) continue;
        bool shit = 0;
        for (auto p : q) {
            int x = 0;
            forn(i, p.F, p.S)
                x |= (bit(mask, i - 1));
            if (!x) {shit = 1; break;}
        }
        if (!shit) {++c; ans &= mask;}
    }
    if (c == 0) return {-2};
    vi v;
    forn(i, 1, n)
        if (bit(ans, i - 1)) v.pb(i);
    if (!v.size()) v.pb(-1);
    return v;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n >> k >> m;
    forn(test, 3, 100) {
    srand(test);
    cerr << "T: " << test << "\n";
    n = 6;
    k = rand() % n + 1;
    m = rand() % 8 + 1;
    vector <PII> q;
    cerr << n << " " << k << " " << m << "\n";
    forn(i, 1, m) {
        int l, r, tp;
        //cin >> l >> r >> tp;
        l = rand() % n + 1;
        r = (rand() % (n - l + 1)) + l;
        cerr << l << " " << r << " 1\n";
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
        cerr << "Invalid\n";
        continue;
        //forn(i, 1, n)
        //    if (!b[i])
        //        cout << i << "\n";
        //return 0;
    }
    n = val.size();
    sort(q.begin(), q.end());
    vi S = slow(q);
    if (S[0] == -2) {
        cerr << "Invalid\n";
        continue;
    }
    vi a(n + 1);
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
    vi my;
    forn(i, 1, n)
        if (a[i]) my.pb(val[i - 1]), shit = 0;
    if (shit) my.pb(-1);
    cerr << "my:\n";
    for (auto x : my) cerr << x << " ";cerr << "\n";
    cerr << "S:\n";
    for (auto x : S) cerr << x << " ";cerr << "\n";
    assert(my == S);
    }

    return 0;
}
