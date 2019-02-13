#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map <int, int> head, tail;
    int cor = 0;
    forn(i, 1, n) {
        string s;
        cin >> s;
        int bal = 0, mn = 0;
        forn(i, 0, s.size() - 1) {
            int c = (s[i] == '(' ? +1 : -1);
            bal += c;
            mn = min(bal, mn);
        }
        if (bal == 0) {
            if (mn == 0) ++cor;
        }
        if (bal > 0) {
            if (mn == 0) head[bal]++;
        }
        if (bal < 0)
            if (mn >= bal) tail[-bal]++;
    }
    int ans = cor / 2;
    for (auto p : head)
        ans += min(p.S, tail[p.F]);

    cout << ans << "\n";

    return 0;
}
