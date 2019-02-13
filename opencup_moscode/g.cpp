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

int n;
int cor[N];

vi get1(vi q) {
    cout << "? ";
    for (auto x : q) cout << x << " ";
    cout << endl;
    vi ans(n);
    vi in(n);
    forn(i, 0, n - 1)
        if (q[i]) in[cor[i + 1] - 1] = 1;
    forn(i, 0, n - 1) {
        ans[i] = (q[i] == 0 ? -1 : in[i]);//(c == '-' ? -1 : c - '0');
    }
//    forn(i, 0, n - 1) cerr << q[i] << " ";cerr << "\n";
//    forn(i, 0, n - 1) cerr << in[i] << " ";cerr << "\n";
//    forn(i, 0, n - 1) cerr << ans[i] << " ";cerr << "\n";
    return ans;
}

vi get(vi q) {
    cout << "? ";
    for (auto x : q) cout << x;
    cout << endl;
    vi ans(n);
    forn(i, 0, n - 1) {
        char c;
        cin >> c;
        ans[i] = (c == '-' ? -1 : c - '0');
    }
    return ans;
}

int ans[N];

bool ins(int a, int b, int c) {
    return a <= b && b <= c;
}

void solve(int l, int r, vi in) {
    //cerr << l << " " << r << ": ";forn(i, 0, n - 1) cerr << in[i] << " ";cerr << "\n";
    if (l == r) {
        forn(i, 0, n - 1)
            if (in[i]) ans[l + 1] = i + 1;
        assert(ans[l + 1] > 0);
        return;
    }
    vi inl(n, 0), inr(n, 0);
    vi q(n, 0);
    int m = (l + r) / 2;
    forn(i, 0, n - 1)
        if (ins(l, i, m) || (!ins(l, i, r) && in[i])) q[i] = 1;
    vi res = get(q);
    forn(i, 0, n - 1) {
        if (ins(l, i, m)) {
            if (in[i]) {
                if (res[i] == 1) inl[i] = 1;
                if (res[i] == 0) inr[i] = 1;
            }
        }
        else {
            if (res[i] == 1) inl[i] = 1;
            if (res[i] == 0) inr[i] = 1;
        }
    }

    forn(i, 0, n - 1)
        q[i] = ins(m + 1, i, r);
    res = get(q);
    forn(i, m + 1, r) {
        if (in[i]) {
            if (res[i] == 1) inr[i] = 1;
            if (res[i] == 0) inl[i] = 1;
        }
    }
    solve(l, m, inl);
    solve(m + 1, r, inr);
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    //forn(i, 1, n) cin >> cor[i];
    vi v(n);
    forn(i, 0, n - 1) v[i] = 1;
    solve(0, n - 1, v);
    cout << "! ";
    forn(i, 1, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
