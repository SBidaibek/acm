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

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, sz;

int k = (1 << 17);
map <int, int> f[N];

void upd(int x, int v, int d) {
    for (; v < k; v |= v + 1) f[x][v] += d;
}

int mex(int x) {
    if (f[x].count(0) == 0) return 0;
    int l = 0, r = k - 1, c = 0, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (f[x][m] == m + 1 - c)
            l = m + 1, c += f[x][m];
        else
            r = m;
    }
    return l;
}

map <string, int> s2i;

int crt(int x) {
    int ans = mex(x);
    upd(x, ans, +1);
    return ans;
}

int id(string s) {
    return (s2i.count(s) ? s2i[s] : s2i[s] = ++sz);
}

void del(string s) {
    int v = 0;
    if (s.back() == ')') {
        vi t;
        for (s.pop_back(); !isalpha(s.back()); s.pop_back())
            if (isdigit(s.back())) t.pb(s.back() - '0');
        reverse(t.begin(), t.end());
        for (auto d : t)
            v = v * 10 + d;
    }
    int x = id(s);
    upd(x, v, -1);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n) {
        string tp, s;
        cin >> tp >> s;
        if (tp[0] == 'c') {
            int ans = crt(id(s));
            cout << "+ " << s;
            if (ans) cout << "(" << ans << ")";
            cout << "\n";
        }
        if (tp[0] == 'd') {
            del(s);
            cout << "- " << s << "\n";
        }
        if (tp[0] == 'r') {
            del(s);
            cout << "r " << s << " -> ";
            cin >> s;
            int ans = crt(id(s));
            cout << s;
            if (ans) cout << "(" << ans << ")";
            cout << "\n";
        }
    }

    return 0;
}
