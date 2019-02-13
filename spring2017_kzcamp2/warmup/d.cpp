#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> PII;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;

void gg() {
    cout << "Error occurred\n";
    exit(0);
}

string ans, a[N];
int k;

int rec(int i) {
    if (i > k) gg();
    ans += a[i];
    if (a[i] == "int") return i;
    ans.pb('<');
    i = rec(i + 1);
    ans.pb(',');
    i = rec(i + 1);
    ans.pb('>');
    return i;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    while (cin >> s)
        a[++k] = s;
    if (a[1] == "int") {
        if (k > 1) gg();
        cout << "int\n";
        return 0;
    }
    vi v;
    forn(i, 1, k) {
        if (i != 1 && !v.size()) gg();
        ans += a[i];
        if (a[i] == "int") {
            if (v.back()) {
                ans.pb(',');
                --v.back();
            }
            else {
                ans.pb('>');
                v.pop_back();
            }
        }
        else {
            ans.pb('<');
            v.pb(1);
        }
    }
    if (v.size()) gg();
    //if (rec(1) < k) gg();
    cout << ans << "\n";

    return 0;
}
