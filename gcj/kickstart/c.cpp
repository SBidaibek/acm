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

const int N = 2e2 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int a[N][N];
int d[N * N];
int di[] = {-1, 0, +1, 0};
int dj[] = {0, -1, 0, +1};

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
        int n, m, e, sr, sc, tr, tc;
        cin >> n >> m >> e >> sr >> sc >> tr >> tc;
        forn(i, 1, n)
            forn(j, 1, m)
                cin >> a[i][j];
        #define id(i, j) (i - 1) * m + j
        #define in(i, j) (1 <= i && i <= n && 1 <= j && j <= m)
        set <pii> st;
        forn(i, 1, n * m)
            d[i] = -1;
        d[id(sr, sc)] = 0;
        st.insert({0, id(sr, sc)});
        while (st.size()) {
            int id = st.begin() -> S;
            st.erase(st.begin());
            int i = (id - 1) / m + 1, j = (id - 1) % m + 1;
            forn(dir, 0, 3) {
                int ti = i + di[dir], tj = j + dj[dir];
                if (!in(ti, tj) || a[ti][tj] == -1e5 || d[id(i, j)] - a[ti][tj] > e) continue;
                if (d[id(ti, tj)] == -1 || d[id(ti, tj)] > d[id(i, j)] - a[ti][tj]) {
                    st.erase({d[id(ti, tj)], id(ti, tj)});
                    d[id(ti, tj)] = d[id(i, j)] - a[ti][tj];
                    st.insert({d[id(ti, tj)], id(ti, tj)});
                }
            }
        }
        int ans = d[id(tr, tc)];
        if (ans == -1) cerr << ans << "\n";
        else cerr << e - ans << "\n";
    }

    return 0;
}

