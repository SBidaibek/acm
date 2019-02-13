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
const int K = (1 << 20) + 10;
const int B = 1e9 + 7;

int n;
vi g[N];
int a[N], p[N];
ll d[K][50];
int fam[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 2, n) {
        cin >> p[i];
        g[p[i]].pb(i);
        g[i].pb(p[i]);
        fam[p[i]] |= (1 << (i - 1));
    }
    forn(i, 1, n)
        cin >> a[i];
    ll INF = 1ll * n * (n - 1) / 2;

    queue <pii> q;
    forn(mask, 0, (1 << n) - 1)
        forn(i, 0, n) d[mask][i] = INF;
    d[1][0] = 0;
    q.push({1, 0});
    ll ans = INF;
    while (q.size()) {
        int mask, ons;
        tie(mask, ons) = q.front();
        q.pop();
        if (mask == 0) {
            ans = min(ans, d[mask][ons]);
            continue;
        }
        forn(i, 1, n) {
            if ((mask & (1 << (i - 1))) == 0) continue;
            int to = mask ^ (1 << (i - 1)) ^ fam[i];
            if (!a[i]) {
                if (d[to][ons] == INF) q.push({to, ons});
                d[to][ons] = min(d[to][ons], d[mask][ons] + ons);
            }
            else {
                if (d[to][ons + 1] == INF) q.push({to, ons + 1});
                d[to][ons + 1] = min(d[to][ons + 1], d[mask][ons]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
