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

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
int z[5][5], a[N][N];
bitset <N> b[N];
int ans[N][N];
int cnt[N], ca[N];

bool check(int K) {
    if (K <= 2) {
        forn(i, 1, n)
            forn(j, 1, n)
                b[i][j] = ans[i][j];
        forn(i, 1, n)
            forn(j, i + 1, n)
                if (ca[i] - ans[i][j] && ca[j] - ans[i][j] && (b[i] ^ b[j]).count() - ans[i][j] * 2) return 0;
        return 1;
    }
    if (K <= 4) {
        forn(i, 1, n)
            if (ca[i] > 1) return 0;
        return 1;
    }
    if (K <= 6) {
        forn(i, 1, n)
            if (ca[i] > 2) return 0;
        return 1;
    }
    forn(i, 1, n)
        forn(j, 1, n)
            b[i][j] = ans[i][j];
    if (K <= 8) {
        forn(i, 1, n) {
            int shit = 0;
            forn(j, 1, n)
                if (ans[i][j] && (b[i] & b[j]).count()) shit = 1;
            if (shit) return 0;
        }
        return 1;
    }
    forn(i, 1, n) {
        int shit = 0;
        forn(j, 1, n)
            if (ans[i][j] && (b[i] & b[j]).count()) shit = 1;
        if (ca[i] > 2 && shit) return 0;
    }
    return 1;
}

void solve_base(int K) {
    char inf[20], ouf[20];
    sprintf(ouf, "%02d.out", K);
    freopen(ouf, "r", stdin);
    cin >> n;
    forn(i, 1, n)
        forn(j, 1, n)
            cin >> a[i][j];
    freopen(ouf, "w", stdout);
    cout << "#FILE forbidden " << K << "\n";
    cout << n << "\n";
    forn(i, 1, n)
        forn(j, 1, n)
            cout << a[i][j] << " \n"[j == n];
}

int main() {
    #ifdef black
    #endif // black

    //int K;
    //cin >> K;
    forn(K, 1, 11) {
        cerr << "Generating test " << K << "\n";
        solve_base(K);
        cerr << "Finished test " << K << "\n";
    }

    return 0;
}
