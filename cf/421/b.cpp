#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 6e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
int a[N];
int mp[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n;
    scanf("%d", &n);
    int shift = 2 * n;
    ll s = 0;
    int l = 0, r = 0;
    forn(i, 1, n) {
        //cin >> a[i];
        scanf("%d", &a[i]);
        ++mp[a[i] - i + shift];
        s += abs(a[i] - i);
        if (a[i] < i) ++l;
        if (a[i] > i) ++r;
    }

    ll ans = s, at = 0;
    //cerr << "0: " << s << "\n";
    int lst = n;
    forn(i, 1, n - 1) {
        //cerr << s << " " << l << " " << r << "\n";
        s -= abs(a[lst] - n);
        --mp[a[lst] - lst + shift];
        if (a[lst] - lst > i - 1) --r;
        if (a[lst] - lst < i - 1) --l;

        //cerr << s << " " << l << " " << r << "\n";
        l += mp[i - 1 + shift];
        s += +l - r;
        r -= mp[i + shift];
        //cerr << s << " " << l << " " << r << "\n";

        s += abs(a[lst] - 1);
        ++mp[a[lst] - (1 - i) + shift];
        if (a[lst] - (1 - i) > i) ++r;
        if (a[lst] - (1 - i) < i) ++l;
        --lst;

        //cerr << s << " " << l << " " << r << "\n";
        if (s < ans) ans = s, at = i;
        //cerr << i << ": " << s << "\n";
    }
    cout << ans << " " << at << "\n";

    return 0;
}
