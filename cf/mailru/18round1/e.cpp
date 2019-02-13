#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e2 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

string s[N][N], target[N][N];

vector <vi> ans;

void move(int x1, int y1, int x2, int y2) {
    ans.pb({x1, y1, x2, y2});
    s[x2][y2].pb(s[x1][y1][0]);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n)
        forn(j, 1, n) {
            cin >> s[i][j];
            reverse(s[i][j].begin(), s[i][j].end());
        }
    forn(i, 1, n)
        forn(j, 1, n) {
            cin >> target[i][j];
            reverse(target[i][j].begin(), target[i][j].end());
        }
    forn(i, 2, n) {
        forn(j, 1, s[i][1].size())
            move(j, 1, j, 2);
        s[i][1].clear();
        forn(j, 1, s[1][i].size())
            move(1, j, 2, j);
        s[1][i].clear();
    }

    forn(i, 1, n) {
        forn(j, 1, n) {
            if ((i == 1) + (j == 1) == 1) continue;
            for (auto c : s[i][j]) {
                if (c == '1')
                    move(i, j, i, 1);
                else
                    move(i, j, 1, j);
            }
            s[i][j].clear();
        }
    }

    forn(i, 1, n)
        forn(j, 1, n)
            assert(s[i][j] == target[i][j]);
    cout << ans.size() << "\n";
    for (auto v : ans)
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";

    return 0;
}

