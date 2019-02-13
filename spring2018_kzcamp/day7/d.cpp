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

const int N = 6e5 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

namespace fast {
    int solve(int x) {
        return x * (x + 1) / 2;
    }
};

namespace slow {
    int solve(int x) {
        int a = 0;
        forn(i, 1, min(70, x)) a += i;
        return a;
    }
};


int n;
pii a[N];
int c[N][4];
vector <pii> v[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(tst, 10, 10) {
        srand(tst);
        cerr << "test = " << tst << "\n";
        int n = rand() % 100;
        cerr << n << "\n";
        assert(slow :: solve(n) == fast :: solve(n));
    }

    return 0;
}

