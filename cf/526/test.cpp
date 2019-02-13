#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

ld d[200][400];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed;
    cout << fixed;
    int shift = 110;
    int n = 100;
    d[0][shift] = 1;
    forn(i, 1, n) {
        //if (i >= 9)
         //   d[i][shift + -9] = d[i - 1][shift + -8] * 0.3;
        //if (i >= 10)
       //     d[i][shift + -10] = d[i - 1][shift + -10] + d[i - 1][shift + -9] * 0.3;
        forn(j, max(-i, -i), i)
            d[i][shift + j] = d[i - 1][shift + j - 1] * 0.7 + d[i - 1][shift + j + 1] * 0.3;
        cerr << i << ": ";
        ld prob = 0;
        forn(j, max(-10, -i), i){
            cerr << d[i][shift + j] << " "; prob += d[i][shift + j];}
        cout << "| " << prob;
        cerr << "\n";
    }
    ld ans = 0;
    forn(i, -n, n)
        ans += i * d[n][i + shift];
    cout << ans << "\n";

    return 0;
}
