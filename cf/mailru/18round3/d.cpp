#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vi g[N];
vi st;

int dfs(int x, int p = -1) {
    int sz = (g[x].size() - (p != -1)) == 0;
    for (auto to : g[x])
        if (to != p)
            sz += dfs(to, x);
    st.pb(sz);
    return sz;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 2, n) {
        int p;
        cin >> p;
        g[i].pb(p);
        g[p].pb(i);
    }
    dfs(1);
    sort(st.begin(), st.end());
    for (auto x : st)
        cout << x << " ";

    return 0;
}

