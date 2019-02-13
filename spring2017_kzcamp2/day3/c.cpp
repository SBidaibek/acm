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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
int a[N];
unordered_map <int, int> t;

int g(int x) {
    int ans = 0;
    for (; x > 0; x = (x & (x + 1)) - 1) ans += t[x];
    return ans;
}

void u(int x, int d) {
    for (; x <= 1e9; x |= x + 1) t[x] += d;
}

int bs(int x) {
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (a[m] + g(a[m]) <= x) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    forn(i, 1, m) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 1) {
            cout << a[x] + g(a[x]) << "\n";
        }
        else {
            if (a[n] + g(a[n]) <= x) continue;
            int l = bs(x), r = bs(x + x);
            u(x + x + 1, -x);
            if (l == r || l == 1) continue;
            forn(j, l, r - 1)
                a[j] += g(a[j]) - x;
            //forn(j, 1, n) cerr << a[j] << " ";cerr << "\n";
            inplace_merge(a + 1, a + l, a + r);
            //forn(j, 1, n) cerr << a[j] << " ";cerr << "\n";
            //forn(j, 1, n) cerr << a[j] + g(a[j]) << " ";cerr << "\n";
        }
    }

    return 0;
}
