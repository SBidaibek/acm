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

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vi g[N];
int q[N];
set <int> s[N];

void mrg(set <int> &a, set <int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto x : b)
        a.insert(x);
    //b.clear();
}

ll ans;

void dfs(int x) {
    s[x].insert(x - 1);
    for (auto to : g[x]) {
        dfs(to);
        mrg(s[x], s[to]);
    }
    forn(i, 1, q[x]) {
        if (!(int)s[x].size()) break;
        ans += *--s[x].end();
        s[x].erase(--s[x].end());
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(it, 1, tests) {
        cout << "Case #" << it << ": ";
        int m, a, b;
        cin >> n >> m >> a >> b;
        forn(i, 2, n) {
            int p;
            cin >> p;
            ++p;
            //cerr << p << " " << i << "\n";
            g[p].pb(i);
        }
        //cerr << "-\n";
        forn(i, 0, m - 1) {
            int c = (1ll * a * i + b) % n + 1;
            ++q[c];
        }
        ans = 0;
        dfs(1);
        cout << ans << "\n";
        forn(i, 1, n) {
            g[i].clear();
            q[i] = 0;
            s[i].clear();
        }
    }

    return 0;
}
