#include "wiring.h"
#include "a2.cpp"

#include <cassert>
#include <cstdio>

using namespace std;

int main() {
    forn(it, 1, 1) {
	cin >> it;
	freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    srand(it);
	int n, m;
	assert(2 == scanf("%d %d", &n, &m));

	vector<int> r(n), b(m);
	for(int i = 0; i < n; i++)
		r[i] = rand();
		//assert(1 == scanf("%d", &r[i]));
	sort(r.begin(), r.end());
    for(int i = 0; i < m; i++)
		b[i] = rand();
		//assert(1 == scanf("%d", &b[i]));

    sort(b.begin(), b.end());
    cerr << "r: ";for (auto x : r) cerr << x<< " ";cerr << "\n";
    cerr << "b: ";for (auto x : b) cerr << x<< " ";cerr << "\n";
	long long res = min_total_length(r, b);

	printf("%lld\n", res);
	assert(res == slow(r, b));
    }
	return 0;
}
