#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll slow(vi a) {
    ll ans = 0;
    forn(i, 1, a.size() - 1)
        forn(j, i + 1, a.size() - 1)
            forn(k, j + 1, a.size() - 1)
                if (a[i] * a[j] == a[k] || a[i] * a[k] == a[j] || a[k] * a[j] == a[i])
                    ++ans;
    if (ans == 281){
        for (auto x : a) cerr << x << " ";cerr << "\n";}
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(_, 1, T) {
        cout << "Case #" << _ << ": ";
        int n;
        cin >> n;
        vi c(N);
        vi a(n + 1);
        forn(i, 1, n) {
            cin >> a[i];
            ++c[a[i]];
        }
        ll ans = c[1] * (c[1] - 1) * (c[1] - 2) / 6;
        ans += c[0] * (c[0] - 1) * (c[0] - 2) / 6;
        ans += c[0] * (c[0] - 1) / 2 * (n - c[0]);
        forn(i, 2, N - 1) {
            ans += (c[i] * (c[i] - 1)) / 2 * c[1];
            for (ll j = i; j * i < N; ++j) {
                if (j == i)
                    ans += (c[i] * (c[i] - 1)) / 2 * c[i * i];
                else
                    ans += c[i] * c[j] * c[i * j];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

