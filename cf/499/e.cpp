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

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

struct point {
    int x, y, z;
    point() : x(0), y(0), z(0) {}
};// in[10], out[10];

vector <int> in[100], out[100];

bool ins(vi p) {
    bool ok = 1;
    forn(j, 0, 2) {
        ok &= (in[0][j] <= p[j]);
        ok &= (p[j] <= in[1][j]);
    }
    return ok;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    forn(i, 0, 99) in[i].resize(3);
    forn(i, 0, 99) out[i].resize(3);

    int xx, yx, zx, n, m, k;
    cin >> xx >> yx >> zx >> n >> m >> k;
    in[0] = {INF, INF, INF};
    in[1] = {-INF, -INF, -INF};
    out[0] = {-INF, -INF, -INF};
    out[1] = {INF, INF, INF};
    forn(i, 1, n) {
        vi p;
        p.resize(3);
        forn(j, 0, 2) {
            cin >> p[j];
            in[0][j] = min(in[0][j], p[j]);
            in[1][j] = max(in[1][j], p[j]);
        }
    }
    vector <vi> bad(m + 1);
    forn(i, 1, m) {
        bad[i].resize(3);
        forn(j, 0, 2)
            cin >> bad[i][j];
        bool ok = 1;
        if (ins(bad[i])) {
            cout << "INCORRECT\n";
            return 0;
        }
    }
    cout << "CORRECT\n";

    int it = 2;
    forn(x, 0, 1)
        forn(y, 0, 1)
            forn(z, 0, 1) {
                if (!x && !y && !z) continue;
                int l = 0, r = 1e5;
                while (l < r) {
                    vi sav = in[1];
                    int mid = (l + r + 1) / 2;
                    in[1][0] += x * mid;
                    in[1][1] += y * mid;
                    in[1][2] += z * mid;
                    bool ok = 1;
                    forn(i, 1, m)
                        if (ins(bad[i])) ok = 0;
                    if (ok) l = mid;
                    else r = mid - 1;
                    in[1] = sav;
                }
                in[it][0] = in[1][0] + x * l;
                in[it][1] = in[1][1] + y * l;
                in[it][2] = in[1][2] + z * l;
                it++;
            }
    forn(i, 2, it - 1)
        forn(j, 0, 2)
            out[1][j] = min(in[i][j], out[1][j]);

    int start = it;
    forn(x, 0, 1)
        forn(y, 0, 1)
            forn(z, 0, 1) {
                if (!x && !y && !z) continue;
                int l = 0, r = 1e5;
                while (l < r) {
                    vi sav = in[0];
                    int mid = (l + r + 1) / 2;
                    in[0][0] -= x * mid;
                    in[0][1] -= y * mid;
                    in[0][2] -= z * mid;
                    bool ok = 1;
                    forn(i, 1, m)
                        if (ins(bad[i])) ok = 0;
                    if (ok) l = mid;
                    else r = mid - 1;
                    in[0] = sav;
                }
                in[it][0] = in[0][0] - x * l;
                in[it][1] = in[0][1] - y * l;
                in[it][2] = in[0][2] - z * l;
                it++;
            }
    forn(i, start, it - 1)
        forn(j, 0, 2)
            out[0][j] = max(in[i][j], out[0][j]);

    forn(it, 1, k) {
        vi v;
        v.resize(3);
        forn(j, 0, 2)
            cin >> v[j];
        if (ins(v)) {
            cout << "OPEN\n";
            continue;
        }
        forn(i, 0, 1)
            swap(in[i], out[i]);
        if (ins(v)) {
            forn(i, 0, 1)
                swap(in[i], out[i]);
            cout << "UNKNOWN\n";
            continue;
        }
        forn(i, 0, 1)
            swap(in[i], out[i]);
        cout << "CLOSED\n";
    }


    return 0;
}
