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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

typedef complex <ld> base;
const double PI = acos(-1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;

	vector<base> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft (a0, invert);
	fft (a1, invert);

	double ang = 2*PI/n * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
}

void multiply (const vi & a, const vi & b, vi & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

int n, k, a[N];
ll ans[N];

void solve(int l, int r) {
    if (l == r) {
        ans[a[l]]++;
        return;
    }
    int m = (l + r) / 2;
    vi L, R, T;
    L.pb(0), R.pb(0);
    for1(i, m, l) {
        if (a[i]) L.pb(0);
        ++L.back();
    }
    forn(i, m + 1, r) {
        if (a[i]) R.pb(0);
        ++R.back();
    }
    multiply(L, R, T);
    //forn(i, 0, L.size() - 1)
    //    forn(j, 0, R.size() - 1)
    //        ans[i + j] += 1ll * L[i] * R[j];
    forn(i, 0, T.size() - 1)
        ans[i] += T[i];
    solve(l, m);
    solve(m + 1, r);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    forn(i, 1, n) {
        int x;
        cin >> x;
        a[i] = (x < k);
    }
    solve(1, n);
    forn(i, 0, n)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
