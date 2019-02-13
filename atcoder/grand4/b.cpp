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

int n, x;
int a[N];
bool u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    forn(i, 1, n)
        cin >> a[i];
    ll ans = INF;

    int at = 1;
    forn(i, 2, n)
        if (a[i] < a[at]) at = i;
    forn(i, 1, at - 1)
        a[i + n] = a[i];
    if (at > 1)4
        forn(i, at, n + at - 1)
            a[i - 1] = a[i];
    int p = 1;
    forn(i, 2, n) {
        if (a[i] >)
    }

    return 0;
}
