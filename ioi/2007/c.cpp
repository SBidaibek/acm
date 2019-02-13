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

int n;
pii a[N];
int s[N];

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mh = 0;
    forn(i, 1, n)
        cin >> a[i].S >> a[i].F, mh = max(mh, a[i].S);
    sort(a + 1, a + 1 + n);
    forn(i, 1, n)
        c[1]++, c[a[i].S + 1]--, s[i] = 1;
    forn(i, 1, mh)
        c[i] += c[i - 1];

    set <int> st;
    forn(i, 1, n)
        if (a[i].F < a[i].S) st.insert(i);
    while (st.size()) {
        int chg = 0;
        vi del;
        for (auto i : st) {
            if (r + a[i].   F - 1 == a[i].S) {
                del.pb(i);
                continue;
            }
            if (c[r + a[i].F] > c[r + a[i].F - 1])
        }
        for (auto i : del)
            st.erase(i);
        if (!chg) break;
    }
    /*set <int> st;
    forn(i, 1, n)
        if (a[i].F < a[i].S) st.insert(i);
    forn(r, 1, mh) {
        if (r > 1) assert(c[r] <= c[r - 1]);
        vi del;
        for (auto i : st) {
            if (r + a[i].F - 1 == a[i].S) {
                del.pb(i);
                continue;
            }
            if (c[r + a[i].F] > c[r + a[i].F - 1])
        }
        for (auto i : del)
            st.erase(i);
    }*/

    return 0;
}
