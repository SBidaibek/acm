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

const int N = 100 + 1;
const int K = 1e3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
pii a[N];
int p[N];
int v[N], c[N], ans;
set <int> st;

void rec(int x) {
    if (x == n + 1) {
        bool shit = 0;
        forn(i, 1, n) c[i] = 0;
        forn(i, 1, n) ++c[v[i]];
        forn(i, 1, n)
            forn(j, i + 1, n)
                if (v[i] == i && i <= p[j] && !c[j]) shit = 1;
        int mask = 0;
        forn(i, 1, n)
            if (v[i] == i) mask |= (1 << (i - 1));
        if (!shit) st.insert(mask);
        return;
    }
    v[x] = x;
    rec(x + 1);
    v[x] = x;
    forn(i, 1, p[x])
        if (v[i] == i) {
            v[i] = x;
            rec(x + 1);
            v[x] = x;
            v[i] = i;
        }
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, 1, n)
        cin >> a[i].F >> a[i].S;
    sort(a + 1, a + 1 + n);
    forn(i, 1, n)
        for1(j, i - 1, 1)
            if (a[j].F < a[i].S) {
                p[i] = j;
                break;
            }
    rec(1);
    cout << st.size() << "\n";

    return 0;
}

