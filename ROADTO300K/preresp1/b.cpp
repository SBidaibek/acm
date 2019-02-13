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



int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(n, 1, 20) {
        int cnt = 0;
        forn(mask, 0, (1 << n) - 1) {
            bitset <20> b(mask);
            bool shit = 0;
            forn(i, 0, n - 1) {
                if (i * 4 >= n || shit) break;
                if (b[i * 4 + 1] + b[i * 4 + 2] + b[i * 4 + 3] > 1) shit = 1;
                if (i >= 1)
                    if (b[i * 4 - 2] + b[i * 4 - 1] + b[i * 4] + b[i * 4 + 1] + b[i * 4 + 2] > 2) shit = 1;
            }
            if (!shit) ++cnt;
        }
        cout << n << ": " << cnt << " " << (cnt % 8) << " " << cnt / 8 << " ";
        if (n % 4 == 0) cout << "!";
        cout << "\n";
    }

    return 0;
}
