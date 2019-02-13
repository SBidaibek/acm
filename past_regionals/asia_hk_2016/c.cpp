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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

const ld lg23 = log(3) / log(2);

pii gcd(pii a, pii b) {
    return {min(a.F, b.F), min(a.S, b.S)};
}

pii lcm(pii a, pii b) {
    return {max(a.F, b.F), max(a.S, b.S)};
}

ld v(pii a) {
    return a.F + lg23 * a.S;
}

pii Max(pii a, pii b) {
    return v(a) > v(b) ? a : b;
}

pii Min(pii a, pii b) {
    return v(a) < v(b) ? a : b;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <pii> a(n + 1);
    forn(i, 1, n)
        cin >> a[i].F >> a[i].S;
    pii mx = a[1], mn = a[1];
    forn(i, 1, n) {
        mx = lcm(mx, a[i]);
        mn = gcd(mn, a[i]);
    }

    vector <pii> amn(n + 1), amx(n + 1);
    forn(i, 1, n) {
        if (n - i == 0) {
            amx[i] = a[1];
            forn(j, 2, n)
                amx[i] = gcd(amx[i], a[j]);
        }
        else
        if (n - i == 1) {
            vector <pii> s(n + 2), p(n + 2);
            p[0] = s[n + 1] = {INF, INF};
            forn(j, 1, n)
                p[j] = gcd(p[j - 1], a[j]);
            for1(j, n, 1)
                s[j] = gcd(s[j + 1], a[j]);
            amx[i] = {0, 0};
            forn(j, 1, n)
                amx[i] = Max(amx[i], lcm(a[j], gcd(p[j - 1], s[j + 1])));
        }
        else
            amx[i] = mx;
    }
    forn(i, 1, n) {
        if (i - 1 == 0) {
            amn[i] = a[1];
            forn(j, 2, n)
                amn[i] = lcm(amn[i], a[j]);
        }
        else
        if (i - 1 == 1) {
            vector <pii> s(n + 2), p(n + 2);
            p[0] = s[n + 1] = {0, 0};
            forn(j, 1, n)
                p[j] = lcm(p[j - 1], a[j]);
            for1(j, n, 1)
                s[j] = lcm(s[j + 1], a[j]);
            amn[i] = {INF, INF};
            forn(j, 1, n)
                amn[i] = Min(amn[i], gcd(a[j], lcm(p[j - 1], s[j + 1])));
        }
        else
            amn[i] = mn;
    }

    forn(i, 1, n)
        cout << amx[i].F << " " << amx[i].S << " " << amn[i].F << " " << amn[i].S << "\n";

    return 0;
}

