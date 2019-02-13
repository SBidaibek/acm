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

const int N = 3e5 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

///change to type template
template <typename T> class seg_tree {
protected:
    vector <T> nodes;
    vector <T> pushed;
    int n_leaves;

    inline int _left(int node_id) {
        return node_id * 2;
    }

    inline int _right(int node_id) {
        return node_id * 2 + 1;
    }

    static T neutral_element;
    T oper(T a, T b);

    void recalc(int node_id) {
        nodes[node_id] = oper(nodes[_left(node_id)], nodes[_right(node_id)]);
    }

    void build(int node_id, int left_bound, int right_bound, vector <int> &init_val) {
        if (left_bound == right_bound - 1) {
            nodes[node_id] = init_val[left_bound];
            return;
        }
        int mid_bound = (left_bound + right_bound) / 2;
        build(_left(node_id), left_bound, mid_bound, init_val);
        build(_right(node_id), mid_bound, right_bound, init_val);
        recalc(node_id);
    }

    T get(int left_query, int right_query, int node_id, int left_bound, int right_bound) {
        if (left_query <= left_bound && right_bound <= right_query) return nodes[node_id];
        if (right_query <= left_bound || right_bound <= left_query) return neutral_element;
        int mid_bound = (left_bound + right_bound) / 2;
        return oper(
            get(left_query, right_query, _left(node_id), left_bound, mid_bound),
            get(left_query, right_query, _right(node_id), mid_bound, right_bound)
        );
    }

public:
    seg_tree(vector <int> &init_val) {
        n_leaves = init_val.size();
        nodes.resize(n_leaves * 4 + 1);
        build(1, 1, n_leaves + 1, init_val);
    }

    T get(int x, int left_bound, int right_bound) {
        return get(left_bound, right_bound, 1, 1, n_leaves + 1);
    }

    T root() {
        //push(1, 1, n_leaves + 1);
        return nodes[1];
    }
};

template <typename T> class min_seg_tree: seg_tree <T> {
    min_seg_tree() {
        //neutral_element = INF;
    }
};

void operator = (string s1, string s2) {
    s1 = s2;
    return s1.size() % 2;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string a = "a", b = "b";
    cerr << (a = b) << "\n";

    return 0;
}
