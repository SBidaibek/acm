#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 3e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
vector <pii> f[N];

const int K = 5e4 + 20;
const int Kk = 5e3 + 4;
int table[K][Kk];
int W;
int H;

bool calc(int id, int x, int y) {
    bool flag = 1;
    for (auto it : f[id]) {
        flag &= (y + it.s < W);
        flag &= (table[x + it.f][y + it.s] == 0);
        if (!flag) return 0;
    }
    for (auto it : f[id]) {
        H = max(H, x + it.f);
        table[x + it.f][y + it.s] = id + 1;
    }
    return true;
}

void magic(int id) {
    int MNrow = (int) 1e9;
    int miny = (int) 1e9;
    for (auto &it : f[id]) {
        MNrow = min(MNrow, it.f);
        miny = min(miny, it.s);
    }
    for (auto &it : f[id]) {
        it.f -= MNrow;
        it.s -= miny;
    }
}

bool cmp(int a, int b) {
  return f[a].size() > f[b].size();
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black\

    cin >> n;
    for (int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int x, y;
        cin >>x  >> y;
        f[i].pb(pii(x,  y));
    }
    magic(i);
    for (auto it : f[i])
        W = max(W, it.s);
    }
    W = W * 4;

    vector<int> o;
    for (int i = 0; i < n; i++) o.pb(i);
    sort(o.begin(), o.end(), cmp);

    for (auto it : o) {
    for (int x = 0; true; x++) {
        bool flag = 0;
        for (int y = 0; y < W; y++) {
        if (calc(it, x, y)) {
            flag = 1;
            break;
        }
        }
        if (flag) break;
    }
    }
    cout << H+1 << ' ' << W << endl;
    for (int i = 0; i < H+1; i++) {
    for (int j = 0; j < W; j++) printf("%d ", table[i][j]);
        puts("");
    }
    return 0;
}
