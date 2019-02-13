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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool isprime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    forn(i, 0, n - 1) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << "1\n";
            return 0;
        }
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    int g = 0;
    forn(i, 0, n - 1)
        g = __gcd(g, a[i]);
    if (g != 1) {
        cout << "-1\n";
        return 0;
    }
    forn(i, 0, n - 1) {
        if (isprime(a[i])) {
            cout << "2\n";
            return 0;
        }
    }
    if (n <= 20) {
        int ans = n;
        forn(mask, 0, (1 << n) - 1) {
            int g = 0;
            forn(i, 0, n - 1)
                if (mask & (1 << i))
                    g = __gcd(g, a[i]);
            if (g == 1)
                ans = min(ans, __builtin_popcount(mask));
        }
        cout << ans << "\n";
        return 0;
    }
    cout << "2\n";
    return 0;

    forn(it, 1, 100) {
    srand(it);
    int n, m;
    n = 20;
    vi a(n);
    forn(i, 0, n - 1) a[i] = rand() + 1;
    int ans = n;
    int g = 0;
    forn(i, 0, n - 1)
        g = __gcd(g, a[i]);
    if (g != 1) continue;
    forn(mask, 0, (1 << n) - 1) {
        int g = 0;
        forn(i, 0, n - 1)
            if (mask & (1 << i))
                g = __gcd(g, a[i]);
        if (g == 1)
            ans = min(ans, __builtin_popcount(mask));
    }
    cerr << ans << "\n";
    }

    return 0;
}


