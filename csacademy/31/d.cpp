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

map <pii, int> mn, c;

int q(int x, int y) {
    if (c.count({x, y})) return c[{x, y}];
    if (x == -1 || y == -1)
        return x == -1 ? y : x;
    cout << "Q " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return c[{x, y}] = ans;
}

int gen(int l, int r) {
    if (l == r) return mn[{l, r}] = l;
    int m = (l + r) / 2;
    return mn[{l, r}] = q(gen(l, m), gen(m + 1, r));
}

pii solve(int l, int r) {
    if (l == r) return {l, -1};
    if (l == r - 1) return q(l, r) == l ? pii(l, r) : pii(r, l);
    int m = (l + r) / 2;
    int p1 = mn[{l, m}], p2 = mn[{m + 1, r}];
    if (q(p1, p2) == p1)
        return {p1, q(solve(l, m).S, p2)};
    else
        return {p2, q(p1, solve(m + 1, r).S)};
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black

    int n;
    cin >> n;
    int p1 = gen(1, n);
    cout << "A " << solve(1, n).S << "\n";

    return 0;
}
