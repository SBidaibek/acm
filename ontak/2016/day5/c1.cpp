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

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
vector <string> sav[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        int k;
        cin >> k;
        string str;
        cin >> str;
        sav[k].pb(str);
    }
    int ans = min(25, (int)sav[1].size());

    #define f(x) 1ll * (x - 'a' + 1)
    forn(len, 2, 300) {
        if (!sav[len].size()) continue;
        typedef vector <ll> vll;
        map <pii, int> mp;
        vector <vll> a1, a2;
        for (auto s : sav[len]) {
            a1.pb(vll(0)), a2.pb(vll(0));
            for (auto c : s) {
                a1.pb(;
            }
        }
    }

    forn(len, 301, 2e5) {
        if (!sav[len].size()) continue;
        vector <string> &a = sav[len];
        forn(i, 0, a.size() - 1) {
            map <pii, int> mp;
            vi sum(len);
            forn(j, 0, a.size() - 1) {
                if (i == j) continue;
                int cnt = 0, p1 = -1, p2 = -1;
                forn(k, 0, len - 1) {
                    if (a[i][k] == a[j][k]) continue;
                    if (++cnt > 2) break;
                    if (p1 == -1) p1 = k;
                    else p2 = k;
                }
                if (cnt > 2) continue;
                if (cnt == 1) ++sum[p1];
                else ++mp[{p1, p2}];
            }
            int m1 = 0, m2 = 0;
            forn(i, 0, len - 1) {
                if (sum[i] > m1) {
                    m2 = m1; m1 = sum[i];
                }
                else if (sum[i] > m2)
                    m2 = sum[i];
            }
            int cur = 1 + m1 + m2;
            for (auto p : mp)
                cur = max(cur, 1 + p.S + sum[p.F.F] + sum[p.F.S]);
            cur = min(cur, 26 * 26 - 1);
            ans = max(ans, cur);
        }
    }

    cout << ans << "\n";

    return 0;
}
