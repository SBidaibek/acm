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
typedef vector <int> vi;

const int N = 4e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n + 1);
    vi b(n + 1);
    vi d(n + 1);
    forn(i, 1, n) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for1(it, n, 1) {
        int i = b[it];
        d[i] = 0;
        for (int j = i + a[i]; j <= n; j += a[i])
            if (a[j] > a[i] && !d[j]) d[i] = 1;
        for (int j = i - a[i]; j >= 1; j -= a[i])
            if (a[j] > a[i] && !d[j]) d[i] = 1;
    }
    forn(i, 1, n)
        cout << (d[i] ? 'A' : 'B');
    cout << "\n";

    return 0;
}

