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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

string slow(string s) {
    vi id(s.size());
    int ca = 0, cb = 0;
    forn(i, 0, s.size() - 1) {
        if (s[i] == 'a') id[i] = ca++;
        if (s[i] == 'b') id[i] = cb++;
    }
    string ans;
    forn(mask, 0, (1 << s.size()) - 1) {
        vi cnt(s.size() / 2);
        string cur;
        forn(i, 0, s.size() - 1)
            if (mask & (1 << i))
                ++cnt[id[i]], cur.pb(s[i]);
        bool shit = 0;
        for (auto x : cnt)
            if (x == 1) shit = 1;
        if (shit) continue;
        ans = max(ans, cur);
    }
    cerr << "opt = " << ans << "\n";
    return ans;
}

int n, a[N];
int bal[N];
string str[N], sx[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n * 2)
        bal[i] = 0, str[i] = sx[i] = "";
    string given;
    int ga = n, gb = n;
    forn(i, 1, n * 2) {
        char c;
//        c = rand() % 2 + 'a';
//        if (ga == 0) c = 'b';
//        if (gb == 0) c = 'a';
//        if (c == 'a') --ga;
//        if (c == 'b') --gb;
        cin >> c;
        given.pb(c);
        a[i] = c - 'a';
    }

    vi p, s;
    int b = 0;
    p.pb(1);
    int lst = -1;
    forn(i, 1, n * 2) {
        bal[i] = bal[i - 1] + (a[i] ? 1 : -1);
        if (bal[i] == 0) {
            if (a[i] == 0) lst = s.size();
            s.pb(a[i] ? -1 : 1);
            p.pb(i + 1);
        }
    }

    string ans;
    forn(i, 0, p.size() - 2) {
        if (s[i] == 1) {
            string cans;
            string cur;
            for1(j, p[i + 1] - 1, p[i]) {
                cur = string(1, 'a' + a[j]) + cur;
                cans = max(cans, string(bal[j - 1], 'b') + cur);
            }
            str[i] = cans;
        }
        else {
            string cur;
            vi pa, pb;
            forn(j, p[i], p[i + 1] - 1) {
                if (!a[j]) pa.pb(j);
                if (a[j]) pb.pb(j);
            }
            int prv = 0;
            forn(i, 0, pa.size() - 1)
                if (pa[i] > prv)
                    cur = cur + "ab", prv = pb[i];
            str[i] = cur;
        }
    }
    for1(i, p.size() - 2, 0)
        sx[i] = max(sx[i + 1], str[i]);
    forn(i, 0, p.size() - 2)
        if (/*s[i] == 1 &&*/ str[i] == sx[i])
            ans = ans + str[i];
//    forn(i, 0, p.size() - 2)
//        if (i > lst && s[i] == -1)
//            ans = ans + str[i];
    cout << ans << "\n";

    return 0;
}
