#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

void yes() {
    cout << "YES\n";
    exit(0);
}

int n, m;
char a[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    pii s, t;
    forn(i, 1, n) {
        forn(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S') s = {i, j};
            if (a[i][j] == 'T') t = {i, j};
        }
    }
    if (s.s > t.s) swap(s, t);
    int l = s.s, r = t.s;
    while (l < m && a[s.f][l + 1] != '*') ++l;
    while (r > 1 && a[t.f][r - 1] != '*') --r;
    if (l >= r) {
        if (r < s.s) {
            int x = s.s;
            while (x >= 1 && a[s.f][x] != '*') --x;
            r = max(r, x + 1);
        }
        if (l > t.s) {
            int x = t.s;
            while (x <= m && a[t.f][x] != '*') ++x;
            l = min(l, x - 1);
        }
        //cerr << l << " " << r << "\n";
        forn(j, r, l) {
            bool f = 0;
            forn(i, min(s.f, t.f), max(s.f, t.f))
                f |= (a[i][j] == '*');
            if (!f) yes();
        }
    }

    if (s.f > t.f) swap(s, t);
    l = s.f, r = t.f;
    while (l < n && a[l + 1][s.s] != '*') ++l;
    while (r > 1 && a[r - 1][t.s] != '*') --r;
    if (l >= r) {
        while (r < s.f && a[r][s.s] == '*') ++r;
        while (l > t.f && a[l][t.s] == '*') --l;
        //cerr << l << " " << r << "\n";
        if (r < s.f) {
            int x = s.f;
            while (x >= 1 && a[x][s.s] != '*') --x;
            r = max(r, x + 1);
        }
        if (l > t.f) {
            int x = t.f;
            while (x <= n && a[x][t.s] != '*') ++x;
            l = min(l, x - 1);
        }
        forn(i, r, l) {
            bool f = 0;
            forn(j, min(s.s, t.s), max(s.s, t.s))
                f |= (a[i][j] == '*');
            cerr << i << "\n";
            if (!f) yes();
        }
    }

    cout << "NO\n";

    return 0;
}
