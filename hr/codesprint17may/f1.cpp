#include <bits/stdc++.h>

using namespace std;

#define forn(i, row, n) for (int i = int(row); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(row); --i)
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;

const int inf = (int)1e9 + 123
const ll infl = (ll)1e18 + 123;
const double eps = 1e-10;

const int MAX_N = (int)3e5 + 123;

struct Figure {
int row, y;
vector < pi > f;
void input(int cnt) {
f.resize(cnt);
for (int j = 0; j < cnt; j++)
scanf("%d%d", &f[j].f, &f[j].s);
}

void init() {
row = inf, y = inf;
for (auto i : f)
row = min(row, i.f), y = min(y, i.s);
for (auto &i : f)
i.f -= row, i.s -= y;
row = 0, y = 0;
for (auto i : f)
row = max(row, i.f), y = max(y, i.s);
}
} a[2000][4];

void rotate(Figure &s, Figure &t) {
t.f.clear();
for (auto i : s.f)
t.f.pb(mp(i.s, s.row - i.f));
t.init();
}

int n;

int ans[MAX_N][155];
int h = inf, w = 1;

int val[MAX_N][155];

bool can(int row, int y, Figure &now, int cl) {
for (auto i : now.f)
if (val[row + i.f][y + i.s] != 0)
return 0;
for (auto i : now.f)
val[row + i.f][y + i.s] = cl;
return 1;
}

void check(int lim) {
int H = 0, W = 0;
for (int i = 0, row = 0, y = 0; i < n; i++) {
while(1) {
bool flag = 0;
for (int j = 0; j < 4; j++) {
if (y + a[i][j].y < lim && can(row, y, a[i][j], i + 1)) {
flag = 1;
H = max(H, row + a[i][j].row + 1);
W = max(W, y + a[i][j].y + 1);
break;
}
}
if (flag)
break;
y++;
if (y == lim)
row++, y = 0;
}
}
if (h * w > H * W) {
h = H, w = W;
for (int i = 0; i < h; i++)
for (int j = 0; j < w; j++) {
ans[i][j] = val[i][j];
}
}
for (int i = 0; i < H; i++)
memset(val[i], 0, sizeof val[i]);
}

void output() {
printf("%d %d\n", h, w);
for (int i = 0; i < h; i++, printf("\n"))
for (int j = 0; j < w; j++)
printf("%d ", ans[i][j]);
exit(0);
}

int main() {
#ifdef DEBUG
freopen("input.txt", "r", stdin);
#endif
scanf("%d", &n);
for (int i = 0, cnt; i < n; i++) {
scanf("%d", &cnt);
a[i][0].input(cnt);
a[i][0].init();
for (int j = 1; j < 4; j++) {
rotate(a[i][j - 1], a[i][j]);
}
}
int maxi = 0;
for (int i = 0; i < n; i++)
maxi = max(maxi, a[i][0].y + 1);
check(maxi);
output();
return 0;
}
