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

const int N = 2e6 + 1;
const int INF = 1e9  + 9;
const int B = 1e9 + 7;
const int K = 400;

vector <pii> f(int n, int m) {
    if (!n || !m) return vector <pii> (0);
    vector <pii> ans;
    ans.pb({1, 1});
    ans.pb({n, 1});
    ans.pb({n, m});
    ans.pb({1, m});
    forn(i, 2, m / 2) {
        ans.pb({i, 1});
        ans.pb({n - i + 1, 1});
        ans.pb({n, i});
        ans.pb({n, m - i + 1});
        ans.pb({n - i + 1, m});
        ans.pb({i, m});
        ans.pb({1, m - i + 1});
        ans.pb({1, i});
    }
    if (n != m) {
        forn(i, m / 2 + 1, n / 2) {
            ans.pb({i, 1});
            ans.pb({n - i + 1, 1});
            ans.pb({n - i + 1, m});
            ans.pb({i, m});
        }
        vector <pii> nxt = f(n - 2, m - 2);
        for (auto p : nxt)
            ans.pb({p.x + 1, p.y + 1});
    }
    else {
        vector <pii> nxt = f(n - 2, m - 2);
        for (auto p : nxt)
            ans.pb({n - p.y, 1 + p.x});
    }
    return ans;
}


vector <pii> spec(int n, int m) {
    if (n == 1 && m == 1) return vector <pii> {{1, 1}};
    vector <pii> ans;
    ans.pb({1, 1});
    ans.pb({n, 1});
    ans.pb({n, m});
    ans.pb({1, m});
    forn(i, 2, m / 2) {
        ans.pb({i, 1});
        ans.pb({n - i + 1, 1});
        ans.pb({n, i});
        ans.pb({n, m - i + 1});
        ans.pb({n - i + 1, m});
        ans.pb({i, m});
        ans.pb({1, m - i + 1});
        ans.pb({1, i});
    }
    ans.pb({n / 2 + 1, 1});
    ans.pb({n, n / 2 + 1});
    ans.pb({n / 2 + 1, n});
    ans.pb({1, n / 2 + 1});
    vector <pii> nxt = spec(n - 2, m - 2);
    for(auto p : nxt)
        ans.pb({1 + p.x, 1 + p.y});
    return ans;
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "Yes\n1 1\n";
        return 0;
    }
    if (n == 1 && m == 2) {
        cout << "Yes\n1 1\n1 2\n";
        return 0;
    }
    if (n == 2 && m == 1) {
        cout << "Yes\n1 1\n2 1\n";
        return 0;
    }
    bool sw = 0;
    if (n < m) sw = 1, swap(n, m);
    if (n % 2 == 1 || m % 2 == 1) {
        if (n == 3 && m == 3) {
            cout << "Yes\n";
            vector <pii> v = {
                {1, 1},
                {3, 1},
                {3, 3},
                {1, 3},
                {2, 1},
                {3, 2},
                {2, 3},
                {1, 2},
                {2, 2},
            };
            for (auto p : v)
                cout << p.x << " " << p.y << "\n";
        }
        else
            if (n != m) cout << "No\n";
        if (n != 3 && n == m) {
            cout << "Yes\n";
            vector <pii> v = spec(n, m);
            for (auto p : v)
                cout << p.x << " " << p.y << "\n";
        }
        return 0;
    }
    cout << "Yes\n";
    vector <pii> v = f(n, m);
    if (sw) reverse(v.begin(), v.end());
    for (auto p : v)
        if (!sw)
            cout << p.x << " " << p.y << "\n";
        else
            cout << p.y << " " << p.x << "\n";

    return 0;
}
