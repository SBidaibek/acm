/*
 _    _    _______   _    _
| |  / /  |  _____| | |  / /
| | / /   | |       | | / /
| |/ /    | |_____  | |/ /
| |\ \    |  _____| | |\ \
| | \ \   | |       | | \ \
| |  \ \  | |_____  | |  \ \
|_|   \_\ |_______| |_|   \_\

*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair < ll, int > PLI;


#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define right(x) x << 1 | 1
#define left(x) x << 1
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mkp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define y1 kekekek

#define fname ""

const ll ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const ld eps = 1e-7;
const int N = 2e6 + 6;

string s, t;
char a[N], b[N];
int pa[N], pb[N], sa[N], sb[N];

int main() {
	ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("in", "r", stdin);

    cin >> s >> t;
    int n = sz(s), m = sz(t);
    forn(i, 0, n - 1) a[i + 1] = s[i];
    forn(i, 0, m - 1) b[i + 1] = t[i];

    forn(i, 1, n) {
        pa[i] = pa[i - 1] + (a[i] == 'B' || a[i] == 'C');
        if (a[i] == 'A') {
            sa[i] = sa[i - 1] + 1;
        }
        else {
            sa[i] = 0;
        }
    }

    forn(i, 1, m) {
        pb[i] = pb[i - 1] + (b[i] == 'B' || b[i] == 'C');
        if (b[i] == 'A') {
            sb[i] = sb[i - 1] + 1;
        }
        else {
            sb[i] = 0;
        }
    }

    int Q;
    cin >> Q;
    forn(i, 1, Q) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 = 1, r1 = n, l2 = 1, r2 = m;
        int cnta = pa[r1] - pa[l1 - 1];
        int cntb = pb[r2] - pb[l2 - 1];
        int sufa = sa[r1];
        int sufb = sb[r2];
        bool ans = 1;

        if (sufa < sufb) ans = 0;
        if (sufb % 3 != sufa % 3) cnta += 2;
        if (cnta % 2 != cntb % 2 || cnta > cntb) ans = 0;

        cout << ans;
    }
    cout << "\n";

	return 0;
}
