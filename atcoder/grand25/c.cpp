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
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].F >> a[i].S;

    a[++n] = {0, 0};
    forn(i, 1, n)
        a[i].S *= -1;
    set <pii> sl, sr;
    forn(i, 1, n)
        sl.insert({a[i].F, i}), sr.insert({a[i].S, i});

    ll ans = 0;
    forn(k, 1, n / 2) {
        int i = sl.rbegin() -> S;
        sr.erase({a[i].S, i});
        int j = sr.rbegin() -> S;
        sr.insert({a[i].S, i});
        ll x = a[i].F + a[j].S;

        i = sr.rbegin() -> S;
        sl.erase({a[i].F, i});
        j = sl.rbegin() -> S;
        sl.insert({a[i].F, i});
        if (x >= a[i].S + a[j].F) {
            i = sl.rbegin() -> S;
            sl.erase({a[i].F, i});
            sr.erase({a[i].S, i});
            j = sr.rbegin() -> S;
            sl.erase({a[j].F, j});
            sr.erase({a[j].S, j});
        }
        else {
            x = a[i].S + a[j].F;
            sl.erase({a[i].F, i});
            sr.erase({a[i].S, i});
            sl.erase({a[j].F, j});
            sr.erase({a[j].S, j});
        }
        if (x < 0) break;
        ans += x;
    }

    cout << 2 * ans << "\n";

    return 0;
}
