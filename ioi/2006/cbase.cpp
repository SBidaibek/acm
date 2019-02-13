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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
int z[5][5], a[N][N];
bitset <N> b[N];
int ans[N][N];
int cnt[N], ca[N];
int match[N], ukuhn[N];

bool check(int K) {
    if (K <= 2) {
        forn(i, 1, n)
            forn(j, 1, n)
                b[i][j] = ans[i][j];
        forn(i, 1, n)
            forn(j, i + 1, n)
                if (ca[i] - ans[i][j] && ca[j] - ans[i][j] && (b[i] ^ b[j]).count() - ans[i][j] * 2) return 0;
        return 1;
    }
    if (K <= 4) {
        forn(i, 1, n)
            if (ca[i] > 1) return 0;
        return 1;
    }
    if (K <= 6) {
        forn(i, 1, n)
            if (ca[i] > 2) return 0;
        return 1;
    }
    forn(i, 1, n)
        forn(j, 1, n)
            b[i][j] = ans[i][j];
    if (K <= 8) {
        forn(i, 1, n) {
            int shit = 0;
            forn(j, 1, n)
                if (ans[i][j] && (b[i] & b[j]).count()) shit = 1;
            if (shit) return 0;
        }
        return 1;
    }
    forn(i, 1, n) {
        int shit = 0;
        forn(j, 1, n)
            if (ans[i][j] && (b[i] & b[j]).count()) shit = 1;
        if (ca[i] > 2 && shit) return 0;
    }
    return 1;
}

vector <int> g[N];

bool kuhn(int x) {
    if (ukuhn[x]) return 0;
    ukuhn[x] = 1;
    for (auto to : g[x])
        if (!match[to]) {
            match[x] = to, match[to] = x;
            return 1;
        }
    for (auto to : g[x])
        if (kuhn(match[to])){
            match[x] = to, match[to] = x;
            return 1;
        }
    return 0;
}

int col[N];

void dye(int x) {
    vi v;
    forn(i, 1, n)
        if (a[x][i] && !col[i]) {
            col[i] = 3 - col[x];
            dye(i);
        }
    for (auto i : v)
        dye(i);
}

void solve_opt(int K) {
    char inf[20], ouf[20];
    sprintf(inf, "forbidden%d.in", K);
    sprintf(ouf, "%02d.out", K + 1);
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
    cin >> m >> n;
    forn(i, 1, m)
        forn(j, 1, m)
            cin >> z[i][j];
    int mx = 1;
    forn(i, 1, n)
        forn(j, 1, n)
            cin >> a[i][j];

    forn(i, 1, n) ca[i] = 0;
    assert(check(K));

    if (K == 1) {
        bool found = 0;
        forn(i, 1, n) {
            forn(j, i + 1, n) {
                forn(k, j + 1, n)
                    if (a[i][j] && a[j][k] && a[k][i]) {
                        ans[i][j] = 1, ans[j][k] = 1, ans[k][i] = 1,
                        ans[j][i] = 1, ans[k][j] = 1, ans[i][k] = 1,
                        ca[i] += 2, ca[j] += 2, ca[k] += 2;
                        found = 1; break;
                    }
                if (found) break;
            }
            if (found) break;
        }
    }
    if (K == 2) {
        forn(i, 1, n) {
            forn(j, 1, n)
                cnt[i] += a[i][j];
            if (cnt[mx] < cnt[i]) mx = i;
        }
        forn(i, 1, n)
            if (a[mx][i])
                ans[mx][i] = 1, ans[i][mx] = 1, ++ca[i], ++ca[mx];
    }
    if (K == 3 || K == 4) {
        srand(1);
        forn(i, 1, n)
            col[i] = 1 + (rand() % 2);
            //if (!col[i])
            //    {col[i] = 1; dye(i);}
        forn(i, 1, n)
            forn(j, 1, n)
                if (col[i] != col[j] && a[i][j]) g[i].pb(j);
        forn(it, 1, n) {
            bool upd = 0;
            forn(i, 1, n) ukuhn[i] = 0;
            forn(i, 1, n)
                if (col[i] == 1 && !match[i] && kuhn(i)) upd = 1;
            if (!upd) break;
        }
        int e = 0;
        forn(i, 1, n)
            if (match[i]) {assert(match[match[i]] == i);
                ++ca[i], ans[i][match[i]] = 1, ++e;}
        cerr << e / 2 << "\n";
    }

    assert(check(K));
    cout << n << "\n";
    forn(i, 1, n)
        forn(j, 1, n)
            cout << ans[i][j] << " \n"[j == n];

    forn(i, 1, n)
        forn(j, 1, n)
            a[i][j] = b[i][j] = ans[i][j] = 0;
    forn(i, 1, n) cnt[i] = ukuhn[i] = match[i] = col[i] = 0;
    forn(i, 1, n) g[i].clear();
}

void solve_base(int K) {
    char inf[20], ouf[20];
    sprintf(inf, "forbidden%d.in", K);
    sprintf(ouf, "%02d.out", K + 1);
    freopen(inf, "r", stdin);
    freopen(ouf, "w", stdout);
    cin >> m >> n;
    forn(i, 1, m)
        forn(j, 1, m)
            cin >> z[i][j];
    int mx = 1;
    forn(i, 1, n)
        forn(j, 1, n)
            cin >> a[i][j];

    forn(i, 1, n) ca[i] = 0;
    assert(check(K));

    int e = 0;
    forn(i, 1, n)
        forn(j, i + 1, n) {
            if (!a[i][j]) continue;
            ans[i][j] = 1, ans[j][i] = 1;
            ++ca[i], ++ca[j];
            if (!check(K))
                ans[i][j] = 0, ans[j][i] = 0, --ca[i], --ca[j];
            else
                ++e;
        }
    cerr << e << "\n";

    //cout << "#FILE forbidden " << K << "\n";
    assert(check(K));
    cout << n << "\n";
    forn(i, 1, n)
        forn(j, 1, n)
            cout << ans[i][j] << " \n"[j == n];

    forn(i, 1, n)
        forn(j, 1, n)
            a[i][j] = b[i][j] = ans[i][j] = 0;
    forn(i, 1, n) cnt[i] = 0;
}

int main() {
    #ifdef black
    #endif // black

    //int K;
    //cin >> K;
    forn(K, 3, 4) {
        cerr << "Generating test " << K << "\n";
        //if (K <= 2)
            solve_opt(K);
        //else
        //    solve_base(K);
        cerr << "Finished test " << K << "\n";
    }

    return 0;
}
