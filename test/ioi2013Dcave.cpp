#include <bits/stdc++.h>
#include "grader.h"

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

const int MN = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int cur;

int s[MN], d[MN];

int tC() {
    return cur = tryCombination(s);
}

int solve(int l, int r, int mn, int prv) {
    if (l == r) return l;
    int m = (l + r) / 2;/*
    bool f = 0;
    forn(i, l, m) f |= (d[i] == -1);
    if (!f) return solve(m + 1, r, mn, prv);*/
    /*f = 0;
    forn(i, m + 1, r) f |= (d[i] == -1);
    if (!f) return solve(l, m, mn, prv);*/
    forn(i, l, m)
        if (d[i] == -1) s[i] ^= 1;
    if ((tC() == mn) != (prv == mn))
        return solve(l, m, mn, cur);
    else
        return solve(m + 1, r, mn, prv);
}

void exploreCave(int n) {
    forn(i, 0, n - 1) d[i] = -1;
    forn(i, 0, n - 1) {
        forn(j, i, n - 1)
            if (d[j] == -1) s[j] = 0;
        int tumblr = solve(0, n - 1, i, tryCombination(s));
        if (cur == i)
            s[tumblr] ^= 1;
        d[tumblr] = i;
    }
    answer(s, d);
}
