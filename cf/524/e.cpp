#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 500;
const int INF = 1e9 + 9;

char a[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        forn(j, 1, m)
            cin >> a[i][j];
    forn(i, 1, n) {
        forn(l, 1, m) {
            vi cnt(26);
            int o = 0;
            forn(r, l, m) {
                if (cnt[a[i][r] - 'a'] % 2 == 1) --o;
                ++cnt[a[i][r] - 'a'];
                if (cnt[a[i][r] - 'a'] % 2 == 1) ++o;
            }
        }
    }

    return 0;
}
