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

const int N = 500 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = N;

bool isp[N];
int d[N][K];
int c[N][K], v[N][K];
int pwr[K][K], id[N];
int _n, ans;
vi dv, p;
int sz, P;

int dp(int i, int j) {
    if (d[i][j]) return d[i][j];
    int k = 1;
    forn(pi, 0, P - 1)
        k *= pwr[pi][min(v[_n][pi], c[i - 1][pi] - v[dv[j]][pi])];
    k = id[k];
    if (j == sz - 1 || k == sz - 1)
        return d[i][j] = (j == sz - 1 ? -1 : +1);
    d[i][j] = -1;
    if (i == 7 && j == 3) cerr << k << "\n";
    forn(q, i, _n - 1) {
        if (dp(q + 1, k) == -1) {
            if (i == 8 && j == 6) cerr << q << " " << k << " " << "\n";
            if (i == 1 && j == 0) ans = q;
            return d[i][j] = 1;
        }
    }
    return -1;
}

int solve (int n) {
    memset(pwr, 0, sizeof pwr);
    memset(d, 0, sizeof d);
    memset(c, 0, sizeof c);
    memset(v, 0, sizeof v);
    memset(id, 0, sizeof id);
    _n = n;
    dv.clear(), p.clear();
    forn(i, 1, n)
        if (n % i == 0) {
            id[i] = dv.size();
            dv.pb(i);
            if (isp[i]) p.pb(i);
        }
    sz = dv.size();
    P = p.size();
    if (sz == 2) return n - 1;
    forn(i, 1, n) {
        int x = i;
        forn(j, 0, P - 1) {
            v[i][j] = 0;
            while (x % p[j] == 0) ++v[i][j], x /= p[j];
            c[i][j] = c[i - 1][j] + v[i][j];
            //cerr << i << " " << p[j] << ": " << v[i][j] << " "<< c[i][j] << "\n";
        }
    }
    forn(i, 0, P - 1) {
        pwr[i][0] = 1;
        forn(j, 1, v[n][i])
            pwr[i][j] = pwr[i][j - 1] * p[i];
    }
    ans = 0;
    //9assert(dp(1, 0) == 1);
    cerr << dp(2, 0) << "\n";
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 2, N - 1) {
        isp[i] = 1;
        forn(j, 2, i - 1)
            if (i % j == 0)
                isp[i] = 0;
    }

    int ts;
    cin >> ts;
    forn(_, 1, ts) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}
