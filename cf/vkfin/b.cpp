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

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <pii> v;
    int sz = 1;
    --n;
    forn(i, 1, k) {
        v.emplace_back(1, ++sz);
        forn(j, 2, n / k + (i <= n % k ? 1 : 0)) {
            v.emplace_back(sz, sz + 1);
            ++sz;
        }
    }
    cout << n / k * 2 + (n % k > 0) + (n % k > 1) << "\n";/*
    forn(i, 2, (n - k) + 2)
        v.emplace_back(i - 1, i);
    forn(i, n - k + 3, n)
        v.emplace_back(2, i);
    cout << n - k + 1 << "\n";*/
    for (auto x : v)
        cout << x.F << " " << x.S << "\n";

    return 0;
}
