#include <bits/stdc++.h>
#include "horses.h"

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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
int *a, *b;
ll p[N];
set <int> st;

int p1() {
    int x = n - 1;
    for (ll cur = 1; x >= 0 && cur <= 1e9; --x)
        cur = cur * a[x];
    return ++x;
}

int p2() {
    if (st.size()) {
        ll cur = 1;
        for (auto it = st.end();;) {
            --it;
            cur = cur * a[*it];
            if (cur > 1e9)
                return *it;
            if (it == st.begin())
                return 0;
        }
    }
    else return 0;
}

ll g() {
    p[0] = a[0];
    forn(i, 1, n - 1)
        p[i] = p[i - 1] * a[i] % B;
    int x = p2();
    //assert(x == p2());
    ll ans = b[x], cur = 1;
    forn(i, x + 1, n - 1) {
        cur = cur * a[i];
        ans = max(ans, cur * b[i]);
    }
    return (ans % B) * p[x] % B;
}

int init(int k, int X[], int Y[]) {
    n = k, a = X, b = Y;
    forn(i, 0, n - 1)
        if (a[i] > 1) st.insert(i);
    return g();
}

int updateX(int pos, int val) {
    if (a[pos] > 1) st.erase(pos);
    a[pos] = val;
    if (a[pos] > 1) st.insert(pos);
	return g();
}

int updateY(int pos, int val) {
	b[pos] = val;
	return g();
}

