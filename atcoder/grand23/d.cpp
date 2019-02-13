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

const int N = 2e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, s;
int x[N], p[N];

ll getforce(int tl, int tr, ll force) {
    ll ans = 0;
    forn(i, 1, n) {
        if (!p[i]) continue;
        if (x[i] < s) {
            bool fail = 0;
            ll bal = force;
            for1(j, tl, i) {
                if (bal > 0) {fail = 1; break;}
                bal += p[j];
            }
            ans += (fail ? -1 : 1) * -p[i];
            cerr << s << ": " << i << " " << fail << " heh\n";
        }
        if (x[i] > s) {
            bool fail = 0;
            ll bal = force;
            forn(j, tr, i) {
                if (bal <= 0) {fail = 1; break;}
                bal -= p[j];
            }
            ans += (fail ? -1 : 1) * p[i];
            cerr << s << ": " << i << " " << fail << " heh\n";
        }
    }
    return ans;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    ll sum = 0;
    forn(i, 1, n) {
        cin >> x[i] >> p[i];
        sum += p[i];
    }

    ll ans = 0;
    while (sum > 0) {
        int tl = lower_bound(x + 1, x + 1 + n, s) - x - 1;
        int tr = tl + 1;
        if (x[tr] == s) ++tr;
        cerr << tl << " " << tr << "\n";
        ll sn = 0, sp = 0;
        forn(i, 1, tl) sn += p[i];
        forn(i, tr, n) sp += p[i];
        cerr << s << " " << sum << " " << sn << " " << sp << "\n";
        ll force;
        force = getforce(tl, tr, sp - sn);
        cerr << "doc " << s << " " << force << "\n";
        force = getforce(tl, tr, force);
        cerr << "doc " << s << " " << force << "\n";
        if (force <= 0) {
            ans += (s - x[tl]);
            s = x[tl];
            sum -= p[tl];
        }
        else {
            ans += (x[tr] - s);
            s = x[tr];
            sum -= p[tr];
        }
    }
    cout << ans << "\n";

    return 0;
}
