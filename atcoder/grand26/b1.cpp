#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(n, 1, 20) {
        cerr << n << ": ";
        vi cnt(n + 1, 0);
        forn(mask, 0, (1 << (n - 1)) - 1) {
            int prv = -1;
            forn(i, 0, n - 2) {
                if (!(mask & (1 << i))) continue;
                cnt[i - prv]++;
                prv = i;
            }
            cnt[n - 1 - prv]++;
        }
        forn(i, 1, n)
            cerr << cnt[i] << " ";
        cerr << "\n";
    }

    return 0;
}
