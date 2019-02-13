#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define pii pair<int, int>

#define mp make_pair
#define pb push_back

#define f first
#define s second

using namespace std;

const int N = (int) 1e6 + 7;
const int MOD = (int) 1e9 + 7;

typedef long double ld;
typedef unsigned long long ull;

int n, upper;
int e[N];
double f[N];

multiset<double> s;

inline bool check(double x) {
  int pt = 1;
  s.clear();
  for (int k = 1; k <= n; k++) {
    f[k] = e[k + 1] - e[k] * x;
    if (k > 2)
      s.insert(f[k - 2]);
    while (pt <= k - 2 && e[k] - e[pt] > upper) {
      s.erase(s.find(f[pt]));
      ++pt;
    }
    if (pt <= k - 2) {
      if (e[k] * (1.0 - x) >= *s.begin())
        return true;
    }
  }
  return false;
}

int main() {
  #ifdef LOCAL
  freopen("in.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> upper;
  for (int i = 1; i <= n; i++)
    cin >> e[i];

  double l = 0, r = 1;
  for (int iter = 0; iter < 40; iter++) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  if (!check(l)) cout << -1;
  else cout << fixed << setprecision(10) << l;

  return 0;
}
