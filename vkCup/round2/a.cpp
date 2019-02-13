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

int n, u;
int a[N];
ld d[N];
int q[N];
int h, t;

ld g(ld x) {
    h = t = 0;
    int ptr = 1;
    ld ans = -2e18;
    forn(i, 1, n)
        d[i] = -a[i + 1] + x * a[i];
    forn(i, 3, n) {
        for (; ptr < i - 1 && a[ptr] < a[i] - u; ++ptr)
            if (h > t && q[t + 1] == ptr) ++t;
        if (a[i] - a[i - 2] <= u) {
            while (h > t && d[q[h]] <= d[i - 2]) --h;
            q[++h] = i - 2;
            ans = max(ans, -(x - 1) * a[i] + d[q[t + 1]]);
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> u;
    bool ok = 0;
    forn(i, 1, n) {
        cin >> a[i];
        if (i >= 3 && a[i] - a[i - 2] <= u) ok = 1;
    }
    if (!ok) {
        cout << "-1\n";
        return 0;
    }
    ld l = 0, r = 1;
    forn(i, 1, 200) {
        ld x = (l + r) / 2;
        if (g(x) > 0) l = x;
        else r = x;
    }
    cout << fixed << setprecision(20) << l << "\n";

    return 0;
}
