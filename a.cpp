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

int n;
int k, m;
int a[N];
int cnt[N];
vi v;

bool bit(int mask, int pos) {
    return mask & (1 << pos);
}

void rec(int x) {
    if (x > n) {
        forn(i, 1, n) {
            bitset <6> b(a[i]);
            if (i < 10) cerr << " ";
            cerr << i << ": " <<
            b << "\n";
        }
        cout << "yes\n";
        exit(0);
    }
    for (auto mask : v) {
        bool shit = 0;
        forn(i, 0, m - 1) {
            if (!bit(mask, i)) continue;
            if (cnt[i] == k) {
                shit = 1;
                break;
            }
        }
        if (shit) continue;
        forn(i, 1, x - 1)
            if ((mask & a[i]) == 0) {shit = 1; break;}
        if (shit) continue;
        forn(i, 0, m - 1) {
            if (!bit(mask, i)) continue;
            ++cnt[i];
        }
        a[x] = mask;
        rec(x + 1);
        a[x] = 0;
        forn(i, 0, m - 1) {
            if (!bit(mask, i)) continue;
            --cnt[i];
        }
    }
}

int main() {
    #ifdef black
    //freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    //k = n / 2;
    //m = (n * 3 + (k - 1)) / k;
    cerr << k << " " << m << "\n";
    forn(mask, 1, (1 << m) - 1) {
        if (__builtin_popcount(mask) != 3) continue;
        v.pb(mask);
    }
    random_shuffle(v.begin(), v.end());
    rec(1);
    cout << "no\n";

    return 0;
}
