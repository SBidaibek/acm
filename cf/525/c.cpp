#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

bool rev;
map <pii, int> sav;

int get(int c, int d) {
    if (rev) swap(c, d);
    int x;
    if (!sav.count({c, d})) {
        cout << "? " << c << " " << d << endl;
        cin >> x;
        sav[{c, d}] = x;
    }
    else
        x = sav[{c, d}];
    if (rev) x *= -1;
    return x;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int a = 0, b = 0, i = 2;
    while (i >= 0) {
        if (get(a, b) == -1) rev ^= 1;
        cerr << a << " " << b << " " << i << "\n";
        for (; i >= 0; --i) {
            if (get(a ^(1 << i), b ^ (1 << i)) != 1) break;
            if (get(a, b ^ (1 << i))  == +1)
                a ^= (1 << i), b ^= (1 << i);
        }
        if (get(a ^(1 << i), b ^ (1 << i)) == -1)
            a ^= (1 << i), --i;
        else
            break;
    }
    for (; i >= 0; --i) {
        if (get(a ^ (1 << i), b) == -1)
            a ^= (1 << i), b ^= (1 << i);
    }

    if (rev) swap(a, b);
    cout << "! " << a << " " << b << "\n";

    return 0;
}
