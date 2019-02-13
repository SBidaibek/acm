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

void yes() {
    cout << "Yes\n";
    exit(0);
}

void no() {
    cout << "No\n";
    exit(0);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    int a[N];
    cin >> n;
    int mn = n, mx = 1;
    forn(i, 1, n) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (mn < mx - 1) no();
    if (mn == mx) {
        if (mn == n - 1) yes();
        if (1 <= mn && mn <= n / 2) yes();
        no();
    }
    else {
        int cn = 0, cx = 0;
        forn(i, 1, n)
            if (a[i] == mn)
                ++cn;
            else
                ++cx;
        if (cn + 1 <= mx && mx <= cn + cx / 2) yes();
        else no();
    }

    return 0;
}
