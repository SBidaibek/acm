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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

const int L = 20;
int n, lvl[N], pos[N], tout[N];
vi g[N];
int lg[N], sz;
pii t[L][N];

void dfs(int x, int p = -1) {
    t[0][++sz] = {lvl[x], x};
    pos[x] = sz;
    for (int to : g[x]) {
        if (to == p) continue;
        lvl[to] = lvl[x] + 1;
        dfs(to, x);
        t[0][++sz] = {lvl[x], x};
    }
    tout[x] = sz;
    return;
}

bool isa(int a, int b) {
    return pos[a] <= pos[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    a = pos[a], b = pos[b];
    if (a > b) swap(a, b);
    int d = b - a + 1;
    return min(t[lg[d]][a], t[lg[d]][b - (1 << lg[d]) + 1]).S;
}

int cnt[N], u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n - 1) {
        int f, t;
        cin >> f >> t;
        g[f].pb(t);
        g[t].pb(f);
    }
    lvl[1] = 1;
    dfs(1);
    forn(i, 2, sz)
        lg[i] = lg[i / 2] + 1;
    forn(i, 1, lg[sz])
        forn(j, 1, sz - (1 << i) + 1)
            t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);

    int q;
    cin >> q;
    forn(it, 1, q) {
        int k;
        cin >> k;
        vi v;
        forn(j, 1, k) {
            int x;
            cin >> x;
            v.pb(x);
            cnt[x] = 1;
            u[x] = it;
        }
        sort(v.begin(), v.end(), [](int a, int b) {
            return pos[a] < pos[b];
        });
        forn(i, 0, k - 2) {
            int l = lca(v[i], v[i + 1]);
            v.pb(l);
            if (u[l] != it)
                cnt[l] = 0;
        }
        sort(v.begin(), v.end(), [](int a, int b) {
            return pos[a] < pos[b];
        });
        v.resize(unique(v.begin(), v.end()) - v.begin());
        vi st, ans(k + 1);
        for (auto x : v) {
            for (; st.size() && !isa(st.back(), x); st.pop_back()) {
                assert(st.size() > 1);
                int p = st[st.size() - 2];
                cnt[p] += cnt[st.back()];
                ans[cnt[st.back()]] += (lvl[st.back()] - lvl[p]);
            }
            st.pb(x);
        }
        for (; st.size() > 1; st.pop_back()) {
            int p = st[st.size() - 2];
            cnt[p] += cnt[st.back()];
            ans[cnt[st.back()]] += (lvl[st.back()] - lvl[p]);
        }
        ans[cnt[st.back()]] += lvl[st.back()];
        int sum = 0;
        forn(i, 1, k) sum += ans[i];
        ans[0] = n - sum;
        forn(i, 0, k)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
