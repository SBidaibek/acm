// Nurbakyt Madibek
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const int N = (int)1e5 + 123;
/*
const int K = (int)2e6 + 10;

typedef struct node * node_ptr;

struct node {
    int x;
    node_ptr l, r;
    node() {
        x = 0;
        l = r = 0;
    }
} nds[K];

int nsz;

node_ptr new_node(int x) {
    nds[nsz].x = x;
    return &nds[nsz++];
}

int g(node_ptr t) {
    return t ? t -> x : 0;
}

node_ptr lt(node_ptr t) {
    return t ? t -> l : 0;
}

node_ptr rt(node_ptr t) {
    return t ? t -> r : 0;
}

void recalc(node_ptr t) {
    t -> x = g(t -> l) + g(t -> r);
}

node_ptr new_node(node_ptr l, node_ptr r) {
    nds[nsz].l = l, nds[nsz].r = r;
    recalc(&nds[nsz]);
    return &nds[nsz++];
}

node_ptr upd(int qx, node_ptr t, int tl, int tr) {
    if (tl == tr - 1)
        return new_node(g(t) + 1);
    node_ptr ans = new_node(0);
    if (t) *ans = *t;
    int m = (tl + tr) / 2;
    if (qx < m)
        ans -> l = upd(qx, lt(t), tl, m);
    else
        ans -> r = upd(qx, rt(t), m, tr);
    recalc(ans);
    return ans;
}

int get(int ql, int qr, node_ptr t, int tl, int tr) {
    if (!g(t) || qr <= tl && tr <= ql) return 0;
    if (ql <= tl && tr <= qr) return t -> x;
    int m = (tl + tr) / 2;
    return get(ql, qr, t -> l, tl, m) + get(ql, qr, t -> r, m, tr);
}
*/
int n, l, q;
int x[N];
char d[N];

int getId(vector < int > &f, int x, bool tp) {
    // 0 -> <=
    // 1 -> >=
    if (!tp) {
        int id = upper_bound(f.begin(), f.end(), x) - f.begin();
        return id - 1;
    }
    int id = lower_bound(f.begin(), f.end(), x) - f.begin();
    return id;
}

int calc(vector < int > &f, int t, int x) {
    int res = 0;
    if (x < 0)
        return 0;
    x = min(x, l);
    // 0 -> <=
    // 1 -> >=

    int id = getId(f, l - t, 0);
    int id2 = getId(f, x - t, 0);
    res += min(id, id2) + 1;

    int L = getId(f, l - t + 1, 1), R = getId(f, 2 * l - t, 0);
    id = getId(f, 2 * l - x - t, 1);
    if (id <= R)
        res += min(R - L + 1, R - id + 1);

    id = getId(f, 2 * l - t + 1, 1);
    id2 = getId(f, x - t + 2 * l, 0);

    if (id2 >= id)
        res += id2 - id + 1;

/*
    int res2 = 0;
    for (auto i : f) {
        if (i <= l - t) {
            res2 += (i <= x - t);
        } else if (i >= l - t + 1 && i <= 2 * l - t) {
            res2 += (i >= 2 * l - x - t);
        } else if (i >= 2 * l - t + 1) {
            res2 += (i <= x - t + 2 * l);
        }
    } */
    //cout << "hey " << res << ' ' << res2 << endl;
    return res;
}

vector < int > f, s;

int solve(int id, int t) {
    int tl = 0, tr = l, tm = -1, res = -1;
    while(tl <= tr) {
        tm = (tl + tr) / 2;
         //cout << tm << " -->\n";
         //cout << "R is " << calc(f, t, tm) << endl;
         //cout << "L is " << sz(s) - calc(s, t, l - tm - 1) << endl;
        if (calc(f, t, tm) + sz(s) - calc(s, t, l - tm - 1) >= id) {
            res = tm;
            tr = tm - 1;
        } else
            tl = tm + 1;
    }
    return res;
}

int main() {
#ifdef black
    freopen("in", "r", stdin);
#endif
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("\n%d %c", &x[i], &d[i]);
        if (d[i] == 'R')
            f.pb(x[i]);
        else
            s.pb(l - x[i]);
    }
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
    scanf("\n%d", &q);
    while(q--) {
        int id, t;
        scanf("\n%d %d", &id, &t);
        t %= (2 * l);
        printf("%d\n", solve(id, t));
    }
    return 0;
}

