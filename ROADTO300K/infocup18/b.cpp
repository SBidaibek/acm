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

int n;
int d[N];

bool bit(int mask, int i) {
    return mask & (1 << i);
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[(1 << n) - 1] = 1;
    for1(mask, (1 << n) - 1, 0) {
        if (d[mask] == 1) {
            bitset <8> b(mask);
            cerr << b << "\n";
        }
        if (d[mask] == 0) continue;
        vi v;
        forn(i, 0, n - 1)
            if (bit(mask, i)) v.pb(i);
        forn(i, 0, v.size() - 3) {
            int to = mask;
            to ^= (1 << v[i]);
            to ^= (1 << v[i + 2]);
            d[to] = 1;
        }
    }

    return 0;
}
