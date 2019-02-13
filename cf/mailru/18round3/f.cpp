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

const int N = 2e6 + 10;
const ld INF = 1e18 + 9;
const int B = 1e9 + 7;

ld d[101][101][1001];

ld pwr[101];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pwr[0] = 1;
    forn(i, 1, 100)
        pwr[i] = pwr[i - 1] / 0.9;

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        ld C, T;
        cin >> C >> T;
        vector <pii> tmp(n);
        forn(i, 1, n)
            cin >> tmp[i - 1].F >> tmp[i - 1].S;
        sort(tmp.begin(), tmp.end(), greater <pii> ());
        vi a(n + 1), p(n + 1);
        forn(i, 1, n)
            a[i] = tmp[i - 1].F, p[i] = tmp[i - 1].S;
        forn(k, 0, n) {
            forn(i, 0, n) {
                forn(w, 0, 10 * n) {
                    d[k][i][w] = INF;
                    if (k == 0) {
                        if (w == 0) d[k][i][w] = 0;
                        continue;
                    }
                    if (i == 0) continue;
                    if (w > 10 * k) continue;
                    if (i > 1)
                        d[k][i][w] = d[k][i - 1][w];
                    if (w >= p[i])
                        d[k][i][w] = min(d[k][i][w], d[k - 1][i - 1][w - p[i]] + a[i] * pwr[k - 1]);
                }
            }
        }
        int ans = 0;
        forn(w, 1, 10 * n) {
            ld O = INF;
            forn(k, 1, n)
                O = min(O, d[k][n][w]);
            if (O == INF) continue;
            //cerr << w << ": " << O << "\n";
            ld a = -1;
            ld b = T * C + 1;
            ld c = - O * C;
            ld d = b * b - 4 * a * c;
            if (d < 0) continue;
            ld s1 = (-b - sqrt(d)) / (2 * a);
            ld s2 = (-b + sqrt(d)) / (2 * a);
            if (s1 > s2) swap(s1, s2);
            if (s1 <= 1 && 1 <= s2)
                ans = max(ans, w);
        }
        cout << ans << "\n";
    }

    return 0;
}
