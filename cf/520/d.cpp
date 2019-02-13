#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll p[N], s[N];

int fp(int x) {
    return x == p[x] ? x : p[x] = fp(p[x]);
}

void u(int a, int b, int d) {
    s[fp(a)] += 4 * d;
    if (fp(a) == fp(b)) return;
    s[fp(b)] += s[fp(a)];
    p[fp(a)] = fp(b);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <ll> a(n + 1);
    ll ans = 0;
    forn(i, 2, n)
        p[i] = i, s[i] = 0;
    for1(i, n, 2)
        for (int j = 2; i * j <= n; ++j)
            u(i, i * j, j);
    forn(i, 2, n)
        ans = max(ans, s[fp(i)]);
    cout << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll p[N], s[N];

int fp(int x) {
    return x == p[x] ? x : p[x] = fp(p[x]);
}

void u(int a, int b, int d) {
    s[fp(a)] += 4 * d;
    if (fp(a) == fp(b)) return;
    s[fp(b)] += s[fp(a)];
    p[fp(a)] = fp(b);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <ll> a(n + 1);
    ll ans = 0;
    forn(i, 2, n)
        p[i] = i, s[i] = 0;
    for1(i, n, 2)
        for (int j = 2; i * j <= n; ++j)
            u(i, i * j, j);
    forn(i, 2, n)
        ans = max(ans, s[fp(i)]);
    cout << ans << "\n";

    return 0;
}

