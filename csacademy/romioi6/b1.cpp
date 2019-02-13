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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int L = 21;

int n, a[N], cnt[N], lst[N];
ll s[N][2], d[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i];
        lst[a[i]] = n + 1;
    }
    for1(i, n, 1) {
        ++cnt[a[i]];
        s[a[i]][cnt[a[i]] % 2] += (lst[a[i]] - i);
        d[i] = s[a[i]][(cnt[a[i]] % 2) ^ 1];
        lst[a[i]] = i;
    }

    ll ans = 0;
    vi st;
    st.pb(0);
    forn(i, 1, n) {
        while (a[i] < a[st.back()]) st.pop_back();
        ans += 1ll * (i - st.back()) * d[i];
        st.pb(i);
    }
    cerr << ans << "\n";
    //cout << (n * (n + 1) / 2) - ans << "\n";

    return 0;
}

