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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m, q;
ll ans[N];
int col[N];

int stck[N], sz;
int u[N], timer;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    forn(i, 1, q) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        v[x1].pb({y1, y2, i});
        v[x2].pb({y1, y2, -i});
        col[i] = k;
    }

    set <pii> st;
    int lstx = 0;
    ans[1] = 1ll * n * m;
    forn(i, 0, n - 1) {
        if (!v[i].size()) continue;
        sz = 0;
        st[0] = 1;
        ++timer;
        int lsty = 0, lstk = 1;
        for (auto p : st) {
            if (p.F != lsty) {
                if (lstk != 1) {
                    ll d = 1ll * (p.F - lsty) * (i - lstx);
                    ans[lstk] += d;
                    ans[1] -= d;
                }
            }
            lsty = p.F;
            if (p.S < 0)
                u[-p.S] = timer;
            else {

            }
            while (sz && u[st[sz]] == timer) --sz;
            lstk = st[sz];
        }
        lstx = i;
        for (auto p : v[i]) {
            if (p[2] > 0) {
                st.insert({p[0], p[2]});
                st.insert({p[1], p[2]});
            }
            else {
                st.erase({p[0], -p[2]});
                st.erase({p[1], -p[2]});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
