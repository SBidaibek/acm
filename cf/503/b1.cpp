#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <int> vi;

const int N = 5e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int sav[N];
int cnt = 0;

int get(int x) {
    assert(++cnt <= 60);
    if (sav[x] != INF) return sav[x];
    int ans = 0;
    cout << "? " << x << endl;
    cin >> ans;
    if (ans[(x + n / 2) % n]) {
        cout << "! " << x << endl;
        exit(0);
    }
    return sav[x] = ans;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    forn(i, 0, N - 1) sav[i] = INF;

    int n;
    cin >> n;
    int l = 0, r = n / 2 - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (abs(get(m) - get(l)) < m - l) r = m;
        else l = m;
    }

    assert(0);

    return 0;
}
