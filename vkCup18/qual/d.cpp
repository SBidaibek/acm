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
const int N = 2e5 + 6;

int n, A, B, a[N], b[N], last[N], prv[N], nxt[N], d[N];
bool u[N];

int main() {
	ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    cin >> n >> A >> B;
    forn(i, 1, n - 1) {
        cin >> b[i];
    }

    forn(i, 1, n) {
        cin >> a[i];
    }
    forn(i, 1, n - 1) {
        last[a[i]] = i;
        prv[i] = last[b[i]];
    }
    forn(i, 1, 100010) {
        last[i] = n + 1;
    }
    for1(i, n - 1, 1) {
        last[a[i + 1]] = i + 1;
        nxt[i] = last[b[i]];
    }

    u[a[A]] = 1;
    int l = A, r = A;
    while (1) {
        bool ok = 0;
        while (l > 1 && u[b[l - 1]]) {
            --l;
            u[a[l]] = 1;
            ok = 1;
        }
        while (r < n && u[b[r]]) {
            ++r;
            u[a[r]] = 1;
            ok = 1;
        }
        if (!ok) break;
    }

    if (B < l || r < B) {
        cout << "-1\n";
        return 0;
    }

    l = A, r = A;
    int mn = A, mx = A;
    while (B < l || r < B) {
        while (l > 1 && r >= nxt[l - 1]) {
            --l;
            if (nxt[l] > mx) {
                mx = nxt[l];
                d[l] = d[mx] + (mx - l);
            }
            else {
                d[l] = d[l + 1] + 1;
            }
        }
        while (r < n && l <= prv[r]) {
            if (prv[r] < mn) {
                mn = prv[r];
                d[r + 1] = d[mn] + (r - mn + 1);
            }
            else {
                d[r + 1] = d[r] + 1;
            }
            ++r;
        }
    }

    cout << d[B] << "\n";

	return 0;
}
