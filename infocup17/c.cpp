#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int d[N][N], w[N][N], p[N][N];
bool c[N][N];

int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i != 0) continue;
        ans -= ans / i;
        while (x % i == 0) x /= i;
    }
    if (x > 1) ans -= ans / x;
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("output", "w", stdout);
    #else
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(d, -1, sizeof d);
    memset(w, 0, sizeof w);
    d[0][0] = 0;
    w[0][0] = 1;
    int k = 2000;
    forn(i, 0, k) {
        forn(j, 0, k - i) {
            if (d[i][j] == -1) continue;
            int x = i + j + 1;
            if (x > k) continue;
            if (d[x][j] == -1) {
                d[x][j] = d[i][j] + 1;
                p[x][j] = i;
                c[x][j] = 0;
            }
            w[x][j] = (w[x][j] + w[i][j]) % B;
            if (d[i][x] == -1) {
                d[i][x] = d[i][j] + 1;
                p[i][x] = j;
                c[i][x] = 1;
            }
            w[i][x] = (w[i][x] + w[i][j]) % B;
        }
    }

    forn(i, 0, 100) {
        int x = 0;
        forn(j, 0, i) {
            //cout << w[j][i - j] << " ";
            x += w[j][i - j];
        }
        //cout << x << ", ";
        //cout << "| " << x << "\n";
    }

    /*int tests;
    cin >> tests;
    while (tests--) {
        cin >> k;
   */
   forn(k, 1, 2000) {
        int K = phi(k + 2);
        /*int m = 0;
        forn(i, 0, k) {
            if (d[i][k - i] == -1) continue;
            if (d[i][k - i] < d[m][k - m]) m = i;
        }*/
        //cout << K << "\n";
        map <PII, int> mp;
        map <PII, bool> c;
        queue <int> q1, q2;
        mp[0][0] = 1;
        q1.push(0), q2.push(0);
        while (q1.size()) {
            int i = q1.front(), j = q2.front();
            q1.pop(), q2.pop();
            int x = i + j + 1;
            if (x > k) continue;
        }
        vi v;
        for (int i = m, j = k - m; i || j;) {
            if (!c[i][j]) {
                v.pb(0);
                i = p[i][j];
            }
            else {
                v.pb(1);
                j = p[i][j];
            }
        }
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
