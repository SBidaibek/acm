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

    forn(it, 1, 1) {
    srand(it);
    bool x = 0;
    string a, b;
//    forn(i, 1, 100) a.pb('a' + rand() % 2);
//    forn(i, 1, 5) b.pb('a' + rand() % 2);
    //cerr << a << " " << b << "\n";
    cin >> a >> b;
    int ak = 1, bk = 1;
    forn(i, 1, a.size() - 1) ak += (a[i] != a[i - 1]);
    forn(i, 1, b.size() - 1) bk += (b[i] != b[i - 1]);
    if (ak < bk)
        swap(ak, bk), swap(a, b), x = 1;
    int best = ak - 1;
    if (ak == bk)
        {if (a[0] == b[0]) ++best;}
    int at = 0;
    cerr << best << " " << at << "\n";
    forn(i, 1, ak - 1) {
        int cai = (a[0] == 'b') ^ (i % 2 == 0);
        int cb1 = (b[0] == 'b');
        int nak = ak - i;
        int nbk = bk + i - 1;
        int cur = max(nak, nbk);
        if (nak == nbk) {
            {if (a[0] == (cai ^ 1) + 'a') ++cur;}
        }
        if (best > cur)
            best = cur, at = i;
    }
    pii save = {-1, -1};
    if (at != 0) {
        int cnt = 1;
        forn(i, 1, a.size() - 1) {
            if (a[i] == a[i - 1]) continue;
            ++cnt;
            if (cnt > at) {
                int cai = (a[0] == 'b') ^ (at % 2 == 0);
                int cb1 = (b[0] == 'b');
                if (cai == cb1) {
                    save = {i, 0};
                    if (x) swap(save.F, save.S);
                    b.insert(0, a.substr(0, i));
                    a.erase(0, i);
                }
                else {
                    int k = 0;
                    while (k < b.size() && b[k] == b[0]) ++k;
                    save = {i, k};
                    if (x) swap(save.F, save.S);
                    string a1 = a.substr(0, i), a2 = a.substr(i);
                    string b1 = b.substr(0, k), b2 = b.substr(k);
                    a = b1 + a2;
                    b = a1 + b2;
                }
                break;
            }
        }
    }
    cerr << best << " " << at << "\n";
    cerr << a << " "<< b << "\n";

    vector <pii> a1 = solve(a, b, x ^ 0);
    vector <pii> a2 = solve(b, a, x ^ 1);
    vector <pii> ans = a1.size() < a2.size() ? a1 : a2;
    if (save.F != -1) ans.insert(ans.begin(), save);

    cout << ans.size() << "\n";
    assert(best == ans.size());
    for (auto p : ans)
        cout << p.F << " " << p.S << "\n";
    }

    return 0;
}
