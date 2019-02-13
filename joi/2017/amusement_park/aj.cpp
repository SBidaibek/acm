#include <bits/stdc++.h>
#include "Joi.h"

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

#define N kekke
#define INF asom
#define B kaskk

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

#define g sekasjoi
#define used laksdasjoi
#define cnt asasdkjoi
#define id weyjoi
#define gen kekjoi

vi g[N];
int used[N];
int cnt;
int id[N];

void gen(int x) {
    id[x] = cnt++;
    used[x] = 1;
    for (auto to : g[x])
        if (!used[to]) gen(to);
}

void Joi(int n, int m, int f[], int t[], ll v, int tc) {
    forn(i, 0, m - 1) {
        g[f[i]].pb(t[i]);
        g[t[i]].pb(f[i]);
    }
    gen(0);
    forn(i, 0, n - 1)
        MessageBoard(i, bool(v & (1ll << (id[i] % 60))));
}

#undef gen
#undef id
#undef cnt
#undef g
#undef used

#undef N
#undef INF
#undef B
