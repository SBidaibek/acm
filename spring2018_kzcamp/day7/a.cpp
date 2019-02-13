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
typedef vector <int> vi;

const int N = 6e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

int a, b, c, n;
int al[N], ar[N], ua[N], va[N];
int bl[N], br[N], ub[N], vb[N];
int t[N], on[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cin >> n;
    forn(i, 1, n)
        cin >> al[i] >> ar[i] >> bl[i] >> br[i] >> t[i];
    vi o;
    forn(i, 1, n) o.pb(i);
    sort(o.begin(), o.end(), [](int x, int y) {return t[x] > t[y];});
    ll ans = 0;
    ua[c] = 1;
    forn(i, 1, n)
        if (al[i] <= c && c <= ar[i])
            on[i] = 1;
    forn(i, 1, a)
        forn(j, 1, n)
            if (al[j] <= i && i <= ar[j] && on[j]) va[i] = max(va[i], t[j]);
    forn(i, 1, b)
        forn(j, 1, n)
            if (bl[j] <= i && i <= br[j] && on[j]) vb[i] = max(vb[i], t[j]);

    forn(it, 1, a + b - 1) {
        int mxa = -1;
        forn(i, 1, a)
            if (!ua[i] && (mxa == -1 || va[i] > va[mxa])) mxa = i;
        int mxb = -1;
        forn(i, 1, b)
            if (!ub[i] && (mxb == -1 || vb[i] > vb[mxb])) mxb = i;
        if (mxa > -1 && va[mxa] == 0) mxa = -1;
        if (mxb > -1 && vb[mxb] == 0) mxb = -1;
        if (mxa == -1 && mxb == -1) {
            cout << "-1\n";
            return 0;
        }
        if (mxa != -1 && (mxb == -1 || va[mxa] >= va[mxb])) {
            ua[mxa] = 1;
            ans += va[mxa];
            //cerr << "a " << mxa << "\n";
            forn(i, 1, n)
                if (al[i] <= mxa && mxa <= ar[i])
                    on[i] = 1;
        }
        else {
            ub[mxb] = 1;
            ans += vb[mxb];
            //cerr << "b " << mxb << "\n";
            forn(i, 1, n)
                if (bl[i] <= mxb && mxb <= br[i])
                    on[i] = 1;
        }
        forn(i, 1, a)
            forn(j, 1, n)
                if (al[j] <= i && i <= ar[j] && on[j]) va[i] = max(va[i], t[j]);
        forn(i, 1, b)
            forn(j, 1, n)
                if (bl[j] <= i && i <= br[j] && on[j]) vb[i] = max(vb[i], t[j]);
    }
    cout << ans << "\n";

    return 0;
}

