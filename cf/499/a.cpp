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

int n, m;
int a[N], b[N];

bool check(ld x) {
    forn(i, 1, n) {
        if (x <= 0) return 0;
        x -= (m + x) / a[i];
        if (x <= 0) return 0;
        x -= (m + x) / b[i + 1];
        if (x <= 0) return 0;
    }
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        cin >> a[i];
    forn(i, 1, n)
        cin >> b[i];
    a[n + 1] = a[1], b[n + 1] = b[1];

    ld l = 0, r = 1e9 + 1;
    if (!check(r)) {
        cout << "-1\n";
        return 0;
    }
    forn(it, 1, 200) {
        ld x = (l + r) / 2;
        if (check(x)) r = x;
        else l = x;
    }
    cout << fixed << setprecision(20);
    cout << l << "\n";

    return 0;
}
