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
ll h[N], w[N], d[N], up[N], down[N];
int p1[N], p2[N];

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
        up[i] = 1e18, down[i] = 1e18;
        forn(j, 1, i - 1) {
            ll x = -2 * h[j] * h[i] + (h[j] * h[j]) + d[j];
            if (h[j] >= h[i]) {
                if (up[i] >= x) up[i] = x, p1[i] = j;
            }
            else
                if (down[i] >= x) down[i] = x, p2[i] = j;
        }
        d[i] = min(up[i], down[i]) + -w[i] + (h[i] * h[i]);
        cerr << i << " " << h[i] << ": " << up[i] << " " << down[i] << " " << d[i] << " " << p1[i] << " " << p2[i] << "\n";
        forn(j, 2, i - 1) {
            if (h[j] > h[i]) assert(p1[i] >= p1[j]);
            if (h[j] < h[i]) assert(p2[i] >= p2[j]);
        }
    }

    cout << d[n] + allw << "\n";


    return 0;
}
