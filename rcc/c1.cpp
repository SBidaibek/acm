#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int f(vi &a) {
    int n = a.size() - 1;
    vi u(n + 1);
    int ans = 0;
    forn(i, 1, n) {
        if (u[i]) continue;
        ++ans;
        for (int x = i; !u[x]; x = a[x]) u[x] = 1;
    }
    return n - ans;
}

int main() {
    //freopen("in", "r", stdin);
    ios_base :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set <int> p, v;
        vi c;
        vi a(n + 1), u(n + 1);
        forn(i, 1, n) {
            cin >> a[i];
            if (a[i] == 0)
                p.insert(i);
            u[a[i]] = 1;
        }
        forn(i, 1, n)
            if (!u[i]) v.insert(i);
        for (auto x : v)
            if (a[x]) c.pb(x);
        forn(_, 0, c.size() - 1) {
            int x = c[_];
            int j = x;
            for (; a[j]; j = a[j]);
            u[x] = 1;
            if (p.size() > 1) {
                p.erase(j);
                int i = *p.begin();
                a[i] = x;
                if (u[i] == 0) c.pb(i);
                p.erase(p.begin());
                p.insert(j);
            }
            else {
                a[j] = x;
                p.erase(j);
            }
        }
        forn(i, 1, n)
            if (u[i]) v.erase(i);
        if (v.size()) {
            if (v.size() == 1) {
                int x = *v.begin();
                a[x] = x;
            }
            else {
                assert(p == v);
                int s = *v.begin();
                v.erase(v.begin());
                while (v.size()) {
                    int i = *p.begin();
                    int x = *v.begin();
                    p.erase(p.begin());
                    v.erase(v.begin());
                    a[i] = x;
                }
                a[*p.begin()] = s;
            }
        }
        cout << f(a) << "\n";
        forn(i, 1, n)
            cout << a[i] << " ";
        cout << "\n";
    }
}
