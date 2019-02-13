#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 998244353;

int p[N], sp[N];
set <int> st[N];

void rel(vi &ans, int x, int d) {
    for (auto y : st[x])
        ans[y] = d;
    st[x].clear();
}

int fp(int x) {
    return x == p[x] ? x : p[x] = fp(p[x]);
}

void unite(int a, int b) {
    if (fp(a) == fp(b)) return;
    if (st[fp(a)].size() > st[fp(b)].size())
        swap(st[fp(a)], st[fp(b)]);
    for (auto x : st[fp(a)])
        st[fp(b)].insert(x);
    st[fp(a)].clear();
    sp[fp(b)] += sp[fp(a)];
    p[fp(a)] = fp(b);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vi spv(k + 1);
    forn(i, 1, k) {
        cin >> spv[i];
        sp[spv[i]] = 1;
    }
    vector <vi> e;
    vi v;
    forn(i, 1, m) {
        int f, t, w;
        cin >> f >> t >> w;
        e.pb({w, f, t});
    }
    forn(i, 1, n)
        p[i] = i, st[i].insert(i);
    sort(e.begin(), e.end());
    vi ans(n + 1, e.back()[0]);
    for (auto E : e) {
        int f = E[1], t = E[2], w = E[0];
        unite(f, t);
        if (sp[fp(f)] == k)
            rel(ans, fp(f), w);
        //    ans[f] = min(ans[f], w);
        //    ans[t] = min(ans[t], w);
        //}
    }
    forn(i, 1, k)
        cout << ans[spv[i]] << " ";
    cout << "\n";

    return 0;
}
