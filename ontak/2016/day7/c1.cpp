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

int m, k;
string a, b;
int p[N], s[N];

bool ok(int n) {
    forn(i, 0, n - 1) {
        p[i] = (i > 0 ? p[i - 1] : 0);
        if (p[i] < k && a[i] == b[p[i]]) ++p[i];
    }
    for1(i, n - 1, 0) {
        s[i] = (i < n - 1 ? s[i + 1] : k - 1);
        if (s[i] >= 0 && a[i] == b[s[i]]) --s[i];
    }
    int ptr = 0;
    if (s[0] > 0 || p[n - 1] < k - 1) return 0;
    forn(i, 1, k - 2) {
        while (ptr < n && p[ptr] < i) ++ptr;
        if (ptr >= n - 1 || s[ptr + 1] > i) return 0;
    }
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> k;
    if (k == 1) {
        cout << "0\n";
        return 0;
    }
    cin >> a >> b;
    int l = k - 1, r = m;
    if (!ok(m)) {
        cout << "-1\n";
        return 0;
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (!ok(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";

    return 0;

}
