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

int n, k;
vi a[N];


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int ov = 0, sz = 0;
    forn(i, 1, n) {
        int l;
        cin >> l;
        vi v(l), u(k + 1);
        forn(j, 1, l) {
            cin >> v[j - 1];
            u[v[j - 1]] = 1;
        }
        if ((l && v[0] == 1) || !u[1]) {
            ++ov;
            continue;
        }
        ++sz;
        forn(j, 1, k)
            if (!u[j]) a[sz].pb(j);
        if (l) a[sz].pb(v[0]);
    }
    n = sz;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!poss(mid)) l = mid + 1;
        else r = mid;
    }
    cout << max(0, l - ov + 1) << "\n";

    return 0;
}
