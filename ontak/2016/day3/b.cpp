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

int a[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n)
        cin >> a[i];
    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s) {
        if (c == 'F') {
            forn(i, 1, n - 1)
                if (a[i] > a[i + 1])
                    swap(a[i], a[i + 1]);
        }
        else {
            for1(i, n - 1, 1)
                if (a[i] > a[i + 1])
                    swap(a[i], a[i + 1]);
        }
        bool ok = 1;
        forn(i, 1, n - 1)
            ok &= (a[i] < a[i + 1]);
        ++ans;
        if (ok) {
            cout << ans << "\n";
            break;
        }
    }


    return 0;
}
