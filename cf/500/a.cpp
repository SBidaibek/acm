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
    int ak = 1, bk = 1;
    forn(i, 1, a.size() - 1) ak += (a[i] != a[i - 1]);
    forn(i, 1, b.size() - 1) bk += (b[i] != b[i - 1]);
    int best = max(ak, bk) - 1 + (b[0] == 'a');
    int at = 0;
    forn(i, 1, ak) {
        int cai = (a[0] == 'b') ^ (i % 2 == 0);
        int cb1 = (b[0] == 'b');
        int nak = ak - i;
        int nbk = bk + i - (cai == cb1);
        if (best > max(nak, nbk) - 1 + (a[0] == 'a'))
            best = max(nak, nbk) - 1 + (a[0] == 'a'), at = i;
    }
    forn(i, 1, bk) {
        int ca1 = (a[0] == 'b');
        int cbi = (b[0] == 'b') ^ (i % 2 == 0);
        int nak = ak + i - (ca1 == cbi);
        int nbk = bk + i;
        if (best > max(nak, nbk) - 1 + ('a' + cbi ==
            best = max(nak, nbk) - 1 + (a[0] == 'a'), at = -i;
    }

    cerr << best << " " << at << "\n";
    if (at != 0) {
        if (at > 0) {
            int cnt = 1;
            forn(i, 1, a.size() - 1) {
                if (a[i] == a[i - 1]) continue;
                ++cnt;
                if (cnt > at) {
                    pii toans = {i, 0};
                    if (x) swap(toans.F, toans.S);
                    ans.pb(toans);
                    b.insert(0, a.substr(0, i));
                    a.erase(0, i);
                    break;
                }
            }
        }
        else {
            at *= -1;
            int cnt = 1;
            forn(i, 1, b.size() - 1) {
                if (b[i] == b[i - 1]) continue;
                ++cnt;
                if (cnt > at) {
                    pii toans = {0, i};
                    if (x) swap(toans.F, toans.S);
                    ans.pb(toans);
                    a.insert(0, b.substr(0, i));
                    b.erase(0, i);
                    break;
                }
            }
        }
    }
    cerr << best << " " << at << "\n";
    cerr << a << " "<< b << "\n";

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
