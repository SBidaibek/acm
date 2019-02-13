#include <bits/stdc++.h>
#include "timecard.h"

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef long double ld;

const int N = 2e6 + 10;
const int INF = 1e9 + 19;
const int B = 1e9 + 7;

void init(int n) {
}

string convert(string s) {
    for (auto &c : s) c = tolower(c);
    return s;
}
