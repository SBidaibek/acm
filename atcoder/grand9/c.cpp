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

const int N = 2e6 + 1;
const ll INF = 4e18 + 9;
const int B = 1e9 + 7;

ll n, a, b;
ll s[N];
ll d[N][2];

ll t[N];

ll g(int l, int r) {
    ll ans = INF;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans = min(ans, t[l++]);
        if (r % 2 == 0) ans = min(ans, t[r--]);
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    forn(i, 1, n)
        cin >> s[i];
    forn(i, 1, n)
        t[i + n - 1] = s[i + 1] - s[i];
    for1(i, n - 1, 1)
        t[i] = min(t[i * 2], t[i * 2 + 1]);

    d[0][0] = 1;
    s[0] = -INF;
    forn(i, 1, n) {
        if (s[i] - s[i - 1] >= a)
            d[i][0] = (d[i - 1][0] + d[i - 1][1]) % B;
        else {
            int l = 0, r = i - 2;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (s[i] - s[m] < a) r = m - 1;
                else l = m;
            }
            if (l == i - 2 || g(l + 1, i - 2) >= b) d[i][0] = d[l + 1][1];
            //int j = i - 2;
            //ll mn = INF;
            //for (; s[i] - s[j] < a; --j)
            //    mn = min(mn, s[j + 1] - s[j]);
            //if (mn >= b) d[i][0] = d[j + 1][1];
        }
        if (s[i] - s[i - 1] >= b)
            d[i][1] = (d[i - 1][0] + d[i - 1][1]) % B;
        else {
            int l = 0, r = i - 2;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (s[i] - s[m] < b) r = m - 1;
                else l = m;
            }
            if (l == i - 2 || g(l + 1, i - 2) >= a) d[i][1] = d[l + 1][0];
//            int j = i - 2;
//            ll mn = INF;
//            for (; s[i] - s[j] < b; --j)
//                mn = min(mn, s[j + 1] - s[j]);
//            if (mn >= a) d[i][1] = d[j + 1][0];
        }
        //cerr << i << ": " << d[i][0] << " " << d[i][1] << "\n";
    }
    cout << (d[n][0] + d[n][1]) % B << "\n";

    return 0;
}
