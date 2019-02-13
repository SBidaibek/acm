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
typedef vector <int> vi;

const int N = 15000;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll f[N];

ll solve(vi a) {
    int n = a.size();
    vi cnt(301, 0);
    for (auto x : a) ++cnt[x];
    for (;;) {
        int d1 = cnt[1] / 2;
        cnt[1] -= d1 * 2, cnt[2] += d1;
        forn(i, 1, cnt.size() - 3) {
            int d = min(cnt[i], cnt[i + 1]);
            cnt[i] -= d, cnt[i + 1] -= d, cnt[i + 2] += d;
        }
        bool up = 0;
        for (auto x : cnt) if (x > 1) up = 1;
        if (!up) break;
        for1(i, cnt.size() - 1, 2) {
            int d = cnt[i] / 2;
            cnt[i] -= d, cnt[i - 1] += d, cnt[max(1, i - 2)] += d;
        }
    }
    //forn(i, 0, 10) cerr << cnt[i] << " ";cerr << "\n";
    ll dp[2] = {1, 0};
    int prv = 0;
    forn(i, 0, cnt.size() - 1) {
        if (!cnt[i]) continue;
        ll np[2] = {0, 0};
        np[0] = (dp[0] + dp[1]) % B;
        np[1] = (dp[0] * ((i - prv - 1) / 2) + dp[1] * ((i - prv) / 2)) % B;
        dp[0] = np[0], dp[1] = np[1];
        prv = i;
    }
    return (dp[0] + dp[1]) % B;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    f[1] = 1, f[2] = 2;
    forn(i, 3, N - 1)
        f[i] = (f[i - 1] + f[i - 2]);

    int n;
    cin >> n;
    vi v;
    forn(i, 1, n) {
        int x;
        cin >> x;
        v.pb(x);
        cout << solve(v) << "\n";
    }

    return 0;
}
