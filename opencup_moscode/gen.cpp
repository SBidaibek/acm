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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
int deg[N], cnt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        for (int j = i * 2; j <= n; j += i)
            ++deg[i], ++deg[j];
        ++cnt[deg[i]];
    }
    int ans = 0;
    int lst = 0;
    forn(i, 1, n)
        if (cnt[deg[i]] == 1)
            cout << i << ": " << deg[i] << "\n";
    forn(i, 1, n) {
        //if (cnt[i) cout << i << ": " << cnt[i] << "\n";
        if (cnt[i] == 1) ++ans;
    }
    cerr << ans << "\n";


    return 0;
}
