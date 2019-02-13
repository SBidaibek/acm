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
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, d;
int a[N];

void kek(int x) {
    int l = 0, r = 1e9;
    if (x > 1) l = max(l, a[x - 1] - d), r = min(r, a[x - 1] + d);
    if (x < n) l = max(l, a[x + 1] - d), r = min(r, a[x + 1] + d);
    forn(i, 1, n) {
        if (a[i] < l || r < a[i] || abs(x - i) <= 1) continue;
        bool shit = 0;
        if (i > 1) shit |= (abs(a[x] - a[i - 1]) > d);
        if (i < n) shit |= (abs(a[x] - a[i + 1]) > d);
        if (!shit) {
            cout << i << " " << x << "\n";
            exit(0);
        }
    }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vi v;
    cin >> n >> d;
    forn(i, 1, n) {
        cin >> a[i];
        if (i > 1 && abs(a[i] - a[i - 1]) > d) v.pb(i);
    }
    if (v.size() == 0) {
        cout << "0\n";
        return 0;
    }
    if (v.size() > 4) {
        cout << "-1\n";
        return 0;
    }
    vi c;
    for (auto i : v) {
        c.pb(i), c.pb(i - 1);
        if (i < n) c.pb(i + 1);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    forn(i, 0, c.size() - 1) {
        forn(j, i + 1, c.size() - 1) {
            swap(a[c[i]], a[c[j]]);
            bool shit = 0;
            forn(k, 2, n)
                if (abs(a[k] - a[k - 1]) > d) shit = 1;
            if (!shit) {
                cout << c[i] << " " << c[j] << "\n";
                return 0;
            }
            swap(a[c[i]], a[c[j]]);
        }
    }
    if (v.size() == 1 || (v.size() == 2 && v[1] - v[0] == 1)) {
        kek(v[0]);
        if (v.size() == 1) kek(v[0] - 1);
    }

    cout << "-1\n";

    return 0;
}

