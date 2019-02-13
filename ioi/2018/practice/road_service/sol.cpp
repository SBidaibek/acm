#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vp;
typedef long double ld;

const int N = 1e3 + 10;
const int INF = 1e9 + 19;
const int B = 1e9 + 7;

int n, k, w;
vi g[N];
int a[N][N], d[N][N];

int tot_dist() {
    ll ans = 0;
    forn(i, 1, n) {
        queue <int> q;
        forn(j, 1, n) d[i][j] = -1;
        q.push(i);
        d[i][i] = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            if (x > i) ans += d[i][x];
            for (auto to : g[x])
                if (d[i][to] == -1) {
                    d[i][to] = d[i][x] + 1;
                    q.push(to);
                }
        }
    }
    return ans;
}

ld score(int it) {
    ld p = (it == 1 ? 10 : 18);
    return min(p, p * pow(20, 1 - tot_dist() / ld(w)));
}

vp rand_sol() {
    vector <pii> ans;
    forn(i, 1, k) {
        int f, t;
        do {
            f = rand() % n + 1;
            t = rand() % n + 1;
        } while (f == t || a[f][t]);
        if (f > t) swap(f, t);
        ans.pb({f, t});
        a[f][t] = 1;
        a[t][f] = 1;
        g[f].pb(t);
        g[t].pb(f);
    }
    return ans;
}

vp diam_sol() {
    vector <pii> ans;
    forn(it, 1, k) {
        int f = 1, t = 1;
        tot_dist();
        forn(i, 1, n)
            forn(j, i + 1, n)
                if (d[f][t] < d[i][j]) f = i, t = j;
        ans.pb({f, t});
        a[f][t] = 1;
        a[t][f] = 1;
        g[f].pb(t);
        g[t].pb(f);
    }
    return ans;
}

vp greedy_sol() {
    vector <pii> ans;
    forn(it, 1, k) {
        int f = 1, t = 1;
        tot_dist();
        vi s(n + 1, 0);
        forn(i, 1, n)
            forn(j, 1, n)
                s[i] += d[i][j];
        forn(i, 1, n)
            if (s[i] >= s[f]) {t = f; f = i;}
            else if (s[i] > s[t]) t = i;
        if (f > t) swap(f, t);
        ans.pb({f, t});
        a[f][t] = 1;
        a[t][f] = 1;
        g[f].pb(t);
        g[t].pb(f);
    }
    return ans;
}

int main() {
    cerr << fixed << setprecision(2);
    forn(it, 1, 6) {
        char in[20], out[20];
        sprintf(in, "input_%02d.txt", it);
        sprintf(out, "output_%02d.txt", it);
        freopen(in, "r", stdin);
        freopen(out, "w", stdout);

        cin >> n >> k >> w;
        forn(i, 1, n - 1) {
            int f, t;
            cin >> f >> t;
            ++f, ++t;
            g[f].pb(t);
            g[t].pb(f);
            a[f][t] = 1;
            a[t][f] = 1;
        }

        //vp ans = rand_sol();
        vp ans = greedy_sol();
        cerr << "test: " << it << ", dist = " << tot_dist() << ", score = " << score(it) << "/" << (it == 1 ? 10 : 18) << "\n";

        for (auto p : ans)
            cout << p.F - 1 << " " << p.S - 1 << "\n";
        forn(i, 1, n)
            g[i].clear();
        forn(i, 1, n)
            forn(j, 1, n)
                a[i][j] = 0;
    }

    return 0;
}
