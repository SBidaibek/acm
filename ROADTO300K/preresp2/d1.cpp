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

const int N = 6e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, len;
int a[N];
int d[N][2];
ll c[N][2];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> len;
    int mx = 0;
    forn(i, 1, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    mx *= 2;
    d[0][1] = 0;
    c[0][1] = 1;
    forn(i, 1, n) {
        int z = (i - 1) % 2;
        forn(j, 0, mx) {
            d[j][z] = d[j][z ^ 1];
            c[j][z] = c[j][z ^ 1];

            if (d[j][z] == d[j ^ a[i]][z ^ 1] + a[i] && c[j ^ a[i]][z ^ 1])
                c[j][z] = (c[j][z] + 2 * c[j ^ a[i]][z ^ 1]) % B;
            if (d[j][z] < d[j ^ a[i]][z ^ 1] + a[i] && c[j ^ a[i]][z ^ 1])
                d[j][z] = d[j ^ a[i]][z ^ 1] + a[i],
                c[j][z] = (2 * c[j ^ a[i]][z ^ 1]) % B;
        }
        cerr << d[0][z] << " " << c[0][z] << "\n";
    }
    cerr << "-\n";
    forn(l, 1, n - len + 1) {
        forn(i, 0, mx)
            forn(k, 0, 1)
                d[i][k] = c[i][k] = 0;
        d[0][1] = 0;
        c[0][1] = 1;
        forn(i, l, l + len - 1) {
            int z = (i - l) % 2;
            forn(j, 0, mx) {
                d[j][z] = d[j][z ^ 1];
                c[j][z] = c[j][z ^ 1];

                if (d[j][z] == d[j ^ a[i]][z ^ 1] + a[i] && c[j ^ a[i]][z ^ 1])
                    c[j][z] = (c[j][z] + 2 * c[j ^ a[i]][z ^ 1]) % B;
                if (d[j][z] < d[j ^ a[i]][z ^ 1] + a[i] && c[j ^ a[i]][z ^ 1])
                    d[j][z] = d[j ^ a[i]][z ^ 1] + a[i],
                    c[j][z] = (2 * c[j ^ a[i]][z ^ 1]) % B;
            }
        }
        int z = (len - 1) % 2;
        cout << d[0][z] << " " << c[0][z] << "\n";
    }

    return 0;
}

