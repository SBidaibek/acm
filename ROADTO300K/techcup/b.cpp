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

vector <int> v[100];
int u[1000], cnt[1000], timer;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    forn(i, 0, n - 1)
        v[s[i] - 'a'].pb(i);

    int ans = 0;
    forn(c, 0, 'z' - 'a') {
        if (!v[c].size()) continue;
        int mx = 0;
        forn(i, 0, n - 1) {
            bool ok = 1;
            ++timer;
            forn(j, 0, v[c].size() - 1) {
                if (u[s[(v[c][j] + i) % n]] != timer)
                    cnt[s[(v[c][j] + i) % n]] = 0;
                u[s[(v[c][j] + i) % n]] = timer;
                cnt[s[(v[c][j] + i) % n]]++;
            }
            int cur = 0;
            forn(j, 0, v[c].size() - 1)
                if (cnt[s[(v[c][j] + i) % n]] == 1) ++cur;
            mx = max(mx, cur);
        }
        ans += mx;
    }

    cout << fixed << setprecision(10) << ld(ans) / n << "\n";

    return 0;
}
