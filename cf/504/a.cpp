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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
pii pc[N];
ll a[N];
vector <pii> v[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool  ok = 0;
    for (auto c : s) ok |= (c == '*');
    if (!ok) {
        cout << (s == t ? "YES" : "NO") << "\n";
        return 0;
    }
    if (m < n - 1) {
        cout << "NO\n";
        return 0;
    }
    forn(i, 0, s.size() - 1) {
        if (s[i] == '*') break;
        if (s[i] != t[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    forn(i, 1, s.size()) {
        if (s[n - i] == '*') break;
        if (s[n - i] != t[m - i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
