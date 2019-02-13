#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace kek {
    typedef long long ll;
    typedef pair <int, int> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const int INF = 1e9 + 9;
    const int B = 1e9 + 7;

    const int L = 22;
    int m, sz, prv[N][L], to[N], d[N];
    char ch[N];

    void init() {
    }

    void add(char c) {
        ++sz;
        to[sz] = sz;
        prv[sz][0] = to[sz - 1];
        forn(i, 1, L - 1)
            prv[sz][i] = prv[prv[sz][i - 1]][i - 1];
        d[sz] = d[prv[sz][0]] + 1;
        ch[sz] = c;
    }

    void undo(int x) {
        ++sz;
        to[sz] = to[sz - 1 - x];
    }

    char get(int x) {
        int p = to[sz];
        int k = d[p] - ++x;
        forn(i, 0, L - 1)
            if (k & (1 << i))
                p = prv[p][i];
        return ch[p];
    }
}

void Init() {
    kek :: init();
}

void TypeLetter(char ch) {
    kek :: add(ch);
}

void UndoCommands(int x) {
    kek :: undo(x);
}

char GetLetter(int p) {
    return kek :: get(p);
}


