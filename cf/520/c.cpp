#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll p[N], s[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1, s[0] = 1;
    forn(i, 1, N - 1) {
        p[i] = p[i - 1] * 2 % B;
        s[i] = (s[i - 1] + p[i]) % B;
    }

    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    forn(i, 1, n) {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
        a[i] += a[i - 1];
    }
    forn(i, 1, q) {
        int l, r;
        cin >> l >> r;
        int o = (a[r] - a[l - 1]);
        int z = r - l + 1 - o;
        ll ans = (s[o - 1] + s[o - 1] * s[z - 1]) % B;
        cout << ans << "\n";
    }

    return 0;
}

