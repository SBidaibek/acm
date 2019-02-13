#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <unsigned long long, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int P = 31;

ostream & operator << (ostream &out, pii p) {
    return out << "(" << p.F << " " << p.S << ")";
}

pii pwr[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pwr[0] = {1, 1};
    forn(i, 1, N - 1)
        pwr[i].F = pwr[i - 1].F * P, pwr[i].S = pwr[i - 1].S * P % B;

    string s, t;
    cin >> s >> t;
    int a = 0, b = s.size();
    for (auto c : s)
        if (c == '0') ++a, --b;
    if (s[0] == '1') {
        swap(a, b);
        for (auto &c : s)
            c = ((c - '0') ^ 1) + '0';
    }
    int n = t.size();
    vector <pii> h(n + 1);
    for (auto &c : t)
        c = c - 'a' + 1;
    h[1] = {t[0], t[0]};
    forn(i, 2, n) {
        h[i].F = (h[i - 1].F * P + t[i - 1]);
        h[i].S = (h[i - 1].S * P + t[i - 1]) % B;
    }

    int ans = 0;
    forn(r1, 1, n / a) {
        if ((n - a * r1) % b != 0) continue;
        int r2 = (n - a * r1) / b;
        if (r1 == 0 || r2 == 0) continue;
        pii h1 = {-1, -1}, h2 = {-1, -1};
        int ptr = 1;
        bool ok = 1;
        for (auto c : s) {
            int len = (c == '0' ? r1 : r2);
            pii ch = pii(
                h[ptr + len - 1].F - h[ptr - 1].F * pwr[len].F,
                (h[ptr + len - 1].S - h[ptr - 1].S * pwr[len].S % B + B) % B
            );
            ptr += len;
            if (c == '0') {
                if (h1.F == -1)
                    h1 = ch;
                else
                    if (h1 != ch) {
                        ok = 0;
                        break;
                    }
            }
            else {
                if (h2.F == -1)
                    h2 = ch;
                else
                    if (h2 != ch) {
                        ok = 0;
                        break;
                    }
            }
        }
        //cerr << r1 << " "<< r2 << "\n";
        if (h1.F == -1 || h2.F == -1 || h1 == h2) ok = 0;
        ans += ok;
    }
    cout << ans << "\n";

    return 0;
}

