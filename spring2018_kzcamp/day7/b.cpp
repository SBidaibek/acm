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
typedef vector <int> vi;

const int N = 6e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

int n;
pii a[N];
int c[N][4];
vector <pii> v[N};

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        cin >> a[i].x;
        char c;
        cin >> c;
        a[i].y = (c == 'G' ? 1 : (c == 'C' ? 2 : 3));
    }
    sort(a + 1, a + 1 + n);
    forn(j, 1, 3)
        forn(i, 1, n) c[i][j] = c[i - 1][j] + (a[i].y == j);
    int ptr = 1;
    forn(l, 1, n) {
        while (ptr < n && a[ptr + 1].x < a[l].x * 2) ++ptr;
        v[c[ptr][1] - c[l - 1][1]].pb({c[ptr][2] - c[l - 1][2], c[ptr][3] - c[l - 1][3]});
    }
    map <int, int> mp;
    mp[-1] = INF;
    mp[INF] = -1;
    for1(i, n, 0) {
        for (auto p : v[i]) {
            auto it = mp.lower_bound(p.F);
            if (it -> S >= p.S) continue;
            if (it -> F > p.F) --it;
            vi del;
            for (; it -> S <= p.S; --it)
                del.pb(it -> F);
            for (auto x : del) mp.erase(x);
            auto it1 = mp.lower_bound(p.F);
            auto it2 = it1; --it2;
            ans += (p.F - it2.F) * (p.S - it1.S);
        }
    }
    cout << ans - 1 << "\n";

    return 0;
}

