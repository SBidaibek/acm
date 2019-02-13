#include <bits/stdc++.h>
#include "koala.h"

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

const int maxn = 2e3 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int q[maxn], g[maxn];

int minValue(int n, int w) {
    q[0] = 1;
    forn(i, 1, n - 1) q[i] = 0;
    playRound(q, g);
    forn(i, 0, n - 1)
        if (q[i] >= g[i])
            return i;
}

int maxValue(int n, int w) {
    // TODO: Implement Subtask 2 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

int greaterValue(int n, int w) {
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

void allValues(int n, int w, int *ans) {
    if (w == 2 * n) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    }
}
