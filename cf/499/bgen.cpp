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

map <int, int> sav;
int goal;
vi lie;
int iter;

int f(int x, int q) {
    return x == q ? 0 : x < q ? +1 : -1;
}

int cnt;

int get(int x) {
    //if (sav.count(x)) {
    //    return sav[x];
    //}
    assert(++cnt <= 60);
    int ans;
    cout << x << endl;
    //ans = f(x, goal) * (lie[iter]);
    //iter = (iter + 1) % lie.size();
    cin >> ans;
    if (ans == 0) exit(0);
    if (ans == -2) exit(0);
    return sav[x] = ans;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;// >> goal;
    //lie.resize(n);
    //forn(i, 0, n - 1) lie[i] = -1;//cin >> lie[i];
    vi v(n);
    forn(i, 0, n - 1)
        v[i] = get(i + 1);
    int l = n + 1, r = m;
    int it = 0;
    while (l < r) {
        int x = (l + r) / 2;
        if (get(x) * v[it % n] == +1) l = x + 1;
        else r = x - 1;
        ++it;
    }
    get(l);
    assert(0);

    return 0;
}
