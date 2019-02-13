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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

int n;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int p = 0;
    ll s = 0, sum = 0;
    multiset <int> st;
    forn(i, 1, n) {
        int tp, g;
        cin >> tp >> g;
        if (tp == 0) {
            s += g;
            if (s < 0) {
                cout << "-1\n";
                return 0;
            }
            if (g < 0) {
                while (st.size() && sum > s) {
                    auto it = --st.end();
                    sum -= *it;
                    st.erase(it);
                }
            }
        }
        else {
            if (g <= 0) {
                ++p;
                s += -g;
                continue;
            }
            sum += g;
            st.insert(g);
            while (st.size() && sum > s) {
                auto it = --st.end();
                sum -= *it;
                st.erase(it);
            }
        }
    }
    cout << st.size() + p << "\n";

    return 0;
}
