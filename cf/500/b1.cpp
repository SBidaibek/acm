#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, m, q;
pii a[N];
int p[N];
vi vx[N], vy[N];

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    forn(i, 1, q) {
        cin >> a[i].x >> a[i].y;
        vx[a[i].x].pb(i);
        vy[a[i].y].pb(i);
    }

    int ans = 0;
    forn(i, 1, n) p[i] = i;
    forn(y, 1, m) {
        if (!vy[y].size()) {
            ++ans;
            continue;
        }
        int c = 0;
        for (auto i : vy[y])
            if (c == 0) c = f(a[i].x);
            else p[f(a[i].x)] = c;
    }
    set <int> st;
    forn(i, 1, n)
        st.insert(f(i));
    ans += st.size() - 1;

    cout << ans << "\n";

    return 0;
}
