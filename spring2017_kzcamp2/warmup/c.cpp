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

const int N = 4e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n = 2e3;
    forn(i, 1, n) {
        forn(j, 1, n) {
            if (!u[i * j]) ++ans;
            u[i * j] = 1;
        }
    }
    cout << ans << "\n";

    return 0;
}
