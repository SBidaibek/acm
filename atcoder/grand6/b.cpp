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

int n = 7;
int a[N];

int f() {
    vi v(8);
    forn(i, 1, 7)
        v[i] = a[i];
    forn(i, 1, n / 2) {
        vi t(v.size() - 2);
        //forn(i, 1, v.size() - 1) cerr << v[i] << " ";cerr << "\n";
        forn(j, 1, t.size() - 1)
            t[j] = v[j] + v[j + 1] + v[j + 2]
                - min(v[j], min(v[j + 1], v[j + 2])) - max(v[j], max(v[j + 1], v[j + 2]));
        v = t;
    }
    forn(i, 1, 7) cout << a[i] << " "; cout << ":" << v[1] << "\n";
    return v[1];
}

int u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    /*forn(i, 1, n) a[i] = i;
    do {
        f();
    } while (next_permutation(a + 1, a + 8));
*/
    int n, k;
    cin >> n >> k;
    if (k == 1 || k == 2 * n - 1)
        cout << "No\n";
    else {
        cout << "Yes\n";
        if (n == 2) {
            cout << "1\n2\n3\n";
            return 0;
        }
        a[n] = k;
        u[k] = 1;
        a[n - 1] = k - 1;
        u[k - 1] = 1;
        a[n + 1] = k + 1;
        u[k + 1] = 1;
        if (k > 2) {
            a[n - 2] = k - 2;
            u[k - 2] = 1;
        }
        if (k + 2 <= 2 * n - 1) {
            a[n + 2] = k + 2;
            u[k + 2] = 1;
        }
        int x = 1;
        forn(i, 1, 2 * n - 1) {
            if (a[i]) continue;
            while (x <= 2 * n - 1 && u[x]) ++x;
            a[i] = x++;
        }
        forn(i, 1, 2 * n - 1)
            cout << a[i] << "\n";
        //cerr << f() << "\n";
    }

    return 0;
}
