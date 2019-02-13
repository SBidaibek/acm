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
typedef vector <int> vi;

const int N = 4e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

string f(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.end());

}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string minp, mins;
    vi ress(s.size()), resp(s.size());
    forn(i, 0, s.size() - 1) {
        string savp = minp, savs = mins;
        string t1 = savp + s[i];
        string t2 = savs + s[i];
        reverse(t2.begin(), t2.end());
        //cerr << t1 << " " << t2 << "\n";
        minp = min(t1, t2);
        resp[i] = (t1 < t2);

        t1 = savp + s[i];
        reverse(t1.begin(), t1.end());
        t2 = savs + s[i];

        reverse(t1.begin(), t1.end());
        reverse(t2.begin(), t2.end());
        mins = min(t1, t2);
        ress[i] = (t1 < t2);
        reverse(mins.begin(), mins.end());
        //cerr << minp << " " << mins << "\n-\n";
    }

    vi res(s.size());
    int p = 1;
    for1(i, s.size() - 1, 0) {
        if (p) {
            res[i] = (!resp[i]);
            p = resp[i];
        }
        else {
            res[i] = ress[i];
            p = ress[i];
        }
    }
    forn(i, 0, s.size() - 1)
        cout << res[i] << " ";

    return 0;
}

