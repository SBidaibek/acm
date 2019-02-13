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

const int N = 1e3 + 10;
const int INF = 1e9 + 9;
const int B = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vector <ll> a(n + 1);
    vector <ll> p(n + 1);
    vector <ll> p1(n + 1);
    vi tp(n + 1);
    forn(i, 1, n) {
        cin >> a[i];
        tp[i] = 1;
        ll s = sqrt(a[i]);
        ll c = cbrt(a[i]);
        ll ss = sqrt(ll(sqrt(a[i])));
        if (s * s == a[i]) {
            if (ss * ss == s)
                p[i] = ss, tp[i] = 4;
            else
                p[i] = s, tp[i] = 2;
        }
        if (c * c * c == a[i]) {
            p[i] = c;
            tp[i] = 3;
        }
//        cerr << a[i] << ": " << p[i] << " " << tp[i] << "\n";
    }
    map <ll, int> pcnt;
    map <ll, int> down;
    forn(it, 1, n) {
        forn(i, 1, n) {
            if (tp[i] != 1) continue;
            forn(j, 1, n) {
                if (tp[j] == 1) continue;
                ll g = 1;
                if (a[i] % p[j] == 0) g *= p[j];
                if (tp[j] == -1 && a[i] % p1[j] == 0) g *= p1[j];
                if (g == a[i]) {assert(a[i] == a[j]);}
                if (g == 1 || g == a[i]) continue;
                tp[i] = -1;
                p[i] = g;
                p1[i] = a[i] / p[i];
            }
        }
    }

//    forn(i, 1, n)
//        cerr << a[i] << ": " << p[i] << " " << p1[i] << " " << tp[i] << "\n";

    forn(i, 1, n) {
        if (tp[i] == -1)
            ++pcnt[p[i]], ++pcnt[p1[i]];
        if (tp[i] == 1)
            ++down[a[i]];
        if (tp[i] >= 2)
            pcnt[p[i]] += tp[i];
    }

    ll ans = 1;
    for (auto el : pcnt)
        ans = ans * (el.S + 1) % B;
    for (auto el : down)
        ans = ans * (el.S + 1) % B * (el.S + 1) % B;

    cout << ans << endl;

    return 0;
}

