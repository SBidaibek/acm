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
int sp[N], ss[N];

int Gp(vector <PII> &q) {
    int ans = 0, lst = 0;
    for (auto p : q) {
        if (p.F <= lst) continue;
        forn(i, lst, p.S - 1)
            sp[i] = ans;
        ++ans, lst = p.S;
    }
    forn(i, lst, n) sp[i] = ans;
    return ans;
}

int Gs(vector <PII> &q) {
    int ans = 0, lst = n + 1;
    for (auto p : q) {
        if (p.S >= lst) continue;
        forn(i, p.F + 1, lst)
            ss[i] = ans;
        ++ans, lst = p.F;
    }
    forn(i, 1, lst) ss[i] = ans;
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
    Gp(l);
    Gs(r);
    vi v;
    vi shit(n + 1), kl(n + 1), kr(n + 1);
    for (auto p : q) {
        kl[p.F] = 1;
        kr[p.S] = 1;
        if (p.F == p.S)
            shit[p.F] = 1, v.pb(p.F);
    }
    forn(i, 1, n)
        if (!shit[i] && (kl[i] || kr[i]) && sp[i - 1] + ss[i + 1] == k - 1 && sp[i] + ss[i] > k)
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

    return 0;
}
