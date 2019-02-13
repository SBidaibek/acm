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

const int N = 1e7 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int K = 501;

#ifdef _WIN32
#define kekme getchar
#else
#define kekme getchar_unlocked
#endif

int read(int &x) {
    char ch = kekme();
    for (; ch < '0' || '9' < ch; ch = kekme());
    for (; '0' <= ch && ch <= '9'; ch = kekme())
        x = (x << 3) + (x << 1) + ch - '0';
}

int n;
int x[N], y[N];
int st[N], sz;

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    read(n);
    forn(i, 1, n) {
        read(x[i]), read(y[i]);
        if (sz && x[i] - x[st[sz]] <= y[st[sz]] - y[i]) continue;
        while (sz && x[i] - x[st[sz]] <= y[i] - y[st[sz]]) --sz;
        st[++sz] = i;
    }
    cout << sz << "\n";

    return 0;
}

