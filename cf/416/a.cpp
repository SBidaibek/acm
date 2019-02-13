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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N], lst[N], prv[N], d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    forn(i, 1, n) {
        vi u(5e3 + 1);
        int xs = 0;
        int s = 0;
        for1(j, i, 1) {
            if (!u[a[j]]) {
                if (lst[a[j]] != j) break;
                ++s;
                xs ^= a[j];
            }
            u[a[j]] = 1;
            if (prv[j] == 0) --s;
            if (s == 0) d[i] = max(d[i], d[j - 1] + xs);
        }
        d[i] = max(d[i], d[i - 1]);
    }
    cout << d[n] << "\n";

    return 0;
}
