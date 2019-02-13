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
    typedef vector <int> vi;

    const int N = 2e6 + 10;
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    int main() {
        #ifdef black
        freopen("in", "r", stdin);
        #endif // black
        ios_base :: sync_with_stdio(0);
        cin.tie(0);

        int ts;
        cin >> ts;
        forn(_t, 1, ts) {
            cout << "Case #" << _t << ": ";
            int n;
            cin >> n;
            vi a, v1, v2;
            forn(i, 1, n) {
                int x;
                cin >> x;
                v1.pb(x);
                if (i < n) {
                    cin >> x;
                    v2.pb(x);
                    ++i;
                }
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            forn(i, 0, v1.size() - 1) {
                a.pb(v1[i]);
                if (i < v2.size())
                    a.pb(v2[i]);
            }
            bool shit = 0;
            forn(i, 1, n - 1)
                if (a[i - 1] > a[i]) {
                    cout << i - 1 << "\n";
                    shit = 1;
                    break;
                }
            if (!shit) cout << "OK\n";
        }

        return 0;
    }
