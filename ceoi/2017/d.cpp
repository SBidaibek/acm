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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
ll h[N], w[N], d[N];
int p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> h[i];
    ll allw = 0;
    forn(i, 1, n) {
        cin >> w[i];
        allw += w[i];
    }

    d[1] = -w[1];
    forn(i, 2, n) {
        d[i] = 1e18;
        forn(j, 1, i - 1) {
            ll x = -2 * h[j] * h[i] + (h[j] * h[j]) + d[j];
            if (d[i] >= x) p[i] = j;
            d[i] = min(d[i], x);
        }
        d[i] += -w[i] + (h[i] * h[i]);
        if (h[p[i]] == h[i]) {
            int j = i - 1;
            while (h[j] != h[i]) --j;
            assert(p[j] <= p[i]);
        }
        else if (h[p[i]] > h[i]) {
            int j = i - 1;
            while (h[j] <= h[i]) --j;
            assert(p[j] <= p[i]);
        }
        else {
            int j = i - 1;
            while (h[j] >= h[i]) --j;
            assert(p[j] <= p[i]);

        }
        //assert(p[i] >= p[i - 1]);
    }

    cout << d[n] + allw << "\n";


    return 0;
}
