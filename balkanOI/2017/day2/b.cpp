#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int P = 31;

int n, m, d[N][N], l[N];
char a[N][N];
ll p[N][N];

ll total() {
    ll ans = 0;
    forn(i, 1, n) {
        vi v;
        v.pb(0);
        forn(j, 1, m) {
            while (d[i][j] < d[i][v.back()]) v.pop_back();
            l[j] = v.back();
            v.pb(j);
        }
        v.clear();
        v.pb(m + 1);
        d[i][m + 1] = -1;
        for1(j, m, 1) {
            while (d[i][j] <= d[i][v.back()]) v.pop_back();
            ans +=1ll * d[i][j] * (j - l[j]) * (v.back() - j);
            v.pb(j);
        }
    }
    cerr << "T = " << ans << "\n";
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m) {
            cin >> a[i][j];
            d[i][j] = a[i][j] == '0' ? 0 : d[i - 1][j] + 1;
        }
    forn(i, 1, n) {
        for1(j, n, i) {
            ll c = 0;
            forn(k, 1, m) {
                if (j - d[j][k] >= i) {c = 0; continue;}
                l[k] = ++c;
            }
            c = 0;
            for1(k, m, 1) {
                if (j - d[j][k] >= i) {c = 0; continue;}
                ++c;
                p[i][k] += c * l[k], p[j + 1][k] -= c * l[k];
            }
        }
    }
    ll ans = 0;
    forn(i, 1, n) {
        forn(j, 1, m) {
            p[i][j] += p[i - 1][j];
            //cerr << p[i][j] << " ";
            ans = max(ans, p[i][j]);
        }
        //cerr << "\n";
    }
    cout << total() - ans << "\n";

    return 0;
}
