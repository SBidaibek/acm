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

const int N = 2e3 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n, m;
int f[N], t[N], p[N], r[N];
int b[N];

int fp(int x) {
    return p[x] == x ? x : p[x] = fp(p[x]);
}

void u(int a, int b) {
    a = fp(a), b = fp(b);
    if (a == b) return;
    if (r[a] > r[b]) swap(a, b);
    p[b] = a;
    if (r[a] == r[b]) ++r[a];
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, m)
        cin >> f[i] >> t[i];
    int ans = 0;
    forn(i, 1, n) {
        forn(j, i + 1, n) {
            forn(k, 1, n) {
                p[k] = (k == i || k == j) ? i : k;
                r[k] = 1;
                b[k] = (k == i || k == j);
            }
            bool shit = 0;
            forn(e, 1, m) {
                if (fp(f[e]) != fp(t[e]))
                    u(f[e], t[e]);
                else
                    if (b[f[e]]|| b[t[e]])
                        shit = 1;
                if (shit) break;
            }
            if (!shit) ++ans;
            if (!shit) cerr << i << " " << j << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}
