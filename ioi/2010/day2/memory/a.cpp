#include <bits/stdc++.h>
#include "grader.h"
//#include "cluedo.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

namespace kek {
    typedef long long ll;
    typedef pair <ll, ll> pii;
    typedef long double ld;
    typedef vector <int> vi;

    const int N = 2e6 + 1;
    const ll INF = 1e18 + 9;
    const int B = 1e9 + 7;

    char a[N];

    void play() {
        forn(i, 1, 50)
            a[i] = faceup(i);
        forn(i, 'A', 'Y')
            forn(j, 1, 50)
                if (a[j] == i) faceup(j);
    }
}

void play() {
    kek :: play();
}


