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

const int N = 2e5 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("holycow4.c", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    vector <string> s;
    string t;
    while (getline(cin, t)) {
        s.pb(t);
    }
    sort(s.begin(), s.end());
    int c = 0;
    for (auto x : s)
        cerr << c++ << ": " << x << "\n";


    return 0;
}
