#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 6e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vi g[N];

bool pr(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return 0;
    return 1;
}

const int P = 1.5e7 + 10;
int e[P];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //while (!pr(p)) --p;
//    cerr << p << "\n";
//    return 0;

    vi pr;
    forn(i, 2, P - 1) {
        if (!e[i]) {
            e[i] = i;
            pr.pb(i);
        }
        for (auto p : pr) {
            if (p > e[i] || 1ll * i * p >= P) break;
            e[i * p] = p;
        }
    }

    int n;
    //n = 3e5;
    cin >> n;
    unordered_map <int, int> d2i;
    int sz = 0;
    forn(j, 1, n) {
        int x;
        cin >> x;
        //int x = 14999981;
        while (x > 1) {
            int c = 0, i = e[x];
            while (e[x] == i) x /= i, ++c;
            if (!d2i[i]) d2i[i] = ++sz;
            g[d2i[i]].pb(c);
        }
    }

    int ans = n;
    forn(i, 1, sz) {
        if (g[i].size() == n) {
            int mn = g[i][0];
            for (auto x : g[i]) mn = min(mn, x);
            int cur = 0;
            for (auto x : g[i]) if (x == mn) ++cur;
            ans = min(ans, cur);
        }
        else
            ans = min(ans, n - (int)g[i].size());
    }
    cout << (ans == n ? -1 : ans) << "\n";

    return 0;
}

