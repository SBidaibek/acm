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

int up(int x) {
    int res;
    //cout << "F " << (x == 1 ? "A" : "B");
    printf("F %c", (x == 1 ? 'A' : 'B'));
    fflush(stdout);
    cin >> res;
    return res;
}

void reset(int x) {
    //cout << "R " << (x == 1 ? "A" : "B");
    printf("R %c", (x == 1 ? 'A' : 'B'));
    fflush(stdout);
}

int check() {
    int res;
    //cout << "E ";
    putchar('E');
    fflush(stdout);
    cin >> res;
    return res;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black

    int la = 0, lb = 0;
    int a = 1, b = 2;
    forn(i, 0, 30) {
        bool flag = 0;
        for (; la < (1 << i) && up(a); ++la);
        if (i > 0) reset(b);
        lb = 0;
        for (int j = 1; j <= (1 << (i + 1)); ++j, ++lb) {
            if (check()) flag = 1;
            if (flag || !up(b)) break;
        }
        if (check()) flag = 1;
        if (flag) break;
    }
    reset(a), reset(b);
    if (la > lb) {
        swap(a, b);
        swap(la, lb);
    }
    int ans = lb - la;
    for (; lb > la; --lb)
        up(b);
    for (; !check(); up(a), up(b))
        ans += 2;
    cout << "A " << ans << "\n";

    return 0;
}
