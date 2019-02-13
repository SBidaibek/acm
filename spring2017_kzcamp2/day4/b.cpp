#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int d[N * 2], t[N * 2];

bool ok(int x) {
    for (; x; x /= 10)
        if (x % 10 != 4 && x % 10 != 0) return 0;
    return 1;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #else
    freopen("transformations.in", "r", stdin);
    freopen("transformations.out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    int L = 3e6;
    //map <ll, int> d;
    queue <ll> q;
    q.push(4);
    d[4] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        //if (x == n) break;
        if (d[x] > 200) break;
        int to = x * 10;
        if (to <= L && !d[to]) {
            d[to] = d[x] + 1;
            q.push(to);
        }
        to = x * 10 + 4;
        if (to <= L && !d[to]) {
            d[to] = d[x] + 1;
            q.push(to);
        }
        to = x / 2;
        if (to <= L && x % 2 == 0 && !d[to]) {
            d[to] = d[x] + 1;
            q.push(to);
        }
    }
    vector <pii> v;
    forn(i, 1, 1e5)
        v.pb({d[i], i}), t[i] = 10 * L;
    sort(v.begin(), v.end());
    t[4] = 4;
    for (auto p : v) {
        int x = p.S;
        t[x] = max(t[x], x);
        int to = x * 10;
        if (to <= L && d[to] == d[x] + 1)
            t[to] = min(t[to], x);
        to = x * 10 + 4;
        if (to <= L && d[to] == d[x] + 1)
            t[to] = min(t[to], x);
        to = x / 2;
        if (to <= L && x % 2 == 0 && d[to] == d[x] + 1)
            t[to] = min(t[to], x);
    }
    forn(i, 1, 1e5) {
        printf("%d %d %d\n", i, d[i], t[i]);
    }
    while (tests--) {
        ll n;
        cin >> n;
        if (d[n] == 0) {
            cout << "kek\n";
            continue;
        }
        string ans;
        while (n != 4) {
            if (d[n / 10] == d[n] - 1) {
                if (n % 10 == 0) {
                    ans.pb('A');
                    n /= 10;
                    continue;
                }
                if (n % 10 == 4) {
                    ans.pb('B');
                    n /= 10;
                    continue;
                }
            }
            ans.pb('C');
            n *= 2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    return 0;
}
