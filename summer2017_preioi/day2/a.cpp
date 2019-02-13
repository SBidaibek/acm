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
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, q;
int a[N], b[N], ans[N];
pii c[N];
int v[N], sz;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //cin >> n >> q;
    scanf("%d%d", &n, &q);
    forn(i, 1, n)
        scanf("%d", &a[i]);
        //cin >> a[i];
    forn(i, 1, q) {
        scanf("%d", &b[i]);
        //cin >> b[i];
        c[i] = {b[i], i};
        ans[i] = 1;
    }
    sort(c + 1, c + 1 + q);

    a[0] = INF;
    forn(i, 1, n) {
        while (a[v[sz]] <= a[i]) --sz;
        v[++sz] = i;
        int p = sz;
        forn(j, 1, q) {
            //if (c[j].F <= a[v[sz]]) break;
            while (p > 1 && a[v[p - 1]] <= c[j].F) --p;
            ans[c[j].S] = max(ans[c[j].S], sz - p + 1);
        }
    }
    forn(i, 1, q)
        cout << ans[i] << " ";

    return 0;
}
