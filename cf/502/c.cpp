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
typedef vector <int> vi;

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int lis(vi a) {
    vi d(a.size());
    int ans = 0;
    forn(i, 1, a.size() - 1)
        forn(j, 0, i - 1)
            if (a[j] < a[i])
                {d[i] = max(d[i], d[j] + 1); ans = max(ans, d[i]);}
    return ans;
}

int lds(vi v) {
    reverse(v.begin(), v.end());
    return lis(v);
}

vi slow(int n) {
    vi ans;
    vi v(n);
    forn(i, 0, n - 1)
        v[i] = i + 1;
    int x = n + n + n;
    do {
        int cur = lis(v) + lds(v);
        if (cur < x)
            x = cur, ans = v;
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

vi fast(int n) {
    vi ans(n);
    forn(i, 0, n - 1) ans[i] = i + 1;
    int x = sqrt(n);
    for1(i, n - 1, 0) {
        int j = max(0, i - x + 1);
        reverse(ans.begin() + j, ans.begin() + i + 1);
        i = j;
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi ans = fast(n);
    for (auto x : n)
        cout << x << "\n";

    return 0;
}
