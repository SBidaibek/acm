
#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 2;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;
int a[N], d[N][2];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n) {
        d[i][0] = i - 1, d[i][1] = i - 1;
        forn(j, 1, i - 1) {
            if (a[i] < a[j]) d[i][0] = min(d[i][0], d[j][1] + (i - j - 1));
            if (a[i] > a[j]) d[i][1] = min(d[i][1], d[j][0] + (i - j - 1));
        }
    }
    cout << min(d[n][0], d[n][1]) << "\n";

    return 0;
}
