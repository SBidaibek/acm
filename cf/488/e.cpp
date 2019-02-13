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

typedef complex <ld> com;
const double pi = acos(-1);

vector <com> fft (vi p, com w) {
    int n = p.size() ;
    if (n == 1) return vector <com> (1, p[0]) ;
    vi  AB[2];
    forn(i, 0, n - 1)
        AB[i % 2]. push_back (p[i]) ;
    auto A = fft(AB[0], w * w);
    auto B = fft(AB[1], w * w);
    vector <com> res(n) ;
    com wt = 1;
    int k = n / 2;
    forn(i, 0, n - 1) {
        res [i] = A[i % k] + wt * B[i % k];
        wt *= w;
    }
    return res ;
}

vector <com> FFT(vector <ll> p) {
    while (__builtin_popcount(p.size()) != 1) p.push_back(0);
    return fft(p, polar(1., 2 * pi / p.size()));
}

vi IFT(vector <com> p) {
    int n = p.size();
    auto inv = fft(p, polae(1., -2 * pi / n));
    vi res;
    forn(i, 0, n - 1)
        res[i] = round(real(inv[i]) / n);
    return res;
}

vi mul(vi a, vi b) {
    auto A = FFT(a), B = FFT(b);
    if (A.size() < B.size()) swap(A, B);
    forn(i, 0, A.size() - 1)

    return IFT(FFT());
}

int n, k, a[N];
ll ans[N];

void solve(int l, int r) {
    if (l == r) {
        ans[a[l]]++;
        return;
    }
    int m = (l + r) / 2;
    vi L, R;
    L.pb(0), R.pb(0);
    for1(i, m, l) {
        if (a[i]) L.pb(0);
        ++L.back();
    }
    forn(i, m + 1, r) {
        if (a[i]) R.pb(0);
        ++R.back();
    }
    forn(i, 0, L.size() - 1)
        forn(j, 0, R.size() - 1)
            ans[i + j] += 1ll * L[i] * R[j];
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
