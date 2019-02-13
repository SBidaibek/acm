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
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll divup(ll a, ll b) {
    return (a + b - 1) / b;
}

ll slow(vi vl, vi vr, vector <pii> k) {
    ll ans = 0;
    forn(i, 1, k.size() - 1) {
        if (k[i].F <= 0) continue;
        int l = 1, r = 1e9 + 1;
        while (l < r) {
            int m = (l + r) / 2;
            ll cur = 0;
            forn(j, 1, vl.size() - 1)
                if (m >= vl[j]) cur += min(1ll * m, vr[j]) - vl[j] + 1;
            //cerr << l << " " << r << "\n";
            if (cur < k[i].F) l = m + 1;
            else r = m;
        }
        if (l == 1e9 + 1) continue;
        ans += 1ll * l * k[i].S;
    }
    return ans;
}

int C[3][6];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    freopen("out", "w", stderr);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(_, 1, T) {
        cerr << "Case #" << _ << ": ";
        int n, q;
        cin >> n >> q;
        forn(i, 0, 2)
            forn(j, 0, 5)
                cin >> C[i][j];
        vi x(n + 1), y(n + 1), z(q + 1);
        vi l(n + 1), r(n + 1);
        vector <pii> k(q + 1);
        x[1] = C[0][0], x[2] = C[0][1];
        y[1] = C[1][0], y[2] = C[1][1];
        z[1] = C[2][0], z[2] = C[2][1];
        forn(i, 3, n) {
            x[i] = (C[0][2] * x[i - 1] + C[0][3] * x[i - 2] + C[0][4]) % C[0][5];
            y[i] = (C[1][2] * y[i - 1] + C[1][3] * y[i - 2] + C[1][4]) % C[1][5];
        }
        forn(i, 3, q)
            z[i] = (C[2][2] * z[i - 1] + C[2][3] * z[i - 2] + C[2][4]) % C[2][5];
        forn(i, 1, n) {
            l[i] = min(x[i], y[i]) + 1;
            r[i] = max(x[i], y[i]) + 1;
        }
        forn(i, 1, q)
            k[i].F = z[i] + 1, k[i].S = i;

        ll sum = 0;
        vector <pii> v;
        forn(i, 1, n) {
            sum += r[i] - l[i] + 1;
            v.pb({l[i], +1}), v.pb({r[i] + 1, -1});
        }
        v.pb({1e9 + 1, 0});
        sort(v.begin(), v.end());
        forn(i, 1, q)
            k[i].F = sum - k[i].F + 1;
        sort(k.begin() + 1, k.end());

        //forn(i, 1, n) cerr << l[i] << " " << r[i] << "\n";
        //cerr << "-\n";
        //forn(i, 1, q)
       // cerr << k[i].F << "\n";

        int ptr = 1;
        while (ptr <= q && k[ptr].F <= 0) ++ptr;
        ll ans = 0, cur = 0, bal = 0, prv = 0;
        forn(i, 0, v.size() - 1) {
            ll sav = cur;
            cur += (v[i].F - prv) * bal;
            //cerr << prv << " -> " << v[i].F << " | " << cur << " " << bal << "\n";
            for (; ptr <= q && k[ptr].F <= cur; ++ptr) {
                //cerr << k[ptr].F << " " << prv << " " << sav << " " << bal << "\n";
                ll val = prv + divup(k[ptr].F - sav, bal) - 1;
                ans += val * k[ptr].S;
            }
            prv = v[i].F;
            int j = i;
            for (; i < v.size() && v[i].F == v[j].F; ++i)
                bal += v[i].S;
            --i;
        }
        //cerr << "slow = " << slow(l, r, k) << " ";
        cerr << ans << endl;
    }

    return 0;
}

