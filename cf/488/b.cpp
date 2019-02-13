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
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll n, m;
int p[2][10][10];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        p[0][a][b] = 1;
    }
    forn(i, 1, m) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        p[1][a][b] = 1;
    }
    set <int> ans;
    bool bad = 0;
    forn(i, 1, 9)
        forn(j, i + 1, 9) {
            if (!p[0][i][j]) continue;
            set <int> st;
            int k = 0;
            forn(i1, 1, 9)
                forn(j1, i1 + 1, 9)
                    if ((i == i1) + (i == j1) + (j == i1) + (j == j1) == 1 && p[1][i1][j1])
                        st.insert(i == i1 || i == j1 ? i : j), ans.insert(i == i1 || i == j1 ? i : j);
            //if (st.size() == 1)
                //ans.insert(*st.begin());
            if (st.size() > 1) bad = 1;
        }
    if (ans.size() == 1) {
        cout << *ans.begin() << "\n";
        return 0;
    }
    set <int> ans2;
    forn(i, 1, 9)
        forn(j, i + 1, 9) {
            if (!p[1][i][j]) continue;
            set <int> st;
            int k = 0;
            forn(i1, 1, 9)
                forn(j1, i1 + 1, 9)
                    if ((i == i1) + (i == j1) + (j == i1) + (j == j1) == 1 && p[0][i1][j1])
                        st.insert(i == i1 || i == j1 ? i : j), ans2.insert(i == i1 || i == j1 ? i : j);
            //if (st.size() == 1)
                //ans2.insert(*st.begin());
            if (st.size() > 1) bad = 1;
        }
    if (ans2.size() == 1) {
        cout << *ans2.begin() << "\n";
        return 0;
    }
    set <int> st;
    bool ok = 0;
    for (auto x : ans)
        for (auto y : ans2)
            if (x == y) st.insert(x);
//    if (st.size() == 1) {
//        cout << *st.begin() << "\n";
//        return 0;
//    }
    if (bad || ans.size() == 0 || ans2.size() == 0) {
        cout << "-1\n";
        return 0;
    }
    cout << "0\n";


    return 0;
}
