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

const int N = 5e4 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int to[N]

ll dfs(int x) {

}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n) {
        string s;
        cin >> s;
        int x = 0;
        for (auto c : s) {
            c -= 'a';
            if (to[x][c] == 0) to[x][c] = ++sz;
            x = to[x][c];
        }
    }
    cout << dfs(0) << "\n";

    return 0;
}
