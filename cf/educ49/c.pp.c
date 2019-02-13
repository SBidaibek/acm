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
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N], c[N];

bool cmp(ll a, ll b, ll c, ll d) {
    return a * (a + c + d) + b * (b + c + d) <= c * (a + b + c) + d * (a + b + d);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    forn(_, 1, t) {
        int n;
        cin >> n;
        vi v;
        forn(i, 1, n) {
            cin >> a[i];
            if (++c[a[i]] == 2) v.pb(a[i]);
        }
        sort(v.begin(), v.end());
        int p = 0;
        pii ans;
        if (v.size() >= 2)
            ans = pii(v[0], v[1]);
        else
            ans = pii(v[0], v[0]);
        forn(i, 1, v.size() - 1) {
            //while (p < i - 1 && cmp(v[i], v[p + 1], v[i], v[p])) ++p;
            if (cmp(v[i], v[i - 1], ans.F, ans.S)) ans = {v[i - 1], v[i]};
        }
        forn(i, 0, v.size() - 1)
            if (c[v[i]] >= 4)
                ans = {v[i], v[i]};
        cout << ans.F << " " << ans.F << " " << ans.S << " " << ans.S << "\n";
        forn(i, 1, n) c[a[i]] = 0;
    }

    return 0;
}
