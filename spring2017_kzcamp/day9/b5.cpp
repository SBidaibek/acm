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

vi slow_slow(vector <PII> q) {
    int ans = (1 << n) - 1;
    forn(mask, 1, (1 << n) - 1) {
        if (__builtin_popcount(mask) != k) continue;
        bool shit = 0;
        for (auto p : q) {
            int x = 0;
            forn(i, p.F, p.S)
                x |= (bit(mask, i - 1));
            if (!x) {shit = 1; break;}
        }
        if (!shit) ans &= mask;
    }
    vi v;
    forn(i, 1, n)
        if (bit(ans, i - 1)) v.pb(i);
    if (!v.size()) v.pb(-1);
    return v;
}

int Gp(vector <PII> &q, int x) {
    int ans = 0, lst = 0;
    for (auto p : q) {
        if (p.S > x) break;
        if (p.F <= lst) continue;
        ++ans, lst = p.S;
    }
    return ans;
}

int Gs(vector <PII> &q, int x) {
    int ans = 0, lst = n + 1;
    for (auto p : q) {
        if (p.F < x) break;
        if (p.S >= lst) continue;
        ++ans, lst = p.F;
    }
    return ans;
}

int Gb(vector <PII> &q, int x) {
    int ans = 0, lst = 0;
    for (auto p : q) {
        if (p.F <= lst) continue;
        if (p.S == x) {
            if (p.F == p.S) return k + 1;
            ++ans, lst = p.S - 1;
        }
        else
            ++ans, lst = p.S;
    }
    return ans;
}

ostream & operator << (ostream &out, PII p) {
    out << "(" << p.F << " " << p.S << ")";
    return out;
}

vi slow(vector <PII> q) {
    vector <PII> l = q, r = q;
    sort(l.begin(), l.end(), [](PII a, PII b) {
        return PII(a.S, a.F) < PII(b.S, b.F);
    });
    sort(r.begin(), r.end(), [](PII a, PII b) {
        return a > b;
    });
    //for (auto x : l) cerr << x << " ";cerr << "\n";
    //for (auto x : r) cerr << x << " ";cerr << "\n";
    vi v;
    forn(i, 1, n)
        if (Gp(l, i - 1) + Gs(r, i + 1) == k - 1 && Gb(l, i) > k)
            v.pb(i);
    if (!v.size()) v.pb(-1);
    return v;
}

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
    sort(q.begin(), q.end());
    vi v = slow(q);
    for (auto &x : v)
        cout << (x > 0 ? val[x - 1] : x) << "\n";
    return 0;

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
    forn(i, 1, n)
        if (a[i]) cout << val[i - 1] << "\n", shit = 0;
    if (shit) cout << "-1\n";

    return 0;
}
