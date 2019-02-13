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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;



int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    forn(i, 1, n) {
        if (__gcd(rand(), rand()) == 1) ++cnt;
    }
    cout << ld(cnt) / n << "\n";

    /*
    int n, sd;
    cin >> n >> sd;
    srand(sd);
    ld k;
    cin >> k;
    int cnt = 0;
    //ld sum = 1;
    forn(i, 1, n) {
        ld a = (ld)rand() / RAND_MAX;
        ld b = (ld)rand() / RAND_MAX;
        ld c = (ld)rand() / RAND_MAX;
        ld d = (ld)rand() / RAND_MAX;
        if (a + b + c + d <= k) ++cnt;
        //sum *= sin(rand());
        //int a = rand(), b = rand();
        //if (__gcd(a, b) == 1) ++cnt;
    }
    cout << cnt << " " << n << " " << ld(cnt) / n << "\n";

    return 0;

    ll x = 0;
    cin >> x;
    for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) x /= i;
    }
    cout << x << "\n";
    return 0;*/

    return 0;
}
