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

vi g[N];
int n, m;
const int K = 100;
int d[N];
vector <pii> p[N];
ll c[N];
int tomask[N][K];

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

void rec(int mask, vi path) {
    if (mask == (1 << n) - 1) {
        for1(i, path.size() - 1, 0)
            cerr << path[i] << " ";
        cerr << "| " << check(path) << "\n";
        cerr << "\n-\n";
        return;
    }
    for (auto pr : p[mask]) {
        path.pb(pr.S);
        rec(pr.F, path);
        path.pop_back();
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //forn(n, 2, 19) {
    //    m = n;
//        cerr << "n = " << n << ": ";
//        forn(i, 1, n) g[i].clear();
        //cin >> n >> m;
        cin >> n;
        m = n - 1;
        forn(i, 1, m) {
            int f, t;
        //    cin >> f >> t;
            f = (i + 1) / 2, t = i + 1;
            g[f].pb(t);
            g[t].pb(f);
        }
         //   g[i].pb(i == n ? 1 : i + 1);
        //    g[i == n ? 1 : i + 1].pb(i);


        forn(mask, 0, (1 << n) - 1) {
            forn(j, 1, n) {
                int newmask = 0;
                forn(k, 1, n) {
                    if (bit(mask, k - 1) == 0) continue;
                    for (auto to : g[k])
                        if (to != j) newmask |= (1 << (to - 1));
                }
                tomask[mask][j] = newmask;
            }
        }

        forn(mask, 0, N - 1)
            d[mask] = -1, p[mask].clear();
        d[(1 << n) - 1] = 0;
        c[(1 << n) - 1] = 1;
        queue <int> q;
        q.push((1 << n) - 1);

        while (q.size()) {
            int mask = q.front();
            q.pop();
            forn(i, 1, n) {
                int to = tomask[mask][i];
//                if (to == 0 && d[mask] == 13) {
//                    bitset <10> b(mask);
//                    cerr << b << "\n";
//                }
                if (d[to] != -1) {
                    if (d[to] == d[mask] + 1) {
                        c[to] += c[mask];
                        p[to].pb({mask, i});
                    }
                    continue;
                }
                d[to] = d[mask] + 1;
                p[to].pb({mask, i});
                c[to] = c[mask];
                q.push(to);
            }
        }

        /*int cnt = 0;
        forn(mask, 0, (1 << n) - 1) {
            forn(i, 1, n)
                if (tomask[mask][i] == 0 && d[mask] == d[0] - 1) {
                    bitset <15> b(mask);
                    cerr << b << "\n";
                    ++cnt;
                }
        }*/
        cerr << d[0] << " length\n";
        cerr << c[0] << " solutions\n";
        if (d[0] == -1) return 0;
        rec(0, vi (0));

       /* vector <pii> ans;
        for (int mask = 0; mask < (1 << n) - 1; mask = p[mask].F) {
            bitset <10> b(mask);
            ans.pb({p[mask].S, mask});
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans) {
            bitset <15> b(x.S);
            cerr << x.F << " " << b << "\n";
        }*/
    //}

    return 0;
}
