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

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;

vector <vi> solve(vector <pii> a) {
    vector <vi> ans;

}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector <pii> a(m + 1);
    vector <pii> b(m + 1);
    forn(i, 1, m)
        cin >> a[i].x >> a[i].y;
    forn(i, 1, m)
        cin >> b[i].x >> b[i].y;

    vector <vi> ans = solve(a);
    vector <vi> t = solve(b);
    reverse(t.begin(), t.end());
    for (auto p : t) ans.pb(p);
    cout << ans.size() << "\n";
    for (auto p : ans) {
        for (auto x : p) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

