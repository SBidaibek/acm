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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int i2c[] = {500, 1000, 1500, 2000, 2500, 3000};

int cost(int a, int b, int c) {
    assert(a <= b);
    forn(i, 0, 5) {
        if (i < 5 && a * (1 << (i + 1)) <= b) continue;
        return i2c[i] - (i2c[i] / 250 * c);
    }
}

int n;
int a[N][6], solved[6], kek[6];

int main() {

    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    forn(i, 1, n) {
        forn(j, 1, 5) {
            cin >> a[i][j];
            if (a[i][j] != -1) ++solved[j];
        }
    }

    forn(pc, n, n * 100) {
        int sa = 0, sb = 0;
        forn(j, 1, 5) {
            if (a[1][j] == -1 || a[2][j] == -1) {
                if (a[1][j] == -1) sb += cost(solved[j], pc, a[2][j]);
                if (a[2][j] == -1) sa += cost(solved[j], pc, a[1][j]);
            }
            else {
                if (a[1][j] < a[2][j]) {
                    sa += cost(solved[j], pc, a[1][j]);
                    sb += cost(solved[j], pc, a[2][j]);
                }
                else {
                    sa += cost(solved[j] + (pc - n), pc, a[1][j]);
                    sb += cost(solved[j] + (pc - n), pc, a[2][j]);
                }
            }
        }
        if (sa > sb) {
            cout << (pc - n) << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}
