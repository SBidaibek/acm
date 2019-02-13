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

ll pwr(ll a, ll b, ll p) {
    ll res = 1;
    for (; b; a = a * a % p, b >>= 1)
        if (b & 1) res = res * a % p;
    return res;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int u, v, p;
    cin >> u >> v >> p;
    vi ans;
    while (u > 1) {
    cerr << u << ": " << pwr(u, p - 2, p) << "\n";
        if (pwr(u, p - 2, p) >= u) {
            ans.pb(2);
            --u;
            continue;
        }
        u = pwr(u, p - 2, p);
        ans.pb(3);
    }
    vi sna;
    while (v > 1) {
        if (pwr(v, p - 2, p) >= v) {
            sna.pb(1);
            --v;
            continue;
        }
        v = pwr(v, p - 2, p);
        sna.pb(3);
    }
    for (; sna.size(); sna.pop_back())
        ans.pb(sna.back());
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
    /*unordered_map <int, int> d;
    d[u] = 0;
    queue <int> q;
    q.push(u);
    while (q.size()) {
        int x = q.front();
    }*/

    return 0;
}
