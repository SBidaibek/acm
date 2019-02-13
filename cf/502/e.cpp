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

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll cp(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

pii vec(pii a, pii b) {
    return {b.x - a.x, b.y - a.y};
}

vector <pii> hull(vector <pii> a) {
    int n = a.size();
    int s = 0;
    forn(i, 1, n)
        if (a[i] < a[s]) s = i;
    swap(a[0], a[s]);
    for1(i, n - 1, 0)
        a[i].x -= a[0].x, a[i].y -= a[0].y;
    sort(a.begin(), a.end(), [](pii l, pii r) {
        if (cp(l, r) != 0)
            return cp(l, r) > 0;
        return l < r;
    });
    vi st(1);
    st[0] = 0;
    forn(i, 1, n - 1) {
        for (; st.size() > 1; st.pop_back()) {
            pii vo = vec(a[st[st.size() - 2]], a[st.back()]);
            pii vn = vec(a[st.back()], a[i]);
            if (cp(vo, vn) > 0) break;
        }
        st.pb(i);
    }
    for (auto x : st) cerr << x << "\n";
    vector <pii> ans;
    for (auto x : st)
        ans.pb(a[x]);
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <pii> a(n), b(m);
    forn(i, 0, n - 1)
        cin >> a[i].x >> a[i].y;
    a = hull(a);
    for (auto p : a)
        cerr << p.x << " " << p.y << "\n";
        exit(0);
    return 0;

    forn(i, 0, m - 1)
        cin >> b[i].x >> b[i].y;
    b = hull(b);

    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    return 0;
}
