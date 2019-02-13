#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef unsigned long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int P = 31;

ll pr1[N], pr2[N];

typedef struct node* node_ptr;

struct node {
    int y, sz;
    node_ptr l, r;
    ll p1, p2, s1, s2, c;
    bool flag;
    node() {
        y = rand();
        l = r = 0;
        p1 = p2 = s1 = s2 = flag = 0;
        sz = 1;
    }
} nds[N];

int n_sz;

node_ptr new_node(char c) {
    node &t = nds[n_sz];
    t.c = c - 'a';
    t.p1 = t.p2 = t.s1 = t.s2 = t.c;
    return &nds[n_sz++];
}

int gsz(node_ptr t) {
    return t ? t -> sz : 0;
}

ll gp1(node_ptr t) {
    return t ? t -> p1 : 0;
}

ll gp2(node_ptr t) {
    return t ? t -> p2 : 0;
}

ll gs1(node_ptr t) {
    return t ? t -> s1 : 0;
}

ll gs2(node_ptr t) {
    return t ? t -> s2 : 0;
}

void push(node_ptr t) {
    if (!t || t -> flag == 0) return;
    t -> flag = 0;
    swap(t -> p1, t -> s1);
    swap(t -> p2, t -> s2);
    swap(t -> l, t -> r);
    if (t -> l) t -> l -> flag ^= 1;
    if (t -> r) t -> r -> flag ^= 1;
}

void recalc(node_ptr t) {
    if (!t) return;
    push(t), push(t -> l), push(t -> r);
    t -> sz = 1 + gsz(t -> l) + gsz(t -> r);
    int k = gsz(t -> l);
    t -> p1 = (gp1(t -> l) + pr1[k] * (t -> c) + pr1[k + 1] * gp1(t -> r)) % B;
    t -> p2 = gp2(t -> l) + pr2[k] * (t -> c) + pr2[k + 1] * gp2(t -> r);
    k = gsz(t -> r);
    t -> s1 = (gs1(t -> r) + pr1[k] * (t -> c) + pr1[k + 1] * gs1(t -> l)) % B;
    t -> s2 = gs2(t -> r) + pr2[k] * (t -> c) + pr2[k + 1] * gs2(t -> l);
}

void Merge(node_ptr &w, node_ptr l, node_ptr r) {
    push(l), push(r);
    if (!l || !r) {
        w = l ? l : r;
        return;
    }
    if (l -> y > r -> y)
        Merge(l -> r, l -> r, r), w = l;
    else
        Merge(r -> l, l, r -> l), w = r;
    //push(w);
    recalc(w);
}

void Split(node_ptr w, node_ptr &l, node_ptr &r, int s) {
    push(w);
    if (!w) {
        l = r = 0;
        return;
    }
    if (gsz(w -> l) + 1 <= s)
        Split(w -> r, w -> r, r, s - gsz(w -> l) - 1), l = w;
    else
        Split(w -> l, l, w -> l, s), r = w;
    //push(l), push(r);
    recalc(w);
}

void out(node_ptr t) {
    if (!t) return;
    push(t);
    out(t -> l);
    cerr << char('a' + t -> c);
    out(t -> r);
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pr1[0] = pr2[0] = 1;
    forn(i, 1, N - 1)
        pr1[i] = pr1[i - 1] * P % B, pr2[i] = pr2[i - 1] * P;

    int n, q;
    node_ptr root = 0;
    string s;
    cin >> n >> q;
    cin >> s;
    for (auto c : s)
        Merge(root, root, new_node(c));
    forn(i, 1, q) {
        char c;
        cin >> c;
        int tp, l, r, k;
        node_ptr L, R, M;
        if (c == 'Q') {
            cin >> l >> r;
            Split(root, L, R, r);
            Split(L, L, M, l - 1);
            push(M);
            bool ans = (pii(gp1(M), gp2(M)) == pii(gs1(M), gs2(M)));
            Merge(L, L, M);
            Merge(root, L, R);
            cout << (ans ? "YES\n" : "NO\n");
        }
        else {
            cin >> tp;
            if (tp == 1) {
                cin >> l >> r >> k;
                Split(root, L, R, r);
                Split(L, L, M, l - 1);
                Merge(root, L, R);
                Split(root, L, R, k);
                Merge(L, L, M);
                Merge(root, L, R);
            }
            if (tp == 2) {
                cin >> l >> r;
                Split(root, L, R, r);
                Split(L, L, M, l - 1);
                M -> flag ^= 1;
                Merge(L, L, M);
                Merge(root, L, R);
            }
            if (tp == 3) {
                cin >> l >> c;
                Split(root, L, R, l - 1);
                Merge(L, L, new_node(c));
                Merge(root, L, R);
            }
        }
    }

    return 0;
}
