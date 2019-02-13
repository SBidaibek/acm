#include <bits/stdc++.h>
#include "prize.h"

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
const int K = 3;//447;

vi c[N];
int cnt;

vi get(int x) {
    if (c[x].size()) return c[x];
    assert(++cnt <= 1e4);
    return c[x] = ask(x);
}

int find_best(int n) {
    if (n <= 1000)
        forn(i, 0, n - 1)
            if (get(i)[0] + get(i)[1] == 0) return i;
    set <int> st;
    forn(i, 0, K) {
        st.insert(get(i)[0] + get(i)[1]);
        if (get(i)[0] + get(i)[1] == 0) return i;
    }
    int mx = *--st.end();
    int ptr = K;
    int k = 0;
    forn(i, 0, K)
        if (get(i)[0] + get(i)[1] != mx) ++k;
    forn(it, k, K) {
        int l = ptr + 1, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int s = get(m)[0] + get(m)[1];
            if (!s) return m;
            if (s == mx) {
                if (get(m)[0] > it) r = m;
                else l = m + 1;
            }
            else {
                if (get(m)[0] == 0) {
                    l = r = m;
                    break;
                }
                while (m > l) {
                    --m;
                    if (get(m)[0] + get(m)[1] == 0) return m;
                    if (get(m)[0] + get(m)[1] == mx) break;
                }
                if (m == l) {
                    while (get(m)[0] + get(m)[1] < mx) ++m;
                    ptr = m - 1;
                    break;
                }
                else
                if (get(m)[0] > it) r = m;
                else l = m + 1;
            }
        }
        ptr = l;
    }
    assert(0);
}
