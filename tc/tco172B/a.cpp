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

int del[N];

class DengklekGaneshAndChains {
    public:
    string getBestChains(vector <string> S, vector <int> Q) {
        for (auto &s : S)
            s += s;
        string ans;
        forn(q, 0, Q.size() - 1) {
            string c1 = "", c2 = "";
            int at = -1;
            forn(it, 0, S.size() - 1) {
                if (del[it]) continue;
                string &s = S[it];
                string t = "", p = "";
                forn(i, 0, s.size() / 2)
                    if (s.substr(i, Q[q]) > t) t = s.substr(i, Q[q]);
                if (q < Q.size() - 1) {
                    forn(i, 0, s.size() / 2)
                        if (s.substr(i, Q[q + 1]) > p) p = s.substr(Q[q + 1]);
                }
                if (at == -1 || c1 + p < t + c2)
                    c1 = t, c2 = p, at = it;
            }
            ans += c1;
            del[at] = 1;
        }
        return ans;
    }
} C;

int main() {
    cerr << C.getBestChains({"ssh", "she", "see", "sea"}, {2,3,2,3}) << "\n";
}
