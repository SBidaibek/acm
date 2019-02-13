#include "train.h"
#include "a1.cpp"
#include "a4.cpp"

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    for (int it = 1; it <= 100; ++it) {
    srand(it);
    freopen("in", "r", stdin);
	int n, m;
	//assert(2 == scanf("%d %d", &n, &m));
    n = 5, m = 7;

	vector<int> a(n), r(n), u(m), v(m);

	for(int i = 0; i < n; i++)
		a[i] = rand() % 2;
		//assert(1 == scanf("%d", &a[i]));

	for(int i = 0; i < n; i++)
		r[i] = rand() % 2;
		//assert(1 == scanf("%d", &r[i]));

    vector <int> cnt(n);
	for(int i = 0; i < m; i++) {
		u[i] = rand() % n, v[i] = rand() % n;
        ++cnt[u[i]];
    }
    bool ok = 1;
    forn(i, 0, n - 1) if (!cnt[i]) ok = 0;
    if (!ok) continue;
		//assert(2 == scanf("%d %d", &u[i], &v[i]));

    cerr << "test: " << it << "\n";
    for (auto x : a ) cerr << x << " ";cerr << "\n";
    for (auto x : r) cerr << x << " ";cerr << "\n";
    forn(i, 0, m - 1)
        cerr << u[i] << " " << v[i] << "\n";
    cerr << "-\n";
	//vector<int> res = who_wins(a, r, u, v);
    vector <int> s = slow::who_wins(a, r, u, v);
    vector <int> f = fast::who_wins(a, r, u, v);
	cerr << "s: ";for (auto x : s) cerr << x << " ";cerr << "\n";
	cerr << "f: ";for (auto x : f) cerr << x << " ";cerr << "\n";

    assert(f == s);
	for(int i = 0; i < (int)f.size(); i++)
		printf(i ? " %d" : "%d", f[i]);
	printf("\n");
    }
	return 0;
}
