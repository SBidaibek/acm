#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 4e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi l(n + 1), r(n + 1);
    forn(i, 1, n)
        cin >> l[i];
    forn(i, 1, n)
        cin >> r[i];
    vi del(n + 1), a(n + 1);
    int k = 1;
    vi sl = l, sr = r;
    forn(it, 1, n) {
        vi v;
        forn(i, 1, n)
            if (l[i] + r[i] == 0 && !del[i])
                v.pb(i);
        if (!v.size()) break;
        for (auto i : v)
            del[i] = 1, a[i] = k;
        ++k;
        int pr = -1;
        forn(i, 1, n) {
            while (pr < (int)v.size() - 1 && v[pr + 1] < i) ++pr;
            if (!del[i] && l[i] + r[i] > 0)
                l[i] -= pr + 1, r[i] -= (v.size() - (pr + 1));
        }
    }
    forn(i, 1, n)
        a[i] = k - a[i];
    forn(i, 1, n) {
        int cl = 0, cr = 0;;
        forn(j, 1, i - 1) if (a[j] > a[i]) ++cl;
        forn(j, i + 1, n) if (a[j] > a[i]) ++cr;
        //cerr << l[i] << " " << r[i] << "\n";
        //cerr << sl[i] << " " << cl << " " << sr[i] << " " << cr << "\n";
        if (l[i] || r[i] || cl != sl[i] || cr != sr[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    forn(i, 1, n)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}

