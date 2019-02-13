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
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, a[N];
int bal[N], sx[N];
bool u[N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string str;
    forn(i, 1, n * 2) {
        char c;
        cin >> c;
        str.pb(c);
        a[i] = c - 'a';
    }

    vi p, s;
    int b = 0;
    p.pb(1);
    int lst = -1;
    forn(i, 1, n * 2) {
        bal[i] = bal[i - 1] + (a[i] ? 1 : -1);
        if (bal[i] == 0) {
            if (a[i] == 0) lst = s.size();
            s.pb(a[i] ? -1 : 1);
            p.pb(i + 1);
        }
    }

    string ans;
    forn(i, 0, p.size() - 2) {
        if (s[i] == 1) {
            forn(j, p[i], p[i + 1] - 1)
                u[j] = 1;
            int cnt = p[i + 1] - p[i], len = 1;
            for (; len <= p[i + 1] - p[i]; ++len) {
                //cerr << len << "\n";
                int mx = -1;
                forn(j, p[i], p[i + 1] - 1) {
                    if (!u[j]) continue;
                    if (j + (len - bal[j - 1]) - 1 >= p[i + 1])
                        u[j] = 0, --cnt;
                    else
                        mx = max(mx, len <= bal[j - 1] ? 'b' : a[j + len - bal[j - 1] - 1]);
                }
                forn(j, p[i], p[i + 1] - 1) {
                    if (!u[j]) continue;
                    if ((len <= bal[j - 1] ? 'b' : a[j + len - bal[j - 1] - 1]) != mx) u[j] = 0, --cnt;
                }
                if (cnt == 1) break;
            }
            assert(cnt == 1);

            forn(j, p[i], p[i + 1] - 1) {
                if (!u[j]) continue;
                ans = ans + string(bal[j - 1], 'b')
                    + str.substr(j - 1, len - bal[j - 1])
                    + string(bal[j + len - bal[j - 1] - 1], 'a');
                break;
            }
        }
        else {
            if (i < lst) continue;
            string cur;
            forn(j, p[i], p[i + 1] - 1)
                if (a[j] == 1 && a[j - 1] == 0)
                    cur.pb('a'), cur.pb('b');
        }
    }
    cout << ans << "\n";

    return 0;
}
