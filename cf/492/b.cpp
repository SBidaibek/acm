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

const int N = 2e2 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const ll M = ll((1.5e6) * (1.5e6));

int n, a[N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, 2 * n)
        cin >> a[i];
    forn(len, 1, 2 * n) {
        forn(l, 1, 2 * n - len + 1) {
            int r = l + len - 1;
            d[l][r] = INF;
            forn(i, 1, n) cnt[i] = 0;
            forn(i, l, r) c[i] = 0, ++cnt[a[i]];
            forn(i, 1, n) on[i] = (cnt[i] == 2);
            c[l - 1] = 0;
            forn(i, l, r) {
                ++cnt[a[i]];
                c[i] = c[i - 1] + (cnt[a[i]] == 1 ? 1 : -1);
                if (c[i] == 0)
                    d[l][r] = min(d[l][r], d[l][i] + d[i + 1][r]);
            }

        }
    }

    return 0;
}
