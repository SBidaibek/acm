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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, k;
string a, b;

bool ok(int m) {
    vi d1(26), d2(26);
    ll s = 1;
    forn(i, 0, m - 1) {
        ll x = s - d1[a[i] - 'a'];
        d1[a[i] - 'a'] = s;
        s += x;
    forn(i, 0, 2)
        cerr << char('a' + i) << ": " << d1[i] << "\n";cerr << "-\n";
    }
    s = 1;
    forn(i, 0, k - 1) {
        ll x = s - d2[b[i] - 'a'];
        d2[b[i] - 'a'] = s;
        s += x;
    }
    s = 0;
    forn(i, 0, 25) {
        cerr << char('a' + i) << ": " << d1[i] << " " << d2[i] << "\n";
        s += max(0ll, d2[i] - d1[i]);
    }
    return s <= 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (k == 1) {
        cout << "0\n";
        return 0;
    }
    cin >> a >> b;
    cerr << ok(4) << "\n";
    return 0;
    int l = k - 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (!ok(m)) l = m + 1;
        else r = m;
    }
    cout << l << "\n";

    return 0;

}
