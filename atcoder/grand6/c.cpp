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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
ld a[N];
int m, k;
int q[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    cin >> m >> k;
    forn(i, 1, m)
        cin >> q[i];
    forn(it, 1, k) {
        forn(i, 1, m)
            a[q[i]] = (a[q[i] - 1] + (a[q[i] - 1] - a[q[i]])) / 2.0 +
                    (a[q[i] + 1] + (a[q[i] + 1] - a[q[i]])) / 2.0;
    }
    cout << fixed << setprecision(10);
    forn(i, 1, n)
        cout << a[i] << "\n";

    return 0;
}
