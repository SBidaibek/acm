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



int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    forn(i, 1, n) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        vi u(s.size());
        forn(i, 0, s.size() - 1) {
            if (s[i] == 's') {
                if (i > 0 && s[i - 1] == 'm' && !u[i - 1]) {
                    u[i - 1] = 1;
                    continue;
                }
                if (i < s.size() - 1 && s[i + 1] == 'm' && !u[i + 1]) {
                    u[i + 1] = 1;;
                    continue;
                }
                ++b;
            }
            else
                ++a;
        }
        if (a == b) cout << "tie\n";
        else cout << (a > b ? "mongooses" : "snakes") << "\n";
    }

    return 0;
}
