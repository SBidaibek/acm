#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ld a[N], b[N], p[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;
	forn(i, 1, n)
	    cin >> a[i] >> b[i];
	sort(a + 1, a + 1 + n, greater <ld> ());
	sort(b + 1, b + 1 + n, greater <ld> ());
	ld ans = 0;
	forn(i, 1, n)
	    a[i] = a[i - 1] + a[i], b[i] = b[i - 1] + b[i];
	forn(i, 1, n)
	    p[i] = max(p[i - 1], b[i] - i);
	int ptr = 1;
	forn(i, 1, n) {
	    for (; ptr <= n && b[ptr] <= a[i]; ++ptr);
	    if (ptr <= n)
	        ans = max(ans, a[i] - i - ptr);
	    ans = max(ans, p[ptr - 1] - i);
	}
	cout << fixed << setprecision(4) << ans << "\n";

    return 0;
}
