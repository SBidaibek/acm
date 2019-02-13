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

//vi v[N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
//    ios_base :: sync_with_stdio(0);
//    cin.tie(0);

    string s = "kek " + 252;
    cerr << s << "\n";
/*
    int n;
    cin >> n;
    vi a(n + 1);
    forn(i, 1, n) {
        cin >> a[i];
        a[i] = n - a[i];
        v[a[i]].pb(i);
    }
    int c = 0;
    vi ans(n + 1);
    bool bad = 0;
    forn(i, 1, n) {
        if (!v[i].size()) continue;
        if (v[i].size() % i != 0) bad = 1;
        int d = 0;
        for (auto x : v[i]) {
            if (d++ % i == 0) ++c;
            ans[x] = c;
        }
    }
    if (c > n) bad = 1;
    if (bad == 1)
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        forn(i, 1, n)
            cout << ans[i] << " ";
        cout << "\n";
    }*/

    return 0;
}
