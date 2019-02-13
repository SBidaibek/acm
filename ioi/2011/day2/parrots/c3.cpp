#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace kek {
    typedef long long ll;
    typedef pair <int, int> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    void init() {
        forn(i, 0, N - 1)
            forn(j, 0, N - 1)
                d[i][j] = cnk(i + j - 1, i);
    }

    void num2obj(int n, int k, ll id) {
        for (; k > 0; --k)
            forn(i, 0, n)
                if (d[n - i][k - 1] < id)
                    id -= d[n - i][k - 1];
                else {
                    n -= i;
                    cnt[k] = i;
                    break;
                }
    }

    ll obj2num(int n, int k, int cnt[]) {
        ll ans = 0;
        for (; k > 0; --k) {
            forn(i, 0, cnt[k] - 1)
                ans += d[n - i][k - 1];
            n -= cnt[k];
        }
        return ++ans;
    }

    void encode(int n, int a[]) {
        vector <pii> v;
        forn(i, 0, n - 1) {
            send(a[i]), send(a[i]);
            v.pb({a[i], i});
        }
        sort(v.begin(), v.end());
        forn(i, 0, n - 1) {
            int x = ((i << 4) | (v[i].S));
            //bitset <8> b(x);
            //cerr << b << "\n";
            send(x);
        }
    }

    int cnt[(1 << 8)];

    void decode(int n, int l, int x[]) {
        forn(i, 0, 255) cnt[i] = 0;
        forn(i, 0, l - 1)
            ++cnt[x[i]];
        vi a, v, ans(n);
        forn(i, 0, 255) {
            forn(j, 1, cnt[i] / 2) a.pb(i);
            if (cnt[i] % 2 == 1) v.pb(i);
        }
        assert(a.size() == n && v.size() == n);
        sort(v.begin(), v.end());
        forn(i, 0, v.size() - 1) {
            int x = (v[i] >> 4), id = (v[i] % 16);
            assert(x == i);
            ans[id] = a[x];
        }
        for (auto x : ans)
            output(x);
    }
}

void encode(int N, int M[]) {
    kek :: encode(N, M);
}

void decode(int N, int L, int X[]) {
    kek :: decode(N, L, X);
}


