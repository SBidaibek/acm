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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k;
int a[N], b[N];
int p[N];

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

void pre(int x, vi &v) {
    if (!x) return;
    v.pb(x);
    pre(a[x], v);
    pre(b[x], v);
}

void post(int x, vi &v) {
    if (!x) return;
    post(a[x], v);
    post(b[x], v);
    v.pb(x);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    forn(it, 1, tests) {
        cout << "Case #" << it << ": ";
        cin >> n >> k;
        forn(i, 1, n)
            cin >> a[i] >> b[i];
        forn(i, 1, n) p[i] = i;
        vi pr, po;
        pre(1, pr);
        post(1, po);
        forn(i, 0, n - 1)
            p[f(pr[i])] = f(po[i]);
        vi v;
        forn(i, 1, n)
            v.pb(f(i));
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        if (v.size() < k)
            cout << "Impossible\n";
        else
            forn(i, 1, n)
                cout << (lower_bound(v.begin(), v.end(), f(i)) - v.begin()) % k + 1 << " \n"[i == n];
        forn(i, 0, n - 1)
            assert((lower_bound(v.begin(), v.end(), f(pr[i])) - v.begin()) % k
            == (lower_bound(v.begin(), v.end(), f(po[i])) - v.begin()) % k);
    }

    return 0;
}
