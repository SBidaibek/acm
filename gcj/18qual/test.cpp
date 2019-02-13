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
typedef vector <int> vi;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int a = 0, b = 0;
    forn(i, 0, (1 << 8) - 1) {
        if (__builtin_popcount(i) !=  4) continue;
        vi o, z;
        forn(j, 0, 7)
            if (i & (1 << j))
                o.pb(j);
            else
                z.pb(j);
        do {
            ++b;
            int ok = 0;
            forn(q, 0, 0)
                forn(w, 1, 1)
                    forn(e, 2, 2)
                        forn(j, 0, 3)
                            if ((o[j] == q || o[j] == w || o[j] == e)
                                && (z[j] == q || z[j] == w || z[j] == e)) ok = 1;
            a += (!ok) ;
        } while (next_permutation(z.begin(), z.end()));
    }

    cout << a / __gcd(a, b) << "/" << b/ __gcd(a, b) << " = " << ld(a) / b << "\n";

    return 0;
}
