#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vi cnt(101);
    int n;
    cin >> n;
    forn(it, 1, n) {
        int k;
        cin >> k;
        forn(i, 1, k) {
            int x;
            cin >> x;
            ++cnt[x];
        }
    }
    forn(i, 1, 100)
        if (cnt[i] == n)
            cout << i << " ";

    return 0;
}

