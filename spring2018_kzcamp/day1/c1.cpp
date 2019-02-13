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
typedef vector <ll> vi;

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, q;
ll ans[N];
int col[N];
vector <vi> v[N];
int nxt[N], prv[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    forn(i, 2, q + 1) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        v[x1].pb({y1, y2, i});
        v[x2].pb({y1, y2, -i});
        col[i] = k;
    }
    v[0].pb({0, m, 1});
    v[n].pb({0, m, 1});
    col[1] = 1;

    set <pii> st;
    int lstx = 0;
    forn(i, 0, n) {
        if (!v[i].size()) continue;
        int lsty = 0;
        set <int> sty;
        int sz = 0, t = 0;
        for (auto p : st) {
            if (p.F != lsty) {
                ll d = 1ll * (p.F - lsty) * (i - lstx);
                ans[col[*--sty.end()]] += d;
            }
            lsty = p.F;
            if (p.S < 0) sty.erase(-p.S);
            else {
                if (sz == 0) {
                    t = p.S;
                    nxt[p.S] = q + 2;
                    prv[p.S] = 0;
                }
                else {

                }
                sty.insert(p.S);
            }
        }
        lstx = i;
        for (auto p : v[i]) {
            if (p[2] > 0) {
                st.insert({p[0], p[2]});
                st.insert({p[1], -p[2]});
            }
            else {
                st.erase({p[0], -p[2]});
                st.erase({p[1], p[2]});
            }
        }
    }

    forn(i, 1, 1e5)
        if (ans[i])
            cout << i << " " << ans[i] << "\n";

    return 0;
}
