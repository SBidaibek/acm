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

const int N = 3e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s[N];
vi v[N];
int val[N][N], h, w;
int ans[N][N];

bool can(int x, int r, int c) {
    for (auto p : v[x])
        if (val[r + p.x - 1][c + p.y - 1]) return 0;
    return 1;
}



int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int h = 0, w = 0;
    forn(i, 1, n) {
        cin >> s[i];
        v[i].resize(s[i] + 1);
        forn(j, 1, s[i]) {
            cin >> v[i][j].x >> v[i][j].y;
            h = max(v[i][j].y, h);
        }
    }

    forn(i, 1, n) {

    }

    return 0;
}
