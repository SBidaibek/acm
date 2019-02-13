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

int n, k;
int a[N], b[N], c[N], l[N], f[N];
int lst[N], p[N], nxt[N], prv[N], ptr[N], cnt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, k)
        cin >> l[i];
    ll s = 0;
    forn(i, 1, k) {
        cin >> c[i];
        b[c[i]] = l[i];
        s += l[i];
    }
    forn(i, 1, n) {
        cin >> a[i];
        nxt[lst[a[i]]] = i;
        prv[i] = lst[a[i]];
        if (lst[a[i]] == 0) f[a[i]] = i;
        lst[a[i]] = i;
    }
    set <int> l, r;
    ll ans = 0;
    forn(i, 1, n) {
        if (b[a[i]] > 0) {
            if (++cnt[a[i]] >= b[a[i]]) {
                if (ptr[a[i]]) r.erase(ptr[a[i]]);
                if (prv[ptr[a[i]]]) l.erase(prv[ptr[a[i]]]);
                ptr[a[i]] = ptr[a[i]] ? nxt[ptr[a[i]]] : f[a[i]];
                r.insert(ptr[a[i]]);
                if (prv[ptr[a[i]]]) l.insert(prv[ptr[a[i]]]);
            }
        }/*
        cerr << i << ":\n";
        cerr << "L: ";for (auto x : l) cerr << x << " ";cerr << "\n";
        cerr << "R: ";for (auto x : r) cerr << x << " ";cerr << "\n";*/
        if (r.size() == k && *r.begin() > (l.size() ? *l.rbegin() : 0))
            ans += (i - *r.begin() + 1 == s);
    }
    cout << ans << "\n";

    return 0;
}
