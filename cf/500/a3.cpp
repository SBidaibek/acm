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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

vector <pii> solve(string a, string b, bool x) {
    vector <pii> ans;
    while (a.size() || b.size()) {
        while (a.size() && a.back() == 'a') a.pop_back();
        while (b.size() && b.back() == 'b') b.pop_back();
        if (!a.size() && !b.size()) break;
        pii toans = {a.size(), b.size()};
        if (x) swap(toans.F, toans.S);
        ans.pb(toans);
        swap(a, b);
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector <pii> a1 = solve(a, b, 0);
    vector <pii> a2 = solve(b, a, 1);
    vector <pii> ans = a1.size() < a2.size() ? a1 : a2;

    cout << ans.size() << "\n";
    for (auto p : ans)
        cout << p.F << " " << p.S << "\n";

    return 0;
}
