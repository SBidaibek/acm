#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, s;
pii a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    s *= 2;
    forn(i, 1, n)
        cin >> a[i].x >> a[i].y;

    forn(q, 1, n) {
        pii sav = a[q];
        forn(i, 1, n)
            a[i].x -= sav.x, a[i].y -= sav.y;
        forn(i, 1,  )
        forn(i, 1, n)
            a[i].x += sav.x, a[i].y += sav.y;
    }

    return 0;
}
