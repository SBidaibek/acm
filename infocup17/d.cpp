#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 1e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

typedef vi bi;

bi operator - (bi a, bi b) {
    bi ans = a;
    forn(i, 0, b.size() - 1) {
        if (ans[i] < b[i])
            ans[i] += 10, --ans[i + 1];
        ans[i] -= b[i];
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    return ans;
}

bi operator + (bi a, bi b) {
    bi ans(max(a.size(), b.size()));
    int c = 0;
    forn(i, 0, ans.size() - 1) {
        ans[i] = c;
        if (i < a.size()) ans[i] += a[i];
        if (i < b.size()) ans[i] += b[i];
        c = ans[i] / 10;
        ans[i] %= 10;
    }
    for (; c; c /= 10) ans.pb(c % 10);
    return ans;
}

int n;
bi q[N];
int a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #else
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    forn(i, 1, n) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (auto c : s)
            q[i].pb(c - '0');
    }
    for1(i, n, 1)
        q[i] = q[i] - q[i - 1];
    set <PII> st;
    forn(i, 1, n) {
        bi x(1, 1);
        a[i] = 1;
        for (; st.size() && x != q[i]; st.erase(st.begin())) {
            int j = st.begin() -> S;
            x = x + q[j];
            ++a[i];
        }
        for (; st.size(); st.erase(st.begin())) {
            int j = st.begin() -> S;
            ++a[j];
        }
        forn(j, 1, i)
            st.insert({a[j], j});
    }
    forn(i, 1, n)
        cout << a[i] << " ";

    return 0;
}
