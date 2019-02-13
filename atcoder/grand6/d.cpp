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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n = 4;
int a[N];

int f() {
    n = 2 * n - 1;
    vi v(8);
    forn(i, 1, 7)
        v[i] = a[i];
    forn(i, 1, n / 2) {
        vi t(v.size() - 2);
        //forn(i, 1, v.size() - 1) cerr << v[i] << " ";cerr << "\n";
        forn(j, 1, t.size() - 1)
            t[j] = v[j] + v[j + 1] + v[j + 2]
                - min(v[j], min(v[j + 1], v[j + 2])) - max(v[j], max(v[j + 1], v[j + 2]));
        v = t;
    }
    //forn(i, 1, 5) cout << a[i] << " "; cout << ":" << v[1] << "\n";
    n = (n + 1) / 2;
    return v[1];
}

int cnt[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 1, n * 2 - 1) a[i] = i;
    //cin >> n;
    do {
    forn(i, 1, 7) cnt[i] = 0;
    if (n == 2) {
        cout << 2 << "\n";
        assert(f() == 2);
        continue;
        //return 0;
    }/*
    forn(i, 1, n * 2 + 1)
        cin >> a[i];*/
    forn(j, 1, 2 * n - 3) {
        int x = a[j] + a[j + 1] + a[j + 2]
            - min(a[j], min(a[j + 1], a[j + 2])) - max(a[j], max(a[j + 1], a[j + 2]));
        ++cnt[x];
    }/*
    if (cnt[a[n]] >= 2) {
        cout << a[n] << "\n";
        assert(f() == a[n]);
        continue;
        //return 0;
    }*/
    int mx = -1;
    forn(i, 1, 2 * n - 1) {
        if (cnt[a[i]] >= 2 && (mx == -1 || abs(i - n) < abs(mx - n)))
            mx = i;
    }
    if (mx == -1) {
        cout << n << "\n";
        assert(n == f());
        continue;
        //return 0;
    }
    cout << a[mx] << " " << cnt[a[mx]] << "\n";
    cerr << "n = " << n << "\n";
    forn(i, 1, 2 * n - 1) cerr << a[i] << " ";cerr << "\n";
    cerr << f() << "\n";//cerr << ": " << a[mx] << " " << f() << " " << mx << "\n";
    assert(a[mx] == f());
    } while (next_permutation(a + 1, a + 6));
    /*
    int mx = 1;
    forn(i, 2, 2 * n - 1) {
        if (cnt[i] > cnt[mx]) mx = i;
        //cerr << i << ": " << cnt[i] << "\n";
    }
    vi v;
    forn(i, 1, 2 * n - 1)
        if (cnt[i] == cnt[mx]) v.pb(i);
    cout << v[v.size() / 2] << "\n";*/

    return 0;
}
