#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(it, 1, 25) {
        int i = (1 << it) - 1;
        int ans = 0;
        forn(j, 1, i - 1) {

            //cout << i << " " << j << " " << __gcd(i ^ j, i & j) << "\n";/*
            ans = max(ans, __gcd(i ^ j, i & j));
        }
            cout << ans << ", ";

    }

    return 0;
}
