#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, q;
int a[N];
int mn[N], mx[N];
int p[N], del[N];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    forn(i, 1, q)
        mn[i] = n + 1, mx[i] = 0;
    forn(i, 1, n + 1)
        p[i] = i;
    forn(i, 1, n) {
        cin >> a[i];
        if (a[i] != 0)
            mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = max(mx[a[i]], i);
    }


    for1(i, q, 1) {
        if (mn[i] == n + 1) {
            if (i < q) continue;
            bool ok = 0;
            forn(x, 1, n) {
                if (a[x] == 0) {
                    a[x] = i;
                    ok = 1;
                    break;
                }
            }
            if (!ok){
                cout << "NO\n";
                return 0;
            }
            continue;
        }
        for (int x = f(mn[i]); x <= n && x <= mx[i]; x = f(x)) {
            assert(!del[x]);
            del[x] = 1;
            if (a[x] == 0)
                a[x] = i;
            else
            if (a[x] < i) {
                cout << "NO\n";
                return 0;
            }
            p[x] = x + 1;
        }
    }
    forn(i, 1, n)
        if (a[i] == 0) a[i] = 1;
    cout << "YES\n";
    forn(i, 1, n)
        cout << a[i] << " ";

    return 0;
}
