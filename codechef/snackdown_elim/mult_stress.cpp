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

int a[N];
ll c[N], d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(t, 1, 1000) {
        cerr << "test " << t << "\n";
        int n = 11;
        //cin >> n;
        forn(i, 1, n)
            a[i] = rand() % 10 + 1;
            //cin >> a[i];
        ll ans = a[1], cur = a[1], sum = a[1];
        d[1] = a[1];
        c[1] = 1;
        forn(i, 2, n) {
            c[i] = i == 2 ? 1 : c[i - 1] * 2 % B;
            ll s = 1;
            d[i] = 0;
            for1(j, i, 1) {
                s = s * a[j] % B;
                d[i] = (d[i] + d[j - 1] + c[j] * s) % B;
            }
            cur = (cur + c[i]) * a[i] % B;
            ans = (sum + cur) % B;
            sum = (sum + ans) % B;
        }
        //cout << ans << " " << d[n] << "\n";
        if (ans != d[n]) {
            cerr << ans << " " << d[n] << "\n";
            cerr << n << "\n";
            forn(i, 1, n)
                cerr << a[i] << " ";
            exit(0);
        }
        //assert(ans == d[n]);
        //cout << ans << "\n";
    }

    return 0;
}

