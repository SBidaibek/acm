#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;



int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T:
    cin >> T;
    forn(_, 1, T) {
        cin >> n;
        vi c(3), v;
        forn(i, 1, n) {
            cin >> a[i];
            ++c[a[i]];
        }
        if (c[0] == 0 || c[1] == 0) {
            cout << "0\n";
            continue;
        }
        if (c[2] == 0) {
            cout << "-1\n";
            continue;
        }
        c.clear();
        a[0] = -1;
        forn(i, 1, n) {
            if (a[i] != a[i - 1])
                v.pb(a[i]), c.pb(1);
            else
                ++c.back();
        }
        int cur = 0, ans = 0;
        if (v.back() == 2) {
            cur += c.back();
            c.pop_back();
            v.pop_back();
        }
        if (a[0] == 2) {
            cur += c[0];
            forn(i, 1, v.size() - 1)
                v[i - 1] = v[i], c[i - 1] = c[i];
        }
        forn(i, 0, v.size() - 1)
            if (v[i] == 2) cur += c[i] - 1;
        forn(i, 0, v.size() - 1) {
            if (v[i] == 2) continue;
            int j = i;
            while (j < v.size() - 1 && v[j + 1] != 2) ++j;
            if (i == j) continue;

        }
    }

    return 0;
}
