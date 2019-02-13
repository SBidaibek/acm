#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ld;
typedef vector <int> vi;

const int N = 3e5 + 10;
const ll INF = 1e18;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    bool h = 0, v = 0;
    for (auto c : s) {
        if (c == '0') {
            if (v == 0) {
                cout << "3 3\n";
                v = 1;
            }
            else {
                cout << "1 3\n";
                v = 0;
            }
        }
        else {
            if (h == 0) {
                cout << "1 1\n";
                h = 1;
            }
            else {
                cout << "1 3\n";
                h = 0;
            }
        }
    }

    return 0;
}
